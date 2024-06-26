/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:34:37 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/17 17:18:07 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

// void print_test(char **strs)
// {
// 	for (int i = 0; strs[i]; i++)
// 	{
// 		ft_printf("strs[%d] = %s\n", i, strs[i]);
// 	}
// }

static void	run_cmd(t_pipe *data, char *cmd)
{
	char	**full_cmd;
	char	*path;
	int		i;

	full_cmd = ft_split(cmd, ' ');
	// 명령어 경로 찾기
	i = -1;
	while (data->paths[++i])
	{
		path = ft_strjoin(data->paths[i], full_cmd[0]);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	//  ft_printf("path: %s\n", path);
	//  print_test(full_cmd);
	if (execve(path, full_cmd, data->envp) < 0)
		ft_error("Command Not Found");
}

// 자식1 프로세스 : infile을 cmd1의 입력으로 받고 출력 결과를 fds[WRITE]으로 보냄
static void	first_child(t_pipe *data)
{
	ft_printf("First Child Pid: %d\n", getpid());
	if (close(data->fds[READ]) < 0)
		ft_error("Close Error");
	data->infile_fd = open(data->infile, O_RDONLY);
	if (data->infile_fd < 0)
		ft_error(data->infile);
	if (dup2(data->infile_fd, STDIN_FILENO) < 0)
		ft_error("infile dup2 Error");
	if (dup2(data->fds[WRITE], STDOUT_FILENO) < 0)
		ft_error("fds[WRITE] dup 2 Error");
	if (close(data->infile_fd) < 0 || close(data->fds[WRITE]) < 0)
		ft_error("First Child Close Error");
	run_cmd(data, data->cmd1);
}

// 자식2 프로세스 : 입력 부분을 fds[READ]로 받아서 읽고 outfile에 출력 결과 씀
static void	second_child(t_pipe *data)
{
	ft_printf("Second Child Pid: %d\n", getpid());
	if (close(data->fds[WRITE]) < 0)
		ft_error("Close Error");
	data->outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd < 0)
		ft_error(data->outfile);
	if (dup2(data->fds[READ], STDIN_FILENO) < 0)
		ft_error("fds[READ] dup 2 Error");
	if (dup2(data->outfile_fd, STDOUT_FILENO) < 0)
		ft_error("outfile dup2 Error");
	if (close(data->outfile_fd) || close(data->fds[READ]) < 0)
		ft_error("Second Child Close Error");
	run_cmd(data, data->cmd2);
}

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
			second_child(data);
	}
	else
		first_child(data);
	ft_printf("Parent Pid: %d\n", getpid());
	// 부모 프로세스 fd 닫음
	if (close(data->fds[READ]) < 0 || close(data->fds[WRITE]) < 0)
		ft_error("Parent Close Error");
	// 자식 프로세스 종료될 때까지 기다림 
	while (waitpid(-1, &data->status, 0) != -1)
	{
		ft_printf("status: %d\n", WEXITSTATUS(data->status));
	}		
}
