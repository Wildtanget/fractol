/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:10:43 by notahtah          #+#    #+#             */
/*   Updated: 2023/11/02 14:06:34 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_specifier(int c, va_list args);

// Print a character or string
int		ft_print_char(int c);
int		ft_print_string(char *string);
int		ft_print_percent(void);

// Print an (unsigned) integer
int		ft_print_integer(int c);
int		ft_print_unsigned(unsigned int c);

// Print a hexadecimal
int		ft_print_lower_hex(int c);
int		ft_print_upper_hex(int c);
char	*ft_htoa(int n);
void	ft_htoa_helper(unsigned int n, char *s, int length);
int		ft_hex_length(unsigned int n);

// Print pointers
int		ft_print_pointer(unsigned long int ptr);
char	*ft_ptoa(unsigned long int ptr);
int		ft_ptr_length(unsigned long int n);