/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:09:28 by alngo             #+#    #+#             */
/*   Updated: 2019/06/03 08:09:53 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int 		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
