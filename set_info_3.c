/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:31 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/19 18:07:39 by junhhong         ###   ########.fr       */
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
