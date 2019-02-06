/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:09:49 by baavril           #+#    #+#             */
/*   Updated: 2019/02/06 19:42:31 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "inttypes.h"
#include "limits.h"
#include <stdio.h>
int main()
{
//	int p;
//	char str;
//	c = malloc(sizeof(int));
//	printf("%p\n", c);
/*	unsigned int i = -1;
	ft_printf("10 : %d, %s, %c, %x, %X, %o, %i, %u, %p\n", 10, 0, 'a', 95, 15, 8, 10, i, "hello world");
	printf("10 : %d, %s, %c, %x, %X, %o, %i, %u, %p\n", 10, (char)0, 'a', 95, 15, 8, 10, i, "hello world");
//	ft_printf("geeks for %ngeeks", 10, c);
	ft_printf("%.9s\n", "bonjourmongars");
	printf("%.9s\n", "bonjourmongars");
	ft_printf("%.12d, %012d, %.12d, %.10d, %50d, %50.80d\n", 42, -42, -24, -90, 75, -200);
	printf("%.12d, %012d, %.12d, %.10d, %50d, %50.80d\n", 42, -42, -24, -90, 75, -200);
	ft_printf("%1$d %2$d\n", 90, 90);
	   printf("%1$d %2$d\n", 90, 90);
	ft_printf("{%-15Z}\n", 123);
	   printf("{%-15Z}\n", 123);
	ft_printf("%d\n", printf("before %d after", 42));
	   printf("%d\n", printf("before %d after", 42));
	ft_printf("%%\n");
	   printf("%%\n");
	ft_printf("% +d\n", 5);
	   printf("% +d\n", 5);
	ft_printf("%.5f\n", 5.36);
	   printf("%.5f\n", 5.36);
//	printf test ' ' flag
	ft_printf("% d\n", 5);
	   printf("% d\n\n\n", 5);
	ft_printf("% 10d\n", 5);
	   printf("% 10d\n\n\n", 5);
	ft_printf("%            .5d\n", 5);
	   printf("%            .5d\n\n\n", 5);
	ft_printf("% +d\n", 5);
	   printf("% +d\n", 5); 
//	string tests (valides + indetermines) ok !
	ft_printf("%.2s\n", (char)0);
	   printf("%.2s\n", (char)0);
	ft_printf("%15s\n", (char)0);
	   printf("%15s\n", (char)0);
	ft_printf("%15s\n", "bonjour");
	   printf("%15s\n", "bonjour");
	ft_printf("%5s\n", "bonjour");
	   printf("%5s\n", "bonjour");
	ft_printf("%.5s\n", "bonjour");
	   printf("%.5s\n", "bonjour");
	ft_printf("%50.5s\n", "bonjour");
	   printf("%50.5s\n", "bonjour");
	ft_printf("%050.5s\n", "bonjour");
	   printf("%050.5s\n", "bonjour");
	ft_printf("%05.15s\n", "bonjour");
	   printf("%05.15s\n", "bonjour");
	ft_printf("%i\n", 42);
	   printf("%i\n", 42);
	ft_printf("%i\n", -42);
	   printf("%i\n", -42);
	ft_printf("before %i after\n", 42);
	   printf("before %i after\n", 42);
	ft_printf("%i%i%i%i%i\n",
			1, -2, 3, -4, 5);
	   printf("%i%i%i%i%i\n",
			1, -2, 3, -4, 5);
	ft_printf("a%ib%ic%id\n",
			1, -2, 3);
	   printf("a%ib%ic%id\n",
			1, -2, 3);
	ft_printf("%p\n", &strlen);
	   printf("%p\n", &strlen);
	ft_printf("%p\n", 0);
	   printf("%p\n", 0);
	ft_printf("%.0p, %.p\n", 0, 0);
	   printf("%.0p, %.p\n", 0, 0);
	ft_printf("%c\n", 48);
	   printf("%c\n", 48);
	ft_printf("%#08x\n", 42);
	   printf("%#08x\n", 42);
	ft_printf("%#-08x\n", 42);
	   printf("%#-08x\n", 42);
	ft_printf("moulitest: %#.x %#.0x\n", 0, 0);
	   printf("moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("%c\n", 480);
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
	   printf("%.25c\n", 'a');
	ft_printf("%.2s is a string\n", "");
	   printf("%.2s is a string\n", "");
	ft_printf("%#x\n", 0);
	   printf("%#x\n", 0);
	ft_printf("@moulitest %.x %.0x\n", 0, 0);
	printf("@moulitest %.x %.0x\n", 0, 0);
	ft_printf("%c", 'c');
	   printf("%c", 'c');
	ft_printf("%c%c\n", '4', '2');
	   printf("%c%c\n", '4', '2');
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
			%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
			' ', '!', '"', '#', '$', '%', '&', '\\', '(', ')', ' ', '+', ',', '-',
			'.', ' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
			'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
			'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
			'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
			't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
//	uintmax_t i;
//	int j;
//	j = 50;
//	i = 4294967296;
	ft_printf("%llD, %llD", (unsigned long long)0, (unsigned long long)USHRT_MAX);
	   printf("%llD, %llD", (unsigned long long)0, (unsigned long long)USHRT_MAX);
	ft_printf("%5+d", 42);
	   printf("%5+d", 42);
	ft_printf("%-+10.5d\n", 4242);
	   printf("%-+10.5d\n", 4242);
	ft_printf("%5%");
	   printf("%5%");
	ft_printf("%%\n");
	   printf("%%\n");
	ft_printf("aa%%bb\n");
	   printf("aa%%bb\n");
	ft_printf("%%%%%%%%%%\n");
	   printf("%%%%%%%%%%\n");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	   printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ft_printf("%");
	   printf("%");
	ft_printf("% Zoooo");
	   printf("% Zoooo");
	ft_printf("{%}");
	   printf("{%}");
	ft_printf("{% %}");
	   printf("{% %}");
	ft_printf("%ld\n", -2147483648);
	   printf("%ld\n", -2147483648);
//	tests pour 'd' integers - alllllllllright
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
	ft_printf("%+-d\n", 50);
	   printf("%+-d\n", 50);
	ft_printf("%+-50d\n", 50);
	   printf("%+-50d\n", 50);
	ft_printf("%+-.050d\n", 50);
	   printf("%+-.050d\n", 50);
	ft_printf("%+-d\n", 50, 60);
	   printf("%+-d\n", 50, 60);
	ft_printf("%+d\n", 10, 10);
	printf("%+d\n", 10, 10);
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
	ft_printf("%d\n", 10);
	printf("%d\n", 10);
	ft_printf("%d\n", 10);
	printf("%d\n", 10);
	ft_printf("%.d\n", 10);
	printf("%.d\n", 10);
	ft_printf("%.50d\n", 10);
	printf("%.50d\n", 10);
	ft_printf("%d\n", 10, 20);
	printf("%d\n", 10, 20);
	ft_printf("%5d\n", 10, 20);
	printf("%5d\n", 10, 20);
	ft_printf("%.50d %d\n", 10, 20, 30);
	printf("%.50d %d\n", 10, 20, 30);
	ft_printf("%.d\n", 10, 20, 30);
	printf("%.d\n", 10, 20, 30);
	ft_printf("%.30d %50d %d\n", 10, 20, 30, 10);
	printf("%.30d %50d %d\n", 10, 20, 30, 10);
	ft_printf("%0d\n", 10);
	printf("%0d\n", 10);
	ft_printf("%050d\n", 10);
	printf("%050d\n", 10);
	ft_printf("%050d, %.30d %50d %d\n", 10, 20, 30, 10, 25);
	printf("%050d, %.30d %50d %d\n", 10, 20, 30, 10, 25);
	ft_printf("%.30d %50d %050d %d\n", 10, 20, 30, 10, 25);
	printf("%.30d %50d %050d %d\n", 10, 20, 30, 10, 25);
	ft_printf("%50d %.30d %050d %d\n", 10, 20, 30, 10, 25);
	printf("%50d %.30d %050d %d\n", 10, 20, 30, 10, 25);
	ft_printf("%050d, %.30d %50d %d\n", -10, -20, -30, -10, -25);
	printf("%050d, %.30d %50d %d\n", -10, -20, -30, -10, -25);
	ft_printf("%.30d %50d %050d %d\n", -10, -20, -30, -10, -25);
	printf("%.30d %50d %050d %d\n", -10, -20, -30, -10, -25);
	ft_printf("%50d %.30d %050d %d\n", -10, -20, -30, -10, -25);
	printf("%50d %.30d %050d %d\n", -10, -20, -30, -10, -25);
	//tests pour 'i' integers - allllllllllllright
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
	ft_printf("|%+-.50i|\n", 50);
	   printf("|%+-.50i|\n", 50);
	ft_printf("\n\n=====\n\n");
	
	ft_printf("|%+-050i|\n", 50);
	   printf("|%+-050i|\n", 50);
	ft_printf("\n\n=====\n\n");
	
	ft_printf("%+-i\n", 50, 60);
	   printf("%+-i\n", 50, 60);
	ft_printf("%+i\n", 10, 10);
	   printf("%+i\n", 10, 10);
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
	ft_printf("%50.10i\n", 10);
	   printf("%50.10i\n", 10);
	//Tests pour les floats
	ft_printf("%f %f\n", 3.14, 0.16);
	   printf("%f %f\n", 3.14, 0.16);
	ft_printf("%.7e %.7e\n", 3.14, 0.16);
	   printf("%.7e %.7e\n", 3.14, 0.16);
//	printf("%50.10i\n", 10);
	ft_printf("\n\n=====\n\n");
	ft_printf("%10.50i\n", 10);
	   printf("%10.50i\n", 10);
	ft_printf("%10.50i\n", 10);
	   printf("%10.50i\n", 10);
	ft_printf("%i\n", 10);
	   printf("%i\n", 10);
	ft_printf("%i\n", 10);
	   printf("%i\n", 10);
	ft_printf("%.i\n", 10);
	   printf("%.i\n", 10);
	ft_printf("%.50i\n", 10);
	   printf("%.50i\n", 10);
	ft_printf("%i\n", 10, 20);
	   printf("%i\n", 10, 20);
	ft_printf("%5i\n", 10, 20);
	   printf("%5i\n", 10, 20);
	ft_printf("%.50i %i\n", 10, 20, 30);
	   printf("%.50i %i\n", 10, 20, 30);
	ft_printf("%.i\n", 10, 20, 30);
	   printf("%.i\n", 10, 20, 30);
	ft_printf("%.30i %50i %i\n", 10, 20, 30, 10);
	   printf("%.30i %50i %i\n", 10, 20, 30, 10);
	ft_printf("%0i\n", 10);
	   printf("%0i\n", 10);
	ft_printf("%050i\n", 10);
	   printf("%050i\n", 10);
	ft_printf("%050i, %.30i %50i %i\n", 10, 20, 30, 10, 25);
	   printf("%050i, %.30i %50i %i\n", 10, 20, 30, 10, 25);
	ft_printf("%.30i %50i %050i %i\n", 10, 20, 30, 10, 25);
	   printf("%.30i %50i %050i %i\n", 10, 20, 30, 10, 25);
	ft_printf("%50i %.30i %050i %i\n", 10, 20, 30, 10, 25);
	   printf("%50i %.30i %050i %i\n", 10, 20, 30, 10, 25);
	ft_printf("%050i, %.30i %50i %i\n", -10, -20, -30, -10, -25);
	   printf("%050i, %.30i %50i %i\n", -10, -20, -30, -10, -25);
	ft_printf("%.30i %50i %050i %i\n", -10, -20, -30, -10, -25);
	   printf("%.30i %50i %050i %i\n", -10, -20, -30, -10, -25);
	ft_printf("%50i %.30i %050i %i\n", -10, -20, -30, -10, -25);
	   printf("%50i %.30i %050i %i\n", -10, -20, -30, -10, -25);
	//printf test + and - flags
	ft_printf("%15c", 'a');
	   printf("%15c", 'a');
	ft_printf("%+d\n", -5);
	printf("%+d\n", -5);
	ft_printf("%+15.20d\n", 5);
	printf("%+15.20d\n", 5);
	ft_printf("%+15.7d\n", 5);
	printf("%+15.7d\n", 5);
	ft_printf("%+15d\n", 5);
	ft_putendl("printf");
	printf("%+15d\n", 5);
	ft_printf("%-15d\n", 5);
	ft_putendl("printf");
	printf("%-15d\n", 5);
	ft_printf("%-15.20d\n", 5);
	ft_putendl("printf");
	printf("%-15.20d\n", 5);
	ft_printf("%-15.7d\n\n", 5);
	ft_putendl("printf");
	printf("%-15.7d\n", 5);
	printf("4567 |%10c5d| plip\n", ']', 12);
	ft_printf("4567 |%10]5d| plip\n", 12);
	printf("4567 |%-10]5d| plip\n", 12);
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
	ft_printf("|%-010.5d|\n", -12);
	ft_printf("before %d after", 42);
	ft_printf("%f", 90.5);
	printf("%u, %u\n", 90, 90);
	ft_printf("%012d, %012d, %12d, %.10d\n", 42, -42, -24, 90);
	   printf("%012d, %012d, %12d, %.10d\n", 42, -42, -24, 90);
	ft_printf("%.6d, %010d\n", -42, 42);
	   printf("%.6d, %010d", -42, 42);
	ft_printf("%012d, %12d, %012d, %.10d\n", 42, -42, -24, 90);
	   printf("%012d, %12d, %012d, %.10d\n", 42, -42, -24, 90);
	ft_printf("%040d\n", 42);
	   printf("%040d\n", 42);
	ft_printf("%12d, %12d\n", 42, -42);
	   printf("%12d, %12d\n", 42, -42);
	ft_printf("%.9d\n", 50, 60);
	   printf("%.9d\n", 50, 60);
	ft_printf("%50d\n", 50, 80);
	   printf("%50d\n", 50, 80);
	ft_printf("%.d\n", 50, 60, 70);
	   printf("%.d\n", 50, 60);
	ft_printf("%.9c", 10);
	   printf("%.9c", 10);
	ft_printf("\n======\n\n");
	ft_printf("pos : %1$d %d\n", 10);
	   printf("pos : %1$d %1$d\n", 10);
	ft_printf("10 : %d, %s, %c, %x, %o, %i, %u\n", 10, (char)0, 'a', 95, 8, 10, i);
	   printf("10 : %d, %s, %c, %x, %o, %i, %u\n", 10, (char)0, 'a', 95, 8, 10, i);
	ft_printf("plop \n\n\n");*/
	

/*	ft_printf("\n======\n\n");
	unsigned int		fl = 33554432;
	unsigned int		index = 0;
	
	while (index++ < 89)
	{
	ft_printf("%.100f\n", (unsigned int)(fl + 1000 * index));
	   printf("%.100f\n\n", (unsigned int)(fl + 1000 * index));
	}*/

//	ft_printf("%#llx", (unsigned long long)9223372036854775807);
//	printf("%#llx", (unsigned long long)9223372036854775807);	

	/*ft_printf("!% 02hhi!\n", 10365270);
	printf("!% 02hhi!\n", 10365270);
	ft_printf("%-+52.56lli!\n", -173717177);
	printf("%-+52.56lli!\n", -173717177);
	ft_printf("%+34lli\n", 2147078299);
	printf("%+34lli\n", 2147078299);
	ft_printf("% 042.57zi\n", 0);
	printf("% 042.57zi\n", 0);
	ft_printf("\\!/%+-24hi\\!/\n", 1121365074);
	printf("\\!/%+-24hi\\!/\n", 1121365074);
	ft_printf("%- 8hhi\n", 0);
	printf("%- 8hhi\n", 0);
	ft_printf("!%+2.2lli!\n", -1395120672);
	printf("!%+2.2lli!\n", -1395120672);
	ft_printf("^.^/% 02hhi^.^/\n",-273664185);
	printf("^.^/% 02hhi^.^/\n",-273664185);
	ft_printf("!%+2.56hhi!\n", -2003103360);
	printf("!%+2.56hhi!\n", -2003103360);
	ft_printf("\\!/%+-.13lli\\!/\n", -294064776);
	printf("\\!/%+-.13lli\\!/\n", -294064776);
	ft_printf("%-+10.5d\n", 4242);
	printf("%-+10.5d\n", 4242);
	ft_printf("%-+52.56lli!\n", -173717177);
	printf("%-+52.56lli!\n", -173717177);
	ft_printf("^.^/%+02.3hi^.^/\n", -1355085574);
	printf("^.^/%+02.3hi^.^/\n", -1355085574);
	ft_printf("%+.2hhi\n", -1227182718);
	printf("%+.2hhi\n", -1227182718);
	ft_printf("\\!/% 02lli\\!/\n", 1088953535);
	printf("\\!/% 02lli\\!/\n", 1088953535);
	ft_printf("%+-10lli\n", 828919416);
	printf("%+-10lli\n", 828919416);
	ft_printf("\\!/%0+2hhd\\!/\n", 348010578);
	printf("\\!/%0+2hhd\\!/\n", 348010578);
	ft_printf("%-+zi\n", -1957793576);
	printf("%-+zi\n", -1957793576);
	ft_printf("%+2ji\n", -602691356);
	printf("%+2ji\n", -602691356);
	ft_printf("!%0+2hi!\n",-917118824);
	printf("!%0+2hi!\n",-917118824);
	ft_printf("%+10.5d\n", 4242);
	printf("%+10.5d\n", 4242);
	ft_printf("%0+42.2hhi\n", -1912145004);
	printf("%0+42.2hhi\n", -1912145004);
	ft_printf("%+031.2hhi\n", -1445396229);
	printf("%+031.2hhi\n", -1445396229);
	ft_printf("%+34hi\n", 1354727992);
	printf("%+34hi\n", 1354727992);
	ft_printf("%#03.2zo\n", 247298405);
	printf("%#03.2zo\n", 247298405);
	ft_printf("\\!/%-#25.52zo\\!/\n", -835317716);
	printf("\\!/%-#25.52zo\\!/\n", -835317716);
	ft_printf("%0#17o\n",0);
	printf("%0#17o\n",0);
	ft_printf("%0#2zo\n", 0);
	printf("%0#2zo\n", 0);
	ft_printf("%0#26.2hho\n",1692432944);
	printf("%0#26.2hho\n",1692432944);
	ft_printf("%0#.11llo\n",-1874643996);
	printf("%0#.11llo\n",-1874643996);
	ft_printf("%#-jo\n", 300647184);
	printf("%#-jo\n", 300647184);
	ft_printf("^.^/%#-60.2o^.^/\n",-1722717206);
	printf("^.^/%#-60.2o^.^/\n",-1722717206);
	ft_printf("\\!/%#.2hho\\!/\n", -114684383);
	printf("\\!/%#.2hho\\!/\n", -114684383);
	ft_printf("%-#2o\n", 864741930);
	printf("%-#2o\n", 864741930);
	ft_printf("%#-55.2llo\n", 0);
	printf("%#-55.2llo\n", 0);
	ft_printf("^.^/%#-38.9jo^.^/\n", 90114849);
	printf("^.^/%#-38.9jo^.^/\n", 90114849);
	ft_printf("!%#-.2jo!\n", 0);
	printf("!%#-.2jo!\n", 0);
	ft_printf("%-#9.2o\n", 1900737282);
	printf("%-#9.2o\n", 1900737282);
	ft_printf("^.^/%#-.6ho^.^/\n", 2083506146);
	printf("^.^/%#-.6ho^.^/\n", 2083506146);
	ft_printf("%#-2hho\n", -459940586);
	printf("%#-2hho\n", -459940586);
	ft_printf("42%-#10llo42\n", 952029742);
	printf("42%-#10llo42\n", 952029742);
	ft_printf("%-#llO\n", 1867676785847498270);
	printf("%-#llO\n", 1867676785847498270);
	ft_printf("42%-#21.1llo42\n", 0);
	printf("42%-#21.1llo42\n", 0);
	ft_printf("\\!/%-#2hho\\!/\n", -1151536633);
	printf("\\!/%-#2hho\\!/\n", -1151536633);
	ft_printf("42%#-2ho42\n", 0);
	printf("42%#-2ho42\n", 0);
	ft_printf("%-#4.2hho\n", 2072306722);
	printf("%-#4.2hho\n", 2072306722);
	ft_printf("%-#5.1hho\n", 1984014087);
	printf("%-#5.1hho\n", 1984014087);
	ft_printf("%0#22O\n", 547744819599762662);
	printf("%0#22O\n", 547744819599762662);
	ft_printf("^.^/%#-38.2O^.^/\n", 1174934370098357440);
	printf("^.^/%#-38.2O^.^/\n", 1174934370098357440);
	ft_printf("!%#-48O!\n", 137228987753680935);
	printf("!%#-48O!\n", 137228987753680935);
	ft_printf("^.^/%#-24.2O^.^/\n", 95579068586708382);
	printf("^.^/%#-24.2O^.^/\n", 95579068586708382);*/
	ft_printf("%#-2llx\n", 0);
	printf("%#-2llx\n", 0);
	ft_printf("!%#050jx!\n", 0);
	printf("!%#050jx!\n", 0);
	ft_printf("%#-2.24llx\n", -738878974);
	printf("%#-2.24llx\n", -738878974);
	ft_printf("!%#-26.2x!\n", -1598505820);
	printf("!%#-26.2x!\n", -1598505820);
/*	ft_printf("%-#2llx\n", 1814281337);
	printf("%-#2llx\n", 1814281337);
	ft_printf("%0#4.2hhx\n", -290158078);
	printf("%0#4.2hhx\n", -290158078);
	ft_printf("%#-2hhx\n", 213775143);
	printf("%#-2hhx\n", 213775143);*/
	ft_printf("|%#-6.2hhx|\n", 3932898);
	printf("|%#-6.2hhx|\n", 3932898);
	ft_printf("!%0#10jx!\n", -534887398);
	printf("!%0#10jx!\n", -534887398);
//	ft_printf("coco et %-#-#--24O titi%#012o\n", 12, -874);
//	printf("coco et %-#-#--24O titi%#012o\n", 12, -874);
//	ft_printf("%#08x\n", 42);
//	printf("%#08x", 42);
//	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
//	printf("@moulitest: %#.x %#.0x", 0, 0);
//	ft_printf("\n======\n\n");
	
/*	ft_printf("|%.0p|, |%.p|\n", 0, 0);
	   printf("|%.0p|, |%.p|\n", 0, 0);
	ft_printf("|%.5p|\n", 0);
	   printf("|%.5p|\n", 0);
	ft_printf("|%9.4p|\n", 1234);
	   printf("|%9.4p|\n", 1234);
	ft_printf("|%#.0x|\n", 1234);
	   printf("|%#.0x|\n", 1234);
	
	ft_printf("%#10.5D\n", 89);
	printf("%#10.5D\n", 89);
	printf("%#10.5u\n", 89);
//	ft_printf("%#10.5n\n", 89);
//	printf("%#10.5n\n", 89);
	ft_printf("%#10.5d\n", 89);
	printf("%#10.5d\n", 89);
	ft_printf("%#10.5c\n", 89);
	printf("%#10.5c\n", 89);
	ft_printf("%#10.5i\n", 89);
	printf("%#10.5i\n", 89);
	ft_printf("%#10.5k\n", 89);
	printf("%#10.5k\n", 89);
	ft_printf("%#10.5o\n", 89);
	printf("%#10.5o\n", 89);
	ft_printf("%#10.5O\n", 89);
	printf("%#10.5O\n", 89);
	ft_printf("|%-12u|\n", 89);
	printf("|%-12u|\n", 89);
	ft_printf("|%.c|\n", 0);
	printf("|%.c|\n", 0);
	ft_printf("|%.5c|\n", 0);
	printf("|%.5c|\n", 0);
	ft_printf("|%.5c|\n", 42);
	printf("|%.5c|\n", 42);
	ft_printf("|%.C|\n", 0);
	printf("|%.C|\n", 0);
	ft_printf("|%.5C|\n", 0);
	printf("|%.5C|\n", 0);
	ft_printf("|%.5C|\n", 42);
	printf("|%.5C|\n", 42);

	ft_printf("toto%.0d et %+.i et  %   .0D !!!, 0, 0, 0");
	printf("toto%.0d et %+.i et  %   .0D !!!, 0, 0, 0");*/

//	ft_printf("\n======\n\n");
//	ft_printf("%2$*1$d\n", 50, 60); /*o: 50 spaces & 60%" */
//	   printf("%2$*1$d\n", 50, 60); /*o: 50 spaces & 60%" */
//	ft_printf("%1$*2$d\n", 50, 60); /*o: 50 spaces & 60%" */
//	   printf("%1$*2$d\n", 50, 60); /*o: 50 spaces & 60%" */
//	ft_printf("%1$*2$d\n", 50, 60); /*o: 60 spaces & 50%" */
//	   printf("%1$*2$d\n", 50, 60); /*o: 60 spaces & 50%" */
//	ft_printf("%1$ *2$d\n", 50, 60); /*o: 60 spaces & 50%" */
//	   printf("%1$ *2$d\n", 50, 60); /*o: 60 spaces & 50%" */
///	ft_printf("%1$d\n", 60); /* o: 60%" */
//	   printf("%1$d\n", 60); /* o: 60%" */
///	ft_printf("%1$*2$d\n", 60, 70); /* o: 60%" */
//	   printf("%1$*2$d\n", 60, 70); /* o: 60%" */
//	ft_printf("%1$.50d\n", 60); /* o: 50 "0" & 60%" */
//	   printf("%1$.50d\n", 60); /* o: 50 "0" & 60%" */
//	ft_printf("%1$d %1$d %1$d\n", 60); /*o: 60 60 60%" */
//	   printf("%1$d %1$d %1$d\n", 60); /*o: 60 60 60%" */
//	ft_printf("%1$d %$d %1$d\n", 60); /*w: invalid conversion specifier '$' */
//	  printf("%1$d %$d %1$d\n", 60); /*w: invalid conversion specifier '$' */
//	ft_printf("%1$d %2$d %1$d\n", 60); /*w: data arfument position '2' exceeds the number of data arfuments (1) */
//	   printf("%1$d %2$d %1$d\n", 60); /*w: data arfument position '2' exceeds the number of data arfuments (1) */
//	ft_printf("%1$050d %3$.50d %2$+d\n", 60, 70, 80); /*o: 60 70 80%*/
///	   printf("%1$050d %3$.50d %2$+d\n", 60, 70, 80); /*o: 60 70 80%*/
//	ft_printf("%1$d %3$d %2$d\n", 60, 70, 80); /*o: 60 80 70%*/
//	   printf("%1$d %3$d %2$d\n", 60, 70, 80); /*o: 60 80 70%*/
//	ft_printf("%3$d %1$d %2$d\n", 60, 70, 80); /*o: 80 60 70%*/
//	   printf("%3$d %1$d %2$d\n", 60, 70, 80); /*o: 80 60 70%*/
//	ft_printf("%3$d %.*d %1$d %2$d\n", 60, 70, 80); /*cannot mix positional and non-positional arfuments in format strinf*/
//	   printf("%3$d %.*d %1$d %2$d\n", 60, 70, 80); /*cannot mix positional and non-positional arfuments in format strinf*/
//	ft_printf("%3$.*d %1$d %2$d\n", 60, 70, 80); /*invalid position specified for field precision*/
//	   printf("%3$.*d %1$d %2$d\n", 60, 70, 80); /*invalid position specified for field precision*/
//	ft_printf("%3$*1$d %1$d %2$d\n", 60, 70, 80); /*o: 60 spaces & 80 60 70%*/
//	   printf("%3$*1$d %1$d %2$d\n", 60, 70, 80); /*o: 60 spaces & 80 60 70%*/
//	ft_printf("%3$*01$d %1$d %2$d\n", 60, 70, 80); /*o: 60 spaces & 80 60 70%*/
//	   printf("%3$*01$d %1$d %2$d\n", 60, 70, 80); /*o: 60 spaces & 80 60 70%*/
//	ft_printf("%3$*1$d %1$d %2$d %3$d\n", 60, 70, 80); /*w: format specifies type 'double' but the argument has type 'int'*/
//	   printf("%3$*1$d %1$d %2$d %3$d\n", 60, 70, 80); /*w: format specifies type 'double' but the argument has type 'int'*/
//	ft_printf("%3$*1$d %1$d %2$d %3$d\n", 60, 70, 80); /*w: 60 spaces & 80 60 70 80%*/
//	   printf("%3$*1$d %1$d %2$d %3$d\n", 60, 70, 80); /*w: 60 spaces & 80 60 70 80%*/
//	ft_printf("%3$*1$d %1$*2$d %2$*3$d %3$d\n", 60, 70, 80); /*w: 60 spaces & 80 - 70 spaces & 60 - 80 spaces & 70 - 80%*/
//	   printf("%3$*1$d %1$*2$d %2$*3$d %3$d\n", 60, 70, 80); /*w: 60 spaces & 80 - 70 spaces & 60 - 80 spaces & 70 - 80%*/
//	ft_printf("%3$*1$d %1$*2$d %2$*3$d %3$*1$d\n", 60, 70, 80); /*w: 60 spaces & 80 - 70 spaces & 60 - 80 spaces & 70 - 60 spaces & 80%*/
//	   printf("%3$*1$d %1$*2$d %2$*3$d %3$*1$d\n", 60, 70, 80); /*w: 60 spaces & 80 - 70 spaces & 60 - 80 spaces & 70 - 60 spaces & 80%*/
//	ft_printf("%3$*1$d %1$*2$d %2$*3$d %3$*1$d\n", 60, 70, 80); /*w: 60 spaces & 80 - 70 spaces & 60 - 80 spaces & 70 - 60 spaces & 80%*/
//	   printf("%3$*1$d %1$*2$d %2$*3$d %3$*1$d\n", 60, 70, 80); /*w: 60 spaces & 80 - 70 spaces & 60 - 80 spaces & 70 - 60 spaces & 80%*/
//	ft_printf("|%3$*1$.30d| |%1$*2$.70d| |%2$*3$.200d| |%3$*1$.70d|\n\n\n", 60, 70, 80); /*w: 10 spaces & 50 "0" & 80 - 70 "0" & 60 - 200 "0" & 70 - 70 "0" & 80%*/
//	   printf("|%3$*1$.30d| |%1$*2$.70d| |%2$*3$.200d| |%3$*1$.70d|\n\n", 60, 70, 80); /*w: 10 spaces & 50 "0" & 80 - 70 "0" & 60 - 200 "0" & 70 - 70 "0" & 80%*/

//	ft_printf("osef ! %#9llx et %#-12hhx\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
//	printf("osef ! %#9llx et %#-12hhx\n", (unsigned long long)-1248759650, (unsigned char)-1478223695);
	//printf("m%#.9od\\nee", 123456789);
//	printf("%0#14.0o!!\n", 12587499);
//	printf("%0#14.0o!!\n", 12587499);
//	printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
//	printf("t%04.2o%#2oet %#-8.3o titi\n", 0, 0, 0);
//	printf("titi%#012o, -874");
//	printf("coco et %-#-#--24O titi%#012o, 12, -874");
//	printf("|%#O|\n", 1000);
//	printf("|%.5p|\n", 0);
/*	ft_printf("|%9.2p|\n", 1234);
	printf("|%9.2p|\n", 1234);
	ft_printf("|%9.2p|\n", 1234567);
	printf("|%9.2p|\n", 1234567);
	ft_printf("|%2.9p|\n", 1234);
	printf("|%2.9p|\n", 1234);
	ft_printf("|%2.9p|\n", 1234567);
	printf("|%2.9p|\n", 1234567);*/
//	   printf("|%.0i|\n", 0);
//	ft_printf("|%-#5x|\n", 16);
//	   printf("|%-#5x|\n", 16);
//	ft_printf("|%.0i|\n", 0);
//	   printf("|%.0i|\n", 0);

}
