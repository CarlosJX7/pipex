/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <cinaquiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:37:45 by cainaqui          #+#    #+#             */
/*   Updated: 2022/09/07 14:40:33 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;
	size_t	size;

	if (big == NULL && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (big_len < little_len || len < little_len)
		return (0);
	if (big_len > len)
		size = len;
	else
		size = big_len;
	while (size-- >= little_len)
	{
		if (ft_memcmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
