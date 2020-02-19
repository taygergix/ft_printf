/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:27:21 by tamather          #+#    #+#             */
/*   Updated: 2020/02/19 06:01:48 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct pf
{
	char *pos;
	int flagn;
	int flagO;
	int size;
	int width;
	int precision[2];
	char format;
	
} pf;


int		ft_printf(const char *arg, ...);
int		pf_print(char *arg, va_list list);
char	*pf_check_param(char *pos, va_list list);

//parsing function

pf      pf_parse_param(char *pos, va_list list);

//display function

int		pf_formater(pf t, va_list list);
void	ft_putstr_w_fd(char *s, int size, int fd);

#endif