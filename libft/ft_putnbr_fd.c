/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cainaqui <cainaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:00:46 by cainaqui          #+#    #+#             */
/*   Updated: 2022/09/01 17:02:05 by cainaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar(56, fd);
	}
	else if (nb < 0)
	{
		ft_putchar(45, fd);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		if (nb > 9)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar(48 + nb % 10, fd);
	}
}
