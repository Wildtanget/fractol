/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:16:56 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:15:08 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
#include <unistd.h>
// #include <stdio.h>
#include "libft.h"
// int main(void)
// {
//     int fd;
//     char *p;
//     fd = open("test.txt", O_WRONLY);
//     p = "Hello world!";
//     ft_putendl_fd(p, fd);
//     printf("Succesfully wrote '%s' to the fd\n", p);
//     close(fd);
//     return (0);
// }

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	int		c;

	i = 0;
	c = '\n';
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &c, 1);
}
