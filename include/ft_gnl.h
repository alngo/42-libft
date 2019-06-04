/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:05:05 by alngo             #+#    #+#             */
/*   Updated: 2019/06/04 13:21:31 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#define BUFF_SIZE 42

typedef struct				s_gnl
{
  int						      fd;
  char					      *str;
}							        t_gnl;

int							      ft_gnl(int fd, char **line);

#endif

