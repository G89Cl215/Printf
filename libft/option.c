/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:50:46 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/17 17:21:18 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

int		ft_help(void)
{
	ft_putstr("les options legits sont : ");
	ft_putendl(OPT);
	return (0);
}

int		ft_usage(char *arg)
{
	while (*arg && ft_isin(*arg, OPT))
		arg++;
	ft_putstr("illegal option : ");
	ft_putchar(*arg);
	ft_putchar('\n');
	ft_putstr("usage : ");
	ft_help();
	return (0);
}

long	ft_option(char *arg)
{
	long	options;

	options = 0;
	while (*arg && ft_isin(*arg, OPT))
		options |= ((long)1 << ft_indice(*arg++, OPT));
	return (*arg ? ~((long)0) : options);
}

int		option(int ac, char **av, long *options)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			*options |= ft_option(av[i]);
		else
			break ;
		if (!(*options + 1))
			return (ft_usage(av[i]));
		i++;
	}
	if (((long)1 << ft_indice(USAGE, OPT)) & *options)
		return (ft_help());
	return (i);
}
