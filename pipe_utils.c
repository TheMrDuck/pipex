/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:52:43 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/04 17:44:11 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *path_finder(char ** evnp, char *cmd)
{
	int	i;
	char **path;
	char *final_path;

	i = 0;
	while (ft_strncmp(evnp[i], "PATH=", 5))
		i++;
	path = ft_split(evnp[i], ':');
	i = 0;
	while(path)
	{
		final_path = ft_strjoin(path[i], "/");
		final_path = ft_strjoin(path[i], cmd);
		if(access(final_path, X_OK) == 0)
			return final_path;
		i++;
	}
	return NULL;
}
