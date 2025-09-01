/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:35:49 by cainaqui          #+#    #+#             */
/*   Updated: 2022/09/01 16:50:26 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*c1;
	unsigned char		*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (c1[i] != c2[i] || c1[i] == 0 || c2[i] == 0)
			return (c1[i] - c2[i]);
		i++;
		n--;
	}
	return (0);
}
