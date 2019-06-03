/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:43:56 by alngo             #+#    #+#             */
/*   Updated: 2019/06/02 15:44:17 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(const char *s, size_t start, size_t n)
{
	char		*tmp;

	if (!(tmp = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strncpy(tmp, &s[start], n);
	tmp[n] = '\0';
	return (tmp);
}
