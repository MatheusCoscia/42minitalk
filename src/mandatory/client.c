/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:59:24 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/30 14:52:46 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	send_msg(pid_t pid, char *msg)
{
	u_int8_t	byte;

	while (*msg)
	{
		byte = 0;
		while (byte < 8)
		{
			if (*msg & (128 >> byte))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			byte++;
			usleep(2000);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		how_to_use();
	if (ft_atoi(argv[1]) < 3)
		invalid();
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
