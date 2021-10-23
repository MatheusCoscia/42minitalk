/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:15:05 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/22 21:20:35 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	send_msg(int sig, siginfo_t *siginfo, void *nothing)
{
	static int	counter;
	static int	byte;
	static char	*str;
	static char	a = 'a';

	(void)nothing;
	counter = 8;
	
	/*if (sig == SIGUSR1)
		byte += 1 << (counter--);
	if (counter == 0)
	{
		str = ft_itoa(byte);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	byte = 0;
	counter = 0;
	kill(siginfo->si_pid, SIGUSR1);*/
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = send_msg;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	get_pid();
	while(1)
		pause();
	return (0);
}
