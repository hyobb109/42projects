/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:34:37 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/14 22:36:26 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	run_cmd(t_pipe *data, char *cmd)
{
	char	**full_cmd;
	char	*path;
	int		i;

	full_cmd = ft_split(cmd, ' ');
	// int execve(const char *pathname, char *const argv[], char *const envp[]);
	// 명령어 경로 찾기
	i = -1;
	while (data->paths[++i])
	{
		path = ft_strjoin(data->paths[i], full_cmd[0]);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	// ft_printf("path: %s\n", path);
	if (execve(path, full_cmd, data->envp) < 0)
		ft_error(ft_strjoin("pipex: ", cmd));
}

// 자식1 프로세스 : infile을 cmd1의 입력으로 받고 출력 결과를 fd[WRITE]으로 보냄
static void	first_child(t_pipe *data)
{
	if (close(data->fds[READ]) < 0)
		ft_error("Close Error");
	// file1 없을 때?
	// if (data->infile != -1)
	if (dup2(data->infile, STDIN_FILENO) < 0)
		ft_error("Fd1 dup2 Error");
	if (dup2(data->fds[WRITE], STDOUT_FILENO) < 0)
		ft_error("fd[WRITE] dup 2 Error");
	if (close(data->infile) < 0 || close(data->fds[WRITE]) < 0)
		ft_error("Close Error");
	run_cmd(data, data->cmd1);
}

// 자식2 프로세스 : 입력 부분을 fd[READ]로 받아서 읽고 outfile에 출력 결과 씀
static void	second_child(t_pipe *data)
{
	if (close(data->fds[WRITE]) < 0)
		ft_error("Close Error");
	if (dup2(data->fds[READ], STDIN_FILENO) < 0)
		ft_error("fd[READ] dup 2 Error");
	if (dup2(data->outfile, STDOUT_FILENO) < 0)
		ft_error("outfile dup2 Error");
	if (close(data->outfile) || close(data->fds[READ]) < 0)
		ft_error("Close Error");
	run_cmd(data, data->cmd2);
}

// 고칠 것!! -> pipe + fork 2번씩
void	do_pipe(t_pipe *data)
{
	pid_t	pid;

	// pipe 생성
	if (pipe(data->fds) < 0)
		ft_error("Pipe Error");
	// 프로세스 복사
	pid = fork();
	if (pid < 0)
		ft_error("Fork Error");
	// 	부모 프로세스는 자식 프로세스 id 가짐
	if (pid)
	{
		// 병렬로 자식 생성
		pid = fork();
		if (pid < 0)
			ft_error("Fork Error");
		if (pid == 0)
			first_child(data);
	}
	else
		second_child(data);
	// 자식 프로세스 종료될 때까지 기다림 
	while (waitpid(-1, &data->wstatus, 0) != -1)
	{
		ft_printf("status: %d\n", data->wstatus);
	}		
}
