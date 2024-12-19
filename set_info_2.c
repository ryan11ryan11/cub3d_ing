/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:52:35 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/19 17:36:18 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_linechange(char *line)
{
	int		i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\0')
	{
		result[i] = line[i];
		i ++;
	}
	result[i] = '\0';
	return (result);
}

char	*return_value(t_info *info, char *target)
{
	int		len;
	char	**double_arr;
	char	*value;

	double_arr = info->whole_file;
	len = ft_strlen(target);
	while (*double_arr != NULL)
	{
		if (ft_strncmp(*double_arr, target, len) == 0)
			break;
		double_arr++;
	}
	if (*double_arr == NULL)
	{
		ft_putstr_fd(target, 2);
		ft_putstr_fd(" Does not exist\n", 2);
		return (NULL);
	}
	value = *double_arr;
	value = value + len;
	while (*value == ' ')
		value ++;
	return (value);
}

void	set_all_NULL(t_info *info)
{
	info->num_lines = 0;
	info->num_map_lines = 0;
	info->path = NULL;
	info->map = NULL;
	info->whole_file = NULL;
	info->NO = NULL;
	info->SO = NULL;
	info->WE = NULL;
	info->EA = NULL;
	info->F = NULL;
	info->C = NULL;
	info->pos_x = -1;
	info->pos_y = -1;
}

int	set_value(t_info *info)
{
	if (return_value(info, "NO"))
		info->NO = ft_strdup(return_value(info, "NO"));
	if (return_value(info, "SO"))
		info->SO = ft_strdup(return_value(info, "SO"));
	if (return_value(info, "WE"))
		info->WE = ft_strdup(return_value(info, "WE"));
	if (return_value(info, "EA"))
		info->EA = ft_strdup(return_value(info, "EA"));
	if (return_value(info, "F"))
		info->F = ft_strdup(return_value(info, "F"));
	if (return_value(info, "C"))
		info->C = ft_strdup(return_value(info, "C"));
	if (!info->NO || !info->SO || !info->WE || !info->EA || !info->F || !info->C)
	{
		ft_putendl_fd("Missing info. check cubfile. please do not harass my program", 2);
		return (1);
	}
	return (0);
}

int	set_mlx(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
	{
		ft_putstr_fd("mlx_init failed\n", 2);
		return (1);
	}
	info->win = mlx_new_window(info->mlx, 1000, 1000, "mlx_project");
	if (!info->win)
	{
		ft_putstr_fd("mlx_new_window failed\n", 2);
		free(info->mlx);
		return (1);
	}
	return (0);
}