/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check_block.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:20:34 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 15:53:51 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_1_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i ++;
	}
	return (0);
}

int	top_bottom_check(t_info *info)
{
	char	*top;
	char	*bottom;

	if (info->num_map_lines < 2)
	{
		ft_putstr_fd("len_map < 2\n", 2);
		return (1);
	}
	top = info->map[0];
	bottom = info->map[info->num_map_lines - 1];
	if (all_1_space(top))
		return (1);
	if (all_1_space(bottom))
		return (1);
	return (0);
}

int	side_check(t_info *info)
{
	int	i;
	int	last;
	int	k;

	i = 0;
	while (info->map[i])
	{
		k = 0;
		last = ft_strlen(info->map[i]);
		if (last <= 0)
			return (1);
		while (info->map[i][k] == ' ')
			k ++;
		if (info->map[i][k] && (info->map[i][k] != '1' || info->map[i][last - 1] != '1'))
			return (1);
		i ++;
	}
	return (0);
}

int is_blocked(t_info *info)
{
	if (top_bottom_check(info))
	{
		ft_putstr_fd("Error:Bottom or Top in map\n", 2);
		return (1);
	}
	if (side_check(info))
	{
		ft_putstr_fd("Error:side in map\n", 2);
		return (1);
	}
	return (0);
}