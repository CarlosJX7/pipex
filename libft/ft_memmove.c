/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:16:19 by cainaqui          #+#    #+#             */
/*   Updated: 2022/08/25 20:17:17 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		mem_dest = (unsigned char *)dest;
		mem_src = (unsigned char *)src;
		while (n--)
			*mem_dest++ = *mem_src++;
	}
	else
	{
		mem_dest = (unsigned char *)dest + (n - 1);
		mem_src = (unsigned char *)src + (n - 1);
		while (n--)
			*mem_dest-- = *mem_src--;
	}
	return (dest);
}
