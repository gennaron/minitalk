/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/11 15:50:11 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*int_to_bin(int chr)
{
	int		tmp;
	int		len;
	char	*bin;

	tmp = chr;
	len = 0;
	while (tmp)
	{
		tmp = tmp / 2;
		len++;
	}
	bin = malloc((len) * sizeof (char));
	while (len >= 0)
	{

		bin[len] = chr % 2 + '0';
		chr = chr / 2;
		len--;
	}
	bin = ft_strjoin_free(bin, "\0");
	return (bin);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		j;
	size_t	i;
	char	*bin;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error\ninvalid number of args\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		bin = int_to_bin(str[i]);
		j = 0;
		while (bin[j])
		{
			ft_printf("%c", bin[j]);
			if (bin[j] == '0')
				kill(pid, SIGUSR2);
			else if (bin[j] == '1')
				kill(pid, SIGUSR1);
			j++;
		}
		i++;
	}
}