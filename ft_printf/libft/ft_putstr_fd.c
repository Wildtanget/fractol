/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:17:03 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:14:56 by notahtah         ###   ########.fr       */
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
//     ft_putstr_fd(p, fd);
//     printf("Succesfully wrote '%s' to the fd\n", p);
//     close(fd);
//     return (0);
// }

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
}
