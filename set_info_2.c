/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:52:35 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/26 17:35:24 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_linechange(char *line)
{
	int		i;
	char	*result;

	result = (char *)malloc(sizeof(char) * ft_strlen(line));
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
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
	while (ft_strncmp(*double_arr, target, len) != 0)
		double_arr ++;
	value = *double_arr;
	value = value + len;
	while (*value == ' ')
		value ++;
	return (value);
}

int	set_value(t_info *info)
{
	info->NO = ft_strdup(return_value(info, "NO"));
	info->SO = ft_strdup(return_value(info, "SO"));
	info->WE = ft_strdup(return_value(info, "WE"));
	info->EA = ft_strdup(return_value(info, "EA"));
	info->F = ft_strdup(return_value(info, "F"));
	info->C = ft_strdup(return_value(info, "C"));
	if (!info->NO || !info->SO || !info->WE || !info->EA || !info->F || !info->C)
	{
		ft_putendl_fd("Missing info. check cupfile and please do not harras ", 2);
		return (1);
	}
	return (0);
}
