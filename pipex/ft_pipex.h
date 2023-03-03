/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:49:12 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/03 19:57:43 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

#include "./libft/libft.h"
#include <fcntl.h>

typedef enum e_type
{
	READ,
	WRITE
}	t_type;

typedef	struct s_pipe
{
	int		fd[2];
	int		fd1;
	int		fd2;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	char	**paths;
}	t_pipe;

#endif