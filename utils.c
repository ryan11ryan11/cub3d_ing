/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:53:11 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/26 17:24:51 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	doublearr_free(char **double_arr)
{
	int	i;

	i = 0;
	while(double_arr[i])
	{
        free(double_arr[i]);
		i ++;
	}
	free(double_arr);
}

void	free_all(t_info *info)
{
	close(info->fd);
	if (info->whole_file)
		doublearr_free(info->whole_file);
	if (info->NO)
		free(info->NO);
	if (info->SO)
		free(info->SO);
	if (info->WE)
		free(info->WE);
	if (info->EA)
		free(info->EA);
	if (info->F)
		free(info->F);
	if (info->C)
		free(info->SO);
}
