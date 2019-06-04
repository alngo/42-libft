/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:06:46 by alngo             #+#    #+#             */
/*   Updated: 2019/06/04 13:39:28 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_gnl(const int fd, char **line)
{
  static t_list *lst;
  t_gnl         gnl;

  gnl.fd = fd;
  (void)line;

  lst = ft_lstnew((void *)&gnl, sizeof(t_gnl));

  return (0);
}
