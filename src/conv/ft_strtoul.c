/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:33:18 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 16:17:25 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_strtoul(const char *s, char **end, int base)
{
	return (ft_stoul(s, end, base));
}
