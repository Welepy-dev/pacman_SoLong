/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:23:00 by  marcsilv         #+#    #+#             */
/*   Updated: 2024/09/15 21:36:39 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <limits.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "../libft.h"
# include "../../so_long.h"

int		upper(unsigned int decimalNumber);
int		lower(unsigned int decimalNumber);
int		find_specifier(char myString, va_list args);
int		ft_printf(const char *myString, ...);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_num_len(unsigned int num);
int		ft_ptr_len(uintptr_t num);

char	*ft_uitoa(unsigned int n);

void	ft_put_ptr(uintptr_t num);

#endif
