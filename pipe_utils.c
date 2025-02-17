/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:52:43 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/17 17:16:49 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*path_finder(char **evnp, char *cmd)
{
	int		i;
	char	**path;
	char	*final_path;
	char	*temp;

	i = 0;
	while (ft_strncmp(evnp[i], "PATH=", 5))
		i++;
	path = ft_split(evnp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		final_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(final_path, X_OK) == 0)
		{
			free_2d(path);
			return (final_path);
		}
		i++;
		free(final_path);
	}
	free_2d(path);
	return (NULL);
}
