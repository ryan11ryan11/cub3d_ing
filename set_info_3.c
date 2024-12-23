/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:31 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/20 16:49:12 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_pos(t_info *info)
{
	int 	i;
	int		j;
	char	*compare = "NEWS";

	i = 0;
	j = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			if (ft_strchr(compare, info->map[i][j]))
			{
				info->pos_y = info->num_map_lines - i - 1;
				info->pos_x = j;
				info->direction[0] = info->map[i][j];
				return (0);
			}
			j ++;
		}
		j = 0;
		i ++;
	}
	ft_putstr_fd("NEWS does not exist\n", 2);
	return (1);
}

void	set_dir_xy(t_info *info, int dir_x, int dir_y)
{
	info->dir_x = dir_x;
	info->dir_y = dir_y;
}

int	set_dir(t_info *info)
{
	if (info->direction[0] == 'N')
	{
		set_dir_xy(info, 0, 1);
		return (0);
	}
	if (info->direction[0] == 'E')
	{
		set_dir_xy(info, 1, 0);
		return (0);
	}
	if (info->direction[0] == 'W')
	{
		set_dir_xy(info, -1, 0);
		return (0);
	}
	if (info->direction[0] == 'S')
	{
		set_dir_xy(info, 0, -1);
		return (0);
	}
	ft_putstr_fd("Invalid direction\n", 2);
	return (1);
}

void	set_plane_xy(t_info *info, double x, double y)
{
	info->plane_x = x;
	info->plane_y = y;
}

int	set_plane(t_info *info)
{
	if (info->dir_x == -1 && info->dir_y == 0)
	{
		set_plane_xy(info, 0, 0.66);
		return (0);
	}
	if (info->dir_x == 1 && info->dir_y == 0)
	{
		set_plane_xy(info, 0, -0.66);
		return (0);
	}
	if (info->dir_x == 0 && info->dir_y == 1)
	{
		set_plane_xy(info, 0.66, 0);
		return (0);
	}
	if (info->dir_x == 0 && info->dir_y == -1)
	{
		set_plane_xy(info, -0.66, 0);
		return (0);
	}
	ft_putstr_fd("Error setting plane\n", 2);
	return (1);
}
