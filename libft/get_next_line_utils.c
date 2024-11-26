/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:00:21 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/25 16:12:12 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	if (!dest_ptr && !src_ptr)
		return (dest);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i ++ ;
	}
	return (dest);
}
