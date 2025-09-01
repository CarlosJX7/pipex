/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:26:31 by cainaqui          #+#    #+#             */
/*   Updated: 2022/09/01 17:26:47 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cadena;
	size_t	inicio;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	inicio = ft_strlen(s + start);
	if (inicio < len)
		len = inicio;
	cadena = (char *)malloc(sizeof(char) * (len + 1));
	if (!cadena)
		return (NULL);
	ft_strlcpy(cadena, s + start, len + 1);
	return (cadena);
}
