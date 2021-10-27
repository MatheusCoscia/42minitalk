/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:55:42 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/26 21:19:36 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>

/*
**	UTILS
*/
void	invalid(void);
void	how_to_use(void);
void	get_pid(void);

/*
**	MINI_LIBFT
*/
int		ft_atoi(const char *str);
void	*ft_calloc(size_t memb, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
