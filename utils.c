/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:53:11 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 15:00:47 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	doublearr_free(char **double_arr)
{
	int	i;

	i = 0;
	if (double_arr == NULL)
		return ;
	while (double_arr[i])
	{
        free(double_arr[i]);
		i ++;
	}
	free(double_arr);
}

void	free_all(t_info *info)
{
	close(info->fd);
	if (info->whole_file != NULL)
		doublearr_free(info->whole_file);
	if (info->NO != NULL)
		free(info->NO);
	if (info->SO != NULL)
		free(info->SO);
	if (info->WE != NULL)
		free(info->WE);
	if (info->EA != NULL)
		free(info->EA);
	if (info->F != NULL)
		free(info->F);
	if (info->C != NULL)
		free(info->C);
	if (info->path != NULL)
		free(info->path);
	if (info->map != NULL)
		doublearr_free(info->map);
}
