/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:06 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/26 17:32:55 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extension_check(const char *path)
{
	const char	*tmp;

	tmp = ft_strrchr(path, '.');
	if (!tmp || ft_strcmp(tmp, ".cup") != 0)
		return (1);
	return (0);
}

int	get_map_line(int fd)
{
	char	*map_line;
	int		i;

	i = 0;
	map_line = get_next_line(fd);
	while (map_line)
	{
		if (map_line[0] && map_line[0] == 'C')
		{
			free(map_line);
			return (i + 1);
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (-1);
}

int	is_news(char *line)
{
	int	i;
	const char *compare = "10NEWS \n";

	i = 0;
	while (line[i])
	{
		if (ft_strchr(compare, line[i]) != 0)
		{
			ft_putendl_fd("Bad component in the map. only NEWS01 is allowed\n", 2);
			return (1);
		}
		i ++;
	}
	return (0);
}

int	component_check(int line_index, int fd)
{
	char	*line;

	line = get_next_line(fd);
	line_index --;
	while((line && line[0] == '\n') || line_index > 0)
	{
		free(line);
		line = get_next_line(fd);
		line_index --;
	}
	while (line)
	{
		if (is_news(line) == 1)
		{
			free(line);
			return (1);
		}
		line = get_next_line(fd);
	}
	return (0);
}

int	map_component_check(char *path)
{
	int	line_index;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return (1);
	}
	line_index = get_map_line(fd);
	if (line_index == -1)
	{
		ft_putendl_fd("Failed to read map\n", 2);
		return (1);
	}
	if (component_check(line_index, fd) == 1)
		return (1);
	close(fd);
	return (0);
}

int	validity_check(t_info *info)
{
	(void) info;
	if (extension_check(info->path) == 1)
	{
		ft_putendl_fd("Error: Invalid extension\n", 2);
		return (1);
	}
	if (map_component_check(info->path) == 1)
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	if (argc != 2)
	{
		ft_putendl_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	if (set_info(&info, argv[1]) == 1)
	{
		free_all(&info);
		return (1);
	}
	print_status(&info);
	if (validity_check(&info) == 1)
		return (1);
	free_all(&info);
	return (0);
}
