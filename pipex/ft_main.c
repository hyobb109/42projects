/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:48:05 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:10 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"


void print_test(char **strs)
{
	for (int i = 0; strs[i]; i++)
	{
		ft_printf("strs[%d] = %s\n", i, strs[i]);
	}
}
/*
void leak()
{
	system("leaks pipex");
}
*/

static void	get_paths(t_pipe *data)
{
	int		i;

	i = -1;
	while (data->envp[++i])
	{
		if (ft_strncmp(data->envp[i], "PATH", 4) == 0)
			data->paths = ft_split(data->envp[i], ':');
	}
	data->paths[0] = ft_strdup(data->paths[0] + 5);
	i = -1;
	while (data->paths[++i])
		data->paths[i] = ft_strjoin(data->paths[i], "/");
}

static void	init_pipe_data(t_pipe *data, char **argv, char **envp)
{
	data->wstatus = 0;
	data->fd1 = open(argv[1], O_RDONLY);
	if (data->fd1 < 0)
		perror(ft_strjoin("pipex: ", argv[1]));
	data->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd2 < 0)
		perror(ft_strjoin("pipex: ", argv[4]));
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->envp = envp;
	get_paths(data);
	// print_test(data->paths);
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
	free_strs(data.paths);
	return (data.wstatus);
}
