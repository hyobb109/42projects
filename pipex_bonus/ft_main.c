/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:48:05 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/17 16:19:43 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

// void leak()
// {
// 	system("leaks pipex");
// }

static int	count_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static void	get_paths(t_pipe *data)
{
	int		i;
	int		cnt;
	char	**tmp;

	i = -1;
	while (data->envp[++i])
	{
		if (ft_strncmp(data->envp[i], "PATH", 4) == 0)
			tmp = ft_split(data->envp[i] + 5, ':');
	}
	// print_test(tmp);
	cnt = count_strs(tmp);
	data->paths = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (data->paths == 0)
		ft_error("malloc error");
	i = -1;
	while (++i < cnt)
		data->paths[i] = ft_strjoin(tmp[i], "/");
	data->paths[i] = 0;
	free_strs(tmp);
}

static void	init_pipe_data(t_pipe *data, int argc, char **argv, char **envp)
{
	data->status = 0;
	data->infile = argv[1];
	data->cmds = malloc(sizeof(char *) * (argc - 2));
	for (int i = 2; i < argc - 2; i++) {
		data->cmds[i - 2] = ft_strdup(argv[i]);
	}
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->outfile = argv[argc - 1];
	data->envp = envp;
	get_paths(data);
	// print_test(data->paths);
}

// < infile "cmd1" | "cmd2" > outfile
int	main(int argc, char **argv, char **envp)
{
	t_pipe	data;

	// atexit(leak);
	// if (argc != 5)
	// 	ft_error("Invalid Parameters");
	// argv[1] infile path
	// print_test(envp);
	init_pipe_data(&data, argc, argv, envp);
	do_pipe(&data);
	free_strs(data.paths);
	return (WEXITSTATUS(data.status));
}
