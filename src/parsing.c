/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:46:42 by tamather          #+#    #+#             */
/*   Updated: 2020/02/25 12:01:30 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

int		num_size(char **pos)
{
	int res;

	res = ft_atoi(*pos);
	while (ft_isdigit(*(*pos + 1)))
		(*pos)++;
	return (res);
}

void	parse_flag(char *pos, pf *t, va_list list)
{
	int i;

	i = 0;
	while (*pos)
	{
		if (*pos == '-' )
			(*t).flagn = 1;
		else if (*pos == '0')
			(*t).O_on = 1;
		else if (*pos == '.')
			(*t).p_on = 1;
		else if (*pos == '*' || ft_isdigit(*pos))
			if	((*t).p_on)
				(*t).precision = (*pos == '*' ? va_arg(list, int) : num_size(&pos));
			else if ((*t).O_on && !(*t).p_on)
				(*t).flagO = (*pos == '*' ? va_arg(list, int) : num_size(&pos));
			else
				(*t).width = (*pos == '*' ? va_arg(list, int) : num_size(&pos));
		else if (*pos == '+')
			(*t).flagp = 1;
		else
			break;
		pos++;
	}
	(*t).pos = pos;
}

void	parse_format(char *pos, pf *t)
{
	if (*pos == 'c' || *pos == 's' || *pos == 'p'|| *pos == 'i' || 
		*pos == 'u' || *pos == 'x' || *pos == 'X' || *pos == '%' || *pos == 'd')
		(*t).format = *pos;
	(*t).pos = pos;
}

void	set_zero_stc(pf *t)
{
	(*t).precision = 0;
	(*t).width = 0;
	(*t).p_on = 0;
	(*t).flagO = 0;
	(*t).flagn = 0;
	(*t).flagp = 0;
	(*t).O_on = 0;
	(*t).format = 0;
}

pf		pf_parse_param(char *pos, va_list list)
{
	pf t;

	t.pos = pos;
	set_zero_stc(&t);
	parse_flag(t.pos, &t, list);
	parse_format(t.pos, &t);
	if (t.precision < 0)
	{
		t.p_on = 0;
		t.precision = 0;
	}
	if (t.width < 0)
	{
		t.flagn = 1;
		t.width *= -1;
	}
	if (t.flagO < 0)
	{
		t.width = -1 * t.flagO;
		t.flagn = 1;
		t.flagO = 0;
	}
	return (t);
}