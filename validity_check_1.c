/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:45 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 16:11:54 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extension_check(const char *path)
{
	const char	*tmp;

	tmp = ft_strrchr(path, '.');
	if (!tmp || ft_strcmp(tmp, ".cub") != 0)
	{
		ft_putstr_fd("Invalid file extension\n", 2);
		return (1);
	}
	return (0);
}

int	is_news(char *line)
{
	int	i;
	const char *compare = "10NEWS \n";

	i = 0;
	while (line[i])
	{
		if (ft_strchr(compare, line[i]) == NULL)
		{
			ft_putendl_fd("Bad component in the map. only NEWS01 is allowed\n", 2);
			return (1);
		}
		i ++;
	}
	return (0);
}

int	only_news(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if (is_news(info->map[i]) == 1)
			return (1);
		i ++;
	}
	return (0);
}

int	validity_check(t_info *info)
{
	(void) info;
	if (extension_check(info->path) == 1)
		return (1);
	if (only_news(info) == 1)
		return (1);
	if (is_blocked(info) == 1)
		return (1);
	return (0);
}