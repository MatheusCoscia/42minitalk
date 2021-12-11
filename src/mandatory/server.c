/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:15:05 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/27 14:32:02 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	send_msg(int sig)
{
	static int	str;
	static int	byte;

	if (byte == 0)
		byte = 128;
	if (sig == SIGUSR1)
		str += byte;
	byte /= 2;
	if (byte == 0)
	{
		write(1, &str, 1);
		str = 0;
	}
}

int	main(void)
{
	get_pid();
	signal(SIGUSR1, send_msg);
	signal(SIGUSR2, send_msg);
	while (1)
		pause();
	return (0);
}
