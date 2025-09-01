/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:14:49 by cainaqui          #+#    #+#             */
/*   Updated: 2022/08/25 20:15:16 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
