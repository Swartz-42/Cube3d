/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:28:44 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 16:43:33 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(unsigned int nbr, int fd)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		write(fd, &c, 1);
		return ;
	}
	ft_putnbr(nbr / 10, fd);
	ft_putnbr(nbr % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned	nbr;

	if (n < 0)
		write(fd, "-", 1);
	nbr = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	ft_putnbr(nbr, fd);
}
