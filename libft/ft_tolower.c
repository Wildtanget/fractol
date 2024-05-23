/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:22:42 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:30:01 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	test;
// 	test = 'F';
// 	printf("The result of ft_tolower is: %c\n", ft_tolower(test));
// 	return (0);
// }

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}
