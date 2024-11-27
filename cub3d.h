/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:15:01 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 15:33:32 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_info
{
	int		fd;
	int		num_lines;
	int		num_map_lines;
	char	*path;
	char	**whole_file;
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
} t_info;

void	doublearr_free(char **double_arr);
void	free_all(t_info *info);

/*set_info1*/
int		set_info(t_info *info, char *path);
int		set_path(t_info *info, char *path);
int		set_fd(t_info *info);
int		set_num_lines(t_info *info);
int		set_whole_file(t_info *info);

/*set_info2*/
char	*remove_linechange(char *line);
char	*return_value(t_info *info, char *target);
int		set_value(t_info *info);
int		set_map(t_info *info);
void	set_all_NULL(t_info *info);


/*cubfile_check*/
int components_counter(t_info *info, char *target);
int duplicate_check(t_info *info);
int cubfile_check(t_info *info);

/*validity_check_1*/
int	extension_check(const char *path);
int	is_news(char *line);
int	only_news(t_info *info);
int	validity_check(t_info *info);

/*validity_check_block*/
int is_blocked(t_info *info);
int	top_bottom_check(t_info *info);
int	all_1_space(char *line);

/* to be deleted befor submit */
void print_status(t_info *info);