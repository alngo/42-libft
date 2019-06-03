/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:33:14 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 16:20:37 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_strtol(const char *s, char **end, int base)
{
	const char		*sc;
	unsigned long	x;

	sc = s;
	while (ft_isspace(*sc))
		sc++;
	x = ft_stoul(sc, end, base);
	if (*sc == '-' && x <= LONG_MAX)
		return (LONG_MIN);
	else if (*sc != '-' && LONG_MAX < x)
		return (LONG_MAX);
	else
		return ((long)x);
}
