/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:17:48 by cainaqui          #+#    #+#             */
/*   Updated: 2022/08/25 20:18:52 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *old)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(old) + 1);
	if (new == NULL)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
