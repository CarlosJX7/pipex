/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:12:28 by cainaqui          #+#    #+#             */
/*   Updated: 2022/09/02 18:37:12 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*cadena;

	if (s == 0 || f == 0)
		return (NULL);
	cadena = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (cadena == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cadena[i] = f(i, s[i]);
		i++;
	}
	cadena[i] = '\0';
	return (cadena);
}
