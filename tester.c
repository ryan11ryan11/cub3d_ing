/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:32:48 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 14:28:29 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_status(t_info *info)
{
    int p = 0;
	printf("************************************************************\n");
	printf("\nwhole file\n");
	while(info->whole_file[p])
	{
		printf("%s\n", info->whole_file[p]);
		p++;
	}
	printf("\nothers\n");
	printf("info->NO::%s\n",info->NO);
	printf("info->SO::%s\n",info->SO);
	printf("info->WE::%s\n",info->WE);
	printf("info->EA::%s\n",info->EA);
	printf("info->F::%s\n",info->F);
	printf("info->C::%s\n",info->C);
	printf("info->path::%s\n",info->path);
	printf("info->num_lines::%d\n",info->num_lines);

	printf("\nmap\n");
	int k = 0;
	while (info->map[k])
	{
		printf("%s\n",info->map[k]);
		k ++;
	}
	printf("************************************************************\n");
}