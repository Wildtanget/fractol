/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:46:55 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:23:00 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	test;
// 	test = 'a';
// 	printf("The result of ft_isdigit is: %d\n", ft_isdigit(test));
// 	return (0);
// }

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}
