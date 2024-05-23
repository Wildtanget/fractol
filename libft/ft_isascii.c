/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:07:51 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:22:54 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	int	test;
// 	test = 128;
// 	printf("The result of ft_isascii is: %d\n", ft_isascii(test));
// 	return (0);
// }

int	ft_isascii(int arg)
{
	if (arg >= 0 && arg <= 127)
		return (1);
	else
		return (0);
}
