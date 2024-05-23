/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:30:13 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:22:48 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	test;
// 	test = 'a';
// 	printf("The result of ft_isalpha is: %d\n", ft_isalpha(test));
// }

int	ft_isalpha(int arg)
{
	if ((arg >= 'A' && arg <= 'Z') || (arg >= 'a' && arg <= 'z'))
		return (1);
	else
		return (0);
}
