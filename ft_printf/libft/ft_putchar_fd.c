/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:16:51 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:15:15 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>
#include "libft.h"
// int main(void)
// {
//     int fd;
//     char p;
//     fd = open("test.txt", O_WRONLY);
//     p = 'p';
//     write(fd, &p, 1);
//     write(fd, &p, 1);
//     close(fd);
//     return (0);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
