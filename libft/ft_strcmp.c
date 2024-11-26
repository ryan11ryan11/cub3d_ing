/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1s2_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:08 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/25 15:28:43 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++ ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
