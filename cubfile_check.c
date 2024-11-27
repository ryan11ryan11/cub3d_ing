/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:02:32 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 14:26:53 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cubfile_check(t_info *info)
{
	if (duplicate_check(info))
	{
		ft_putstr_fd("Component number error. check cubfile\n", 2);
		return (1);
	}
	return (0);
}

int duplicate_check(t_info *info)
{
	if (components_counter(info, "NO") != 1)
		return (1);
	if (components_counter(info, "SO") != 1)
		return (1);
	if (components_counter(info, "WE") != 1)
		return (1);
	if (components_counter(info, "EA") != 1)
		return (1);
	if (components_counter(info, "F") != 1)
		return (1);
	if (components_counter(info, "C") != 1)
		return (1);
	return (0);
}

int components_counter(t_info *info, char *target) // problem
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (info->whole_file[i])
	{
		if (strncmp(info->whole_file[i], target, ft_strlen(target)) == 0)
			count ++;
		i ++;
	}
	return (count);
}