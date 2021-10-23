/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:59:24 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/22 20:31:07 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	send_msg(pid_t pid, char *msg)
{
	u_int8_t	byte;

	while(*msg)
	{
		byte = 0;
		while (byte < 8)
		{
			signal(SIGUSR1, sucess);
			if ((*msg & (128 >> byte)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(600);
			byte++;
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
	signal(SIGUSR1, sucess);
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
