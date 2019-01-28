/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:22:18 by baavril           #+#    #+#             */
/*   Updated: 2019/01/27 18:55:33 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "inttypes.h"
#include "limits.h"
#include <stdio.h>

int	main()
{
	int p; 
//	c = malloc(sizeof(int));
//	printf("%p\n", c);
//	unsigned int i = -1;
//	ft_printf("10 : %d, %s, %c, %x, %X, %o, %i, %u, %p\n", 10, 0, 'a', 95, 15, 8, 10, i, "hello world");
//		printf("10 : %d, %s, %c, %x, %X, %o, %i, %u, %p\n", 10, (char*)0, 'a', 95, 15, 8, 10, i, "hello world");
//	ft_printf("geeks for %ngeeks", 10, c); 
//	ft_printf("%.9s\n", "bonjourmon"); 
//	ft_printf("%.12d, %012d, %.12d, %.10d, %50d, %50.80d\n", 42, -42, -24, -90, 75, -200); 
//	printf("%.12d, %012d, %.12d, %.10d, %50d, %50.80d\n", 42, -42, -24, -90, 75, -200); 
//	ft_printf("%1$d %2$d\n", 90, 90); 
//	ft_printf("%p", &p);
//	printf("%p", &p);

	ft_printf("{%-15Z}", 123);
	printf("{%-15Z}", 123);
//	printf("%d\n", printf("before %d after", 42));
//	printf("%%");
//	printf("% +d", 5);
//	printf("%.5f\n", 5.36);

/* printf test ' ' flag 
  	ft_printf("% d\n", 5);
  	printf("% d\n\n\n", 5);
 	ft_printf("% 10d\n", 5);
  	printf("% 10d\n\n\n", 5);
	ft_printf("%            .5d\n", 5);
	printf("%            .5d\n\n\n", 5);
	ft_printf("% +d\n", 5); */

/* string tests (valides + indetermines) ok !

	ft_printf("%.2s", (char*)0);
	printf("%.2s", (char*)0);
	ft_printf("%15s", (char*)0);
	printf("%15s", (char*)0);
	ft_printf("%15s", "bonjour");
	printf("%15s", "bonjour");
	ft_printf("%5s", "bonjour");
	printf("%5s", "bonjour");
	ft_printf("%.5s", "bonjour");
	printf("%.5s", "bonjour");
	ft_printf("%50.5s", "bonjour");
	printf("%50.5s", "bonjour");
	ft_printf("%050.5s", "bonjour");
	printf("%050.5s", "bonjour");
	ft_printf("%05.15s", "bonjour");
	printf("%05.15s", "bonjour");*/


//	ft_printf("%i", 42);
//	ft_printf("%i", -42);
//	ft_printf("beforec%i after", 42);
//	ft_printf("%i%i%i%i%i",
//		1, -2, 3, -4, 5);
//	ft_printf("a%ib%ic%id",
//		1, -2, 3);
//	ft_printf("%p", &str);
//	printf("%p", &str);
//	ft_printf("%p", &strlen);
//	printf("%p", &strlen);
//	ft_printf("%p", 0);
//	printf("%p", 0);


// chars tests (valides + indetermines) ok !
	//ft_printf("%c\n", 48);
	//printf("%c\n", 48);
//	ft_printf("%#08x\n", 42);
//	ft_printf("%#-08x\n", 42);
//	ft_printf("moulitest: %#.x %#.0x", 0, 0);
/*	ft_printf("%c\n", 480);
	printf("%c\n", 480);
	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	ft_printf("% c\n", 'a');
	printf("% c\n", 'a');
	ft_printf("%25c\n", 'a');
	printf("%25c\n", 'a');
	ft_printf("%025c\n", 'a');
	printf("%025c\n", 'a');
	ft_printf("%c\n", 0);
	printf("%c\n", 0);
	ft_printf("%25c\n", 0);
	printf("%25c\n", 0);
	ft_printf("%025c\n", 0);
	printf("%025c\n", 0);
	ft_printf("%.25c\n", 'a');
	printf("%.25c\n", 'a');*/
// 	ft_printf("%.2s is a string\n", "");
 //	printf("%.2s is a string\n", "");
//	ft_printf("%#x", 0);
//	ft_printf("%#x", 0);
//	printf("%#x", 0);
//	ft_printf("@moulitest %.x %.0x", 0, 0);
//	printf("@moulitest %.x %.0x", 0, 0);

//	ft_printf("%c", 'c');
//	ft_printf("%c%c", '4', '2');
/*	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');*/
	uintmax_t i;
	int j;

	j = 50;
	i = 4294967296;

//	ft_printf("%llD, %llD", (unsigned long long)0, (unsigned long long)USHRT_MAX);

//	printf("%5+d", 42);


//	ft_printf("%-+10.5d\n", 4242);
//	printf("%-+10.5d\n", 4242);
	//ft_printf("%5%");
/*	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("aa%%bb\n");
	printf("aa%%bb\n");
	ft_printf("%%%%%%%%%%\n");
	printf("%%%%%%%%%%\n");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");*/
//	ft_printf("%");
//	printf("%");
//	ft_printf("% Zoooo");
//	printf("% Zoooo");
	//ft_printf("{%}");
	//printf("{%}");
	//ft_printf("{% %}");
//	printf("{% %}");

	//printf("%ld\n", -2147483648);

/* // tests pour 'd' integers - alllllllllright
	ft_printf("%+.50d\n", 50);
	printf("%+.50d\n", 50);
	ft_printf("%+50d\n", 50);
	printf("%+50d\n", 50);
	ft_printf("%d\n", -0);
	printf("%d\n", -0);
	ft_printf("%+d\n", -0);
	printf("%+d\n", -0);
	ft_printf("%+d\n", 0);
	printf("%+d\n", 0);
	ft_printf("%+d\n", -10);
	printf("%+d\n", -10);
	ft_printf("%-d\n", -0);
	printf("%-d\n", -0);
	ft_printf("%d\n", 0);
	printf("%d\n", 0);
	ft_printf("%+d\n", 10);
	printf("%+d\n", 10);
	ft_printf("%+ d\n", 10);
	printf("%+ d\n", 10);
	ft_printf("%+50d\n", 10);
	printf("%+50d\n", 10);
	ft_printf("%+.50d\n", 10);
	printf("%+.50d\n", 10);
	ft_printf("%-d\n", 10);
	printf("%-d\n", 10);
	ft_printf("%-50d\n", 10);
	printf("%-50d\n", 10);
	ft_printf("%-d\n", -10);
	printf("%-d\n", -10);
	ft_printf("%-d\n", -0);
	printf("%-d\n", -0);
	ft_printf("%-50d\n", 50);
	printf("%-50d\n", 50);
	ft_printf("%-.50d\n", 50);
	printf("%-.50d\n", 50);
	ft_printf("%-050d\n", 50);
	printf("%-050d\n", 50);
	ft_printf("%-+d\n", 50);
	printf("%-+d\n", 50);
	ft_printf("%+-d\n", 50);
	printf("%+-d\n", 50);
	ft_printf("%+-50d\n", -50);
	printf("%+-50d\n", -50);
	ft_printf("%+-50d\n", 50);
	printf("%+-50d\n", 50);
	ft_printf("%+-.50d\n", 50);
	printf("%+-.50d\n", 50);
	ft_printf("%+-050d\n", 50);
	printf("%+-.050d\n", 50);
	ft_printf("%+-*d\n", 50, 60);
	printf("%+-*d\n", 50, 60);
	ft_printf("%+*d\n", 10, 10);
	printf("%+*d\n", 10, 10);
	ft_printf("% d\n", 10);
	printf("% d\n", 10);
	ft_printf("%d\n", 10);
	printf("%d\n", 10);
	ft_printf("%10d\n", 10);
	printf("%10d\n", 10);
	ft_printf("%010d\n", 10);
	printf("%010d\n", 10);
	ft_printf("%.10d\n", 10);
	printf("%.10d\n", 10);
	ft_printf("%50.10d\n", 10);
	printf("%50.10d\n", 10);
	ft_printf("%10.50d\n", 10);
	printf("%10.50d\n", 10);
	ft_printf("%10.50d\n", 10);
	printf("%10.50d\n", 10);
	ft_printf("%*d\n", 10);
	printf("%*d\n", 10);
	ft_printf("%*d\n", 10);
	printf("%*d\n", 10);
	ft_printf("%*.d\n", 10);
	printf("%*.d\n", 10);
	ft_printf("%*.50d\n", 10);
	printf("%*.50d\n", 10);
	ft_printf("%*d\n", 10, 20);
	printf("%*d\n", 10, 20);
	ft_printf("%*5d\n", 10, 20);
	printf("%*5d\n", 10, 20);
	ft_printf("%.50d %*d\n", 10, 20, 30);
	printf("%.50d %*d\n", 10, 20, 30);
	ft_printf("%*.*d\n", 10, 20, 30);
	printf("%*.*d\n", 10, 20, 30);
	ft_printf("%.30d %50d %*d\n", 10, 20, 30, 10);
	printf("%.30d %50d %*d\n", 10, 20, 30, 10);
	ft_printf("%0d\n", 10);
	printf("%0d\n", 10);
	ft_printf("%050d\n", 10);
	printf("%050d\n", 10);
	ft_printf("%050d, %.30d %50d %*d\n", 10, 20, 30, 10, 25);
	printf("%050d, %.30d %50d %*d\n", 10, 20, 30, 10, 25);
	ft_printf("%.30d %50d %050d %*d\n", 10, 20, 30, 10, 25);
	printf("%.30d %50d %050d %*d\n", 10, 20, 30, 10, 25);
	ft_printf("%50d %.30d %050d %*d\n", 10, 20, 30, 10, 25);
	printf("%50d %.30d %050d %*d\n", 10, 20, 30, 10, 25);
	ft_printf("%050d, %.30d %50d %*d\n", -10, -20, -30, -10, -25);
	printf("%050d, %.30d %50d %*d\n", -10, -20, -30, -10, -25);
	ft_printf("%.30d %50d %050d %*d\n", -10, -20, -30, -10, -25);
	printf("%.30d %50d %050d %*d\n", -10, -20, -30, -10, -25);
	ft_printf("%50d %.30d %050d %*d\n", -10, -20, -30, -10, -25);
	printf("%50d %.30d %050d %*d\n", -10, -20, -30, -10, -25);
*/

/* tests pour 'i' integers - allllllllllllright
	ft_printf("%+.50i\n", 50);
	printf("%+.50i\n", 50);
	ft_printf("%+50i\n", 50);
	printf("%+50i\n", 50);
	ft_printf("%i\n", -0);
	printf("%i\n", -0);
	ft_printf("%+i\n", -0);
	printf("%+i\n", -0);
	ft_printf("%+i\n", 0);
	printf("%+i\n", 0);
	ft_printf("%+i\n", -10);
	printf("%+i\n", -10);
	ft_printf("%-i\n", -0);
	printf("%-i\n", -0);
	ft_printf("%i\n", 0);
	printf("%i\n", 0);
	ft_printf("%+i\n", 10);
	printf("%+i\n", 10);
	ft_printf("%+ i\n", 10);
	printf("%+ i\n", 10);
	ft_printf("%+50i\n", 10);
	printf("%+50i\n", 10);
	ft_printf("%+.50i\n", 10);
	printf("%+.50i\n", 10);
	ft_printf("%-i\n", 10);
	printf("%-i\n", 10);
	ft_printf("%-50i\n", 10);
	printf("%-50i\n", 10);
	ft_printf("%-i\n", -10);
	printf("%-i\n", -10);
	ft_printf("%-i\n", -0);
	printf("%-i\n", -0);
	ft_printf("%-50i\n", 50);
	printf("%-50i\n", 50);
	ft_printf("%-.50i\n", 50);
	printf("%-.50i\n", 50);
	ft_printf("%-050i\n", 50);
	printf("%-050i\n", 50);
	ft_printf("%-+i\n", 50);
	printf("%-+i\n", 50);
	ft_printf("%+-i\n", 50);
	printf("%+-i\n", 50);
	ft_printf("%+-50i\n", -50);
	printf("%+-50i\n", -50);
	ft_printf("%+-50i\n", 50);
	printf("%+-50i\n", 50);
	ft_printf("%+-.50i\n", 50);
	printf("%+-.50i\n", 50);
	ft_printf("%+-050i\n", 50);
	printf("%+-.050i\n", 50);
	ft_printf("%+-*i\n", 50, 60);
	printf("%+-*i\n", 50, 60);
	ft_printf("%+*i\n", 10, 10);
	printf("%+*i\n", 10, 10);
	ft_printf("% i\n", 10);
	printf("% i\n", 10);
	ft_printf("%i\n", 10);
	printf("%i\n", 10);
	ft_printf("%10i\n", 10);
	printf("%10i\n", 10);
	ft_printf("%010i\n", 10);
	printf("%010i\n", 10);
	ft_printf("%.10i\n", 10);
	printf("%.10i\n", 10);
	ft_printf("%50.10i\n", 10);*/

/*	Tests pour les floats */
	
//	ft_printf("%f %f\n", 3.14, 0.16);
//	printf("%f %f\n", 3.14, 0.16);

//	ft_printf("%.7e %.7e\n", 3.14, 0.16);
//printf("%.7e %.7e\n", 3.14, 0.16);
/*
	printf("%50.10i\n", 10);
	ft_printf("%10.50i\n", 10);
	printf("%10.50i\n", 10);
	ft_printf("%10.50i\n", 10);
	printf("%10.50i\n", 10);
	ft_printf("%*i\n", 10);
	printf("%*i\n", 10);
	ft_printf("%*i\n", 10);
	printf("%*i\n", 10);
	ft_printf("%*.i\n", 10);
	printf("%*.i\n", 10);
	ft_printf("%*.50i\n", 10);
	printf("%*.50i\n", 10);
	ft_printf("%*i\n", 10, 20);
	printf("%*i\n", 10, 20);
	ft_printf("%*5i\n", 10, 20);
	printf("%*5i\n", 10, 20);
	ft_printf("%.50i %*i\n", 10, 20, 30);
	printf("%.50i %*i\n", 10, 20, 30);
	ft_printf("%*.*i\n", 10, 20, 30);
	printf("%*.*i\n", 10, 20, 30);
	ft_printf("%.30i %50i %*i\n", 10, 20, 30, 10);
	printf("%.30i %50i %*i\n", 10, 20, 30, 10);
	ft_printf("%0i\n", 10);
	printf("%0i\n", 10);
	ft_printf("%050i\n", 10);
	printf("%050i\n", 10);
	ft_printf("%050i, %.30i %50i %*i\n", 10, 20, 30, 10, 25);
	printf("%050i, %.30i %50i %*i\n", 10, 20, 30, 10, 25);
	ft_printf("%.30i %50i %050i %*i\n", 10, 20, 30, 10, 25);
	printf("%.30i %50i %050i %*i\n", 10, 20, 30, 10, 25);
	ft_printf("%50i %.30i %050i %*i\n", 10, 20, 30, 10, 25);
	printf("%50i %.30i %050i %*i\n", 10, 20, 30, 10, 25);
	ft_printf("%050i, %.30i %50i %*i\n", -10, -20, -30, -10, -25);
	printf("%050i, %.30i %50i %*i\n", -10, -20, -30, -10, -25);
	ft_printf("%.30i %50i %050i %*i\n", -10, -20, -30, -10, -25);
	printf("%.30i %50i %050i %*i\n", -10, -20, -30, -10, -25);
	ft_printf("%50i %.30i %050i %*i\n", -10, -20, -30, -10, -25);
	printf("%50i %.30i %050i %*i\n", -10, -20, -30, -10, -25);
*/



	
// printf test + and - flags
//	ft_printf("%15c", 'a');
//	printf("%15c", 'a');
/*	ft_printf("%+d\n", -5);
	ft_putendl("printf\n");
	printf("%+d\n", -5);
	ft_printf("%+15.20d\n", 5); 
	ft_putendl("printf\n");
	printf("%+15.20d\n", 5); 
	ft_printf("%+15.7d\n", 5); 
	ft_putendl("printf");
	printf("%+15.7d\n", 5); */
//	ft_printf("%+15d\n", 5); 
//	ft_putendl("printf");
//	printf("%+15d\n", 5); 
//	ft_printf("%-15d\n", 5); 
//	ft_putendl("printf");
//	printf("%-15d\n", 5); 
//	ft_printf("%-15.20d\n", 5); 
//	ft_putendl("printf");
//	printf("%-15.20d\n", 5); 
//	ft_printf("%-15.7d\n\n", 5); 
//	ft_putendl("printf");
//	printf("%-15.7d\n", 5); 


//	printf("4567 |%10c5d| plip\n", ']', 12);
//	ft_printf("4567 |%10]5d| plip\n", 12);
/*	printf("4567 |%-10]5d| plip\n", 12);
	ft_printf("4567 |%-10]5d| plip\n", 12);
	printf("|%10.5d|\n", -12);
	ft_printf("|%10.5d|\n", -12);
	printf("|%10d|\n", -12);
	ft_printf("|%10d|\n", -12);
	printf("|%010d|\n", -12);
	ft_printf("|%010d|\n", -12);
	printf("|%-10.5d|\n", -12);
	ft_printf("|%-10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);
	ft_printf("|%-010.5d|\n", -12);*/
//	ft_printf("before %d after", 42);
//	ft_printf("%f", 90.5); 
//	printf("%u, %u\n", 90, 90); 
//	printf("%012d, %012d, %12d, %*d\n", 42, -42, -24, 90, 90); 
//	printf("%012d, %12d, %012d, %.10d\n", 42, -42, -24, 90); 
//	ft_printf("%.6d, %.10d\n", 42, -42);
//	ft_printf("%.6d, %010d\n", -42, 42);
//	printf("%.6d, %010d", -42, 42);
//	printf("%012d, %12d, %012d, %.10d\n", 42, -42, -24, 90); 
//	printf("%040d", 42); 
//	printf("%12d, %12d\n", 42, -42); 
//	ft_printf("%*.9d\n", 50, 60); 
//	ft_printf("%*50d\n", 50, 80); 
//	ft_printf("%*.*d\n", 50, 60, 70); 
//	printf("%*50d\n", 50, 80); 
//	printf("%*d\n", 50, 60); 
//	printf("%.9c", 10); 
//	printf("%d\n", c);
//	ft_printf("%d", *c); 
//	ft_printf("%d", c); 
//	ft_printf("%d", c); 
//	ft_printf("pos : %1$d %3$s\n", 10);
//	printf("pos : %1$d %1$d", 10);
//	printf("10 : %d, %s, %c, %x, %o, %i, %u\n", 10, (char*)0, 'a', 95, 8, 10, i);
}
