/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:41:40 by junhhong          #+#    #+#             */
/*   Updated: 2023/12/18 12:48:52 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		c = c + 32;
	return (c);
}

// int main()
// {
// 	int	i;

// 	i = 5;
// 	while(i <= 150)
// 	{
// 		printf("%c :: %c\n",i,ft_tolower(i));
// 		i ++ ;
// 	}
// }