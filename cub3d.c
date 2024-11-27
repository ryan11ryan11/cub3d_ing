/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:06 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 16:28:02 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	{
		free_all(&info);
		return (1);
	}
	free_all(&info);
	return (0);
}
