/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:48:05 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/03 19:58:29 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*
void print_test(char **strs)
{
	for (int i = 0; strs[i]; i++)
	{
		ft_printf("strs[%d] = %s\n", i, strs[i]);
	}
}
*/

void	run_cmd(t_pipe *data, char *cmd)
{
	char	**full_cmd;
	char	*path;
	int		i;

	full_cmd = ft_split(cmd, ' ');
	// int execve(const char *pathname, char *const argv[], char *const envp[]);
	// 명령어 경로 찾기
	i = 0;
	while (data->paths[++i])
	{
		path = ft_strjoin(data->paths[i], full_cmd[0]);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	// ft_printf("path: %s\n", path);
	if (execve(path, full_cmd, data->envp) < 0)
		ft_error("Run Error");
	free(path);
}

void	do_pipe(t_pipe *data)
{
	pid_t	pid;

	// pipe 생성
	if (pipe(data->fd) < 0)
		ft_error("Pipe Error");
	// 프로세스 복사
	pid = fork();
	if (pid < 0)
		ft_error("Fork Error");
	// 	부모 프로세스는 자식 프로세스 id 가짐
	if (pid)
	{
		// 읽는 부분 닫음
		close(data->fd[READ]);
		// ft_printf("*Parent, fd: %d\n", data->fd[0]);
		// ft_printf("*fd1: %d\n", data->fd1);
		// 표준입력이 fd1 가리키고 출력은 쓰는 곳에
		if (dup2(data->fd1, STDIN_FILENO) < 0 || dup2(data->fd[WRITE], STDOUT_FILENO) < 0)
			ft_error("Parent dup2 Error");
		close(data->fd1);
		close(data->fd[WRITE]);
		run_cmd(data, data->cmd1);
	}
	// 자식 프로세스 0 반환
	else
	{
		// 자식 프로세스는 쓰는 부분 닫음
		close(data->fd[WRITE]);
		//ft_printf("*Child, fd: %d\n", data->fd[1]);
		//ft_printf("*fd2: %d\n", data->fd2);
		if (dup2(data->fd2, STDOUT_FILENO) < 0 || dup2(data->fd[READ], STDIN_FILENO) < 0)
			ft_error("Child dup2 Error");
		close(data->fd2);
		close(data->fd[READ]);
		run_cmd(data, data->cmd2);
	}
}

char **get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			paths = ft_split(envp[i], ':');
	}
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (paths);
}

void	init_pipe_data(t_pipe *data, char **argv, char **envp)
{
	data->fd1= open(argv[1], O_RDONLY);
	if (data->fd1 < 0)
		ft_error("FILE1 Open Error");
	data->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (data->fd2 < 0)
		ft_error("FILE2 Open Error");
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->envp = envp;
	data->paths = get_paths(envp);
}

// < infile "cmd1" | "cmd2" > outfile
int	main(int argc, char **argv, char **envp)
{
	t_pipe	data;

	if (argc != 5)
		ft_error("Invalid Parameters");
	// argv[1] infile path
	init_pipe_data(&data, argv, envp);
	do_pipe(&data);
	return (0);
}
