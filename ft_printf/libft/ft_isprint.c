/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:21:40 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:23:05 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	int	test;
// 	test = 32;
// 	printf("The result of ft_isprint is: %d\n", ft_isprint(test));
// 	return (0);
// }

int	ft_isprint(int arg)
{
	if (arg > 31 && arg < 127)
		return (1);
	else
		return (0);
}
