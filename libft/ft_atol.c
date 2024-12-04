/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:34:47 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/19 16:41:42 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_int(const char *pstr, int i);

long long	ft_atol(const char *str) // char to int convertor
{
	int			i;
	int			sign;
	long long	num;
	const char	*pstr;

	i = 0;
	num = 0;
	sign = 1;
	pstr = (const char *)str;
	i = find_int(pstr, i);
	if (pstr[i] != '\0' && pstr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (pstr[i] == '+')
		i++;
	while (pstr[i] != '\0' && pstr[i] >= '0' && pstr[i] <= '9')
	{
		num = num * 10 + (pstr[i] - '0');
		i++;
	}
	return (num * sign);
}

static int	find_int(const char *pstr, int i)
{
	while (pstr[i] != '\0' && (pstr[i] == ' ' || pstr[i] == '\t'
			|| pstr[i] == '\n' || pstr[i] == '\r' || pstr[i] == '\v'
			|| pstr[i] == '\f'))
		i++;
	return (i);
}
