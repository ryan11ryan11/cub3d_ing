/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:48:42 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 16:12:02 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_info(t_info *info, char *path)
{
	set_all_NULL(info);
	if (set_path(info, path))
		return (1);
	if (set_fd(info))
		return (1);
	if (set_num_lines(info))
		return (1);
	if (set_whole_file(info))
		return (1);
	if (cubfile_check(info))
		return (1);
	if (set_value(info))
		return (1);
	if (set_map(info))
		return (1);
	return (0);
}

int	set_path(t_info *info, char *path)
{
	info->path = ft_strdup(path);
	if (!info->path)
		return (1);
	return (0);
}

int	set_fd(t_info *info)
{
	info->fd = open(info->path, O_RDONLY);
	if (info->fd == -1)
	{
		perror("Cannot read file. fd is -1");
		return (1);
	}
	return (0);
}

int	set_num_lines(t_info *info)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(info->path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line != NULL && strcmp(line, "\n") == 0)
		{
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		line = get_next_line(fd);
		i ++;
	}
	info->num_lines = i;
	return (0);
}

int	set_whole_file(t_info *info)
{
	char	*line;
	int		i;

	i = 0;
	info->whole_file = (char **)malloc(sizeof(char *) * (info->num_lines + 1));
	line = get_next_line(info->fd);
	while(line != NULL)
	{
		while (line != NULL && strcmp(line, "\n") == 0)
		{
			free (line);
			line = get_next_line(info->fd);
		}
		if (line == NULL)
			break ;
		info->whole_file[i] = remove_linechange(line);
		i ++;
		free (line);
		line = get_next_line(info->fd);
	}
	info->whole_file[info->num_lines] = NULL;
	free (line);
	return (0);
}
