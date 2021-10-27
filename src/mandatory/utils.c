/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:10:30 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/26 21:16:19 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	how_to_use(void)
{
	write(2, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	invalid(void)
{
	write(2, "wrong server_pid\n", 17);
	exit(0);
}

void	get_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(2, "server pid: ", 12);
	write(2, pid, ft_strlen(pid));
	write(2, "\n", 1);
}
