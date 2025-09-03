/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:11:12 by cainaqui          #+#    #+#             */
/*   Updated: 2022/09/01 19:03:21 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cadena;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1))
		return (ft_strdup(s2));
	else if (!(s2))
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cadena = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!cadena)
		return (NULL);
	ft_strlcpy(cadena, s1, s1_len + 1);
	ft_strlcat(cadena + (s1_len), s2, s2_len + 1);
	return (cadena);
}
