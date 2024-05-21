/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:23:28 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:27:17 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	if (dst == NULL && src == NULL)
		return (NULL);
	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (destination < source || destination >= source + n)
		while (n--)
			*destination++ = *source++;
	else
	{
		destination += n - 1;
		source += n - 1;
		while (n--)
			*destination-- = *source--;
	}
	return (dst);
}
