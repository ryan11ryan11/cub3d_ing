/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:06 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/19 14:04:17 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// //cc test.c -L minilibx-linux -lmlx_Linux -lX11 -lXext   

#include "cub3d.h"

int	finish_program(t_info *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	free_all(info);
	exit (0);
}

int	key_press(int key, t_info *info)
{
	(void) info;
	if (key == KEY_W)
		printf("W pressed\n");
	if (key == KEY_S)
		printf("S pressed\n");
	if (key == KEY_A)
		printf("A pressed\n");
	if (key == KEY_D)
		printf("S pressed\n");
	if (key == KEY_LEFT)
		printf("LEFT pressed\n");
	if (key == KEY_RIGHT)
		printf("RIGHT pressed\n");
	if (key == KEY_ESC)
		finish_program(info);
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
	if (set_info(&info, argv[1]) == 1 || validity_check(&info) == 1)
	{
		free_all(&info);
		return (1);
	}
	print_status(&info);
	mlx_hook(info.win, X_CLICK, 0, &finish_program, &info);
	mlx_hook(info.win, KEY_PRESS, 1L<<0, &key_press, &info);
	mlx_loop(info.mlx);
	free_all(&info);
	return (0);
}
