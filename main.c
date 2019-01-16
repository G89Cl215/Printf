/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:22:18 by baavril           #+#    #+#             */
/*   Updated: 2019/01/16 22:01:43 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int tab;
	int *c; 
	c = malloc(sizeof(int));
//	printf("%p\n", c);
	unsigned int i = -1;
	//ft_printf("10 : %d, %b, %s, %c, %x, %%, %X, %o, %i, %u, %p, bonjour%n\n", 10, 200, 0, 'a', 95, 15, 8, 10, i, "hello world", &tab);
//	printf("10 : %d, %s, %c, %x, %X, %o, %i, %u, %p, %n\n", 10, (char*)0, 'a', 95, 15, 8, 10, i, "hello world", tab);
//	ft_printf("geeks for %ngeeks", 10, c); 
	ft_printf("%.1d\n", 10); 
	printf("%.1d", 10); 
//	printf("%d\n", c);
//	ft_printf("%d", *c); 
//	ft_printf("%d", c); 
//	ft_printf("%d", c); 
//	ft_printf("pos : %1$d %3$s\n", 10);
//	printf("pos : %1$d %1$d", 10);
//	printf("10 : %d, %s, %c, %x, %o, %i, %u\n", 10, (char*)0, 'a', 95, 8, 10, i);
}
