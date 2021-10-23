/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:10:30 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/22 21:01:06 by matrodri         ###   ########.fr       */
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

void	sucess(int sig)
{
	(void)sig;
	write(1, "your menssage has been sent\n", 28);
	exit(0);
}

void	get_pid(void)
{
	char *pid;

	pid = ft_itoa(getpid());
	write(2, "server pid: ", 12);
	write(2, pid, ft_strlen(pid));
	write(2, "\n", 1);
}
