/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:23:40 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 14:26:02 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_2_pow[54] =
{
	"1.\0",
	"0.5\0",
	"0.25\0",
	"0.125\0",
	"0.0625\0",
	"0.03125\0",
	"0.015625\0",
	"0.0078125\0",
	"0.00390625\0",
	"0.001953125\0",
	"0.0009765625\0",
	"0.00048828125\0",
	"0.000244140625\0",
	"0.0001220703125\0",
	"0.00006103515625\0",
	"0.000030517578125\0",
	"0.0000152587890625\0",
	"0.00000762939453125\0",
	"0.000003814697265625\0",
	"0.0000019073486328125\0",
	"0.00000095367431640625\0",
	"0.000000476837158203125\0",
	"0.0000002384185791015625\0",
	"0.00000011920928955078125\0",
	"0.000000059604644775390625\0",
	"0.0000000298023223876953125\0",
	"0.00000001490116119384765625\0",
	"0.000000007450580596923828125\0",
	"0.0000000037252902984619140625\0",
	"0.00000000186264514923095703125\0",
	"0.000000000931322574615478515625\0",
	"0.0000000004656612873077392578125\0",
	"0.00000000023283064365386962890625\0",
	"0.000000000116415321826934814453125\0",
	"0.0000000000582076609134674072265625\0",
	"0.00000000002910383045673370361328125\0",
	"0.000000000014551915228366851806640625\0",
	"0.0000000000072759576141834259033203125\0",
	"0.00000000000363797880709171295166015625\0",
	"0.000000000001818989403545856475830078125\0",
	"0.0000000000009094947017729282379150390625\0",
	"0.00000000000045474735088646411895751953125\0",
	"0.000000000000227373675443232059478759765625\0",
	"0.0000000000001136868377216160297393798828125\0",
	"0.00000000000005684341886080801486968994140625\0",
	"0.000000000000028421709430404007434844970703125\0",
	"0.0000000000000142108547152020037174224853515625\0",
	"0.00000000000000710542735760100185871124267578125\0",
	"0.000000000000003552713678800500929355621337890625\0",
	"0.0000000000000017763568394002504646778106689453125\0",
	"0.00000000000000088817841970012523233890533447265625\0",
	"0.000000000000000444089209850062616169452667236328125\0",
	"0.0000000000000002220446049250313080847263336181640625\0",
	"0.00000000000000011102230246251565404236316680908203125\0",
};

void	ft_strsum_dec(char *str, char *to_add)
{
	int		ret;
	int		point_str;
	int		point_to_add;
	int		i;

	point_str = ft_indice('.', str);
	point_to_add = ft_indice('.', to_add);
	i = ft_strlen(to_add) - point_to_add - 1;
	ret = 0;
	while (i > 0)
	{
		ret += str[point_str + i] + to_add[point_to_add + i] - 2 * '0'; 
		str[point_str + i] = (ret % 10) + '0';
		ret = (ret > 9 ? 1 : 0);
		i--;
	}
	i = point_to_add - 1;
	while (i >= 0)
	{
		ret += str[--point_str] + to_add[i--] - 2 * '0'; 
		str[point_str] = (ret % 10) + '0';
		ret = (ret > 9 ? 1 : 0);
	}
	if (ret)
		str[--point_str] = ret % 10 + '0';
}

void	ft_strdiv_2(char *str)
{
	int		i;
	int		len;
	int		ret;
	int		div;

	i = 0;
	len = ft_strlen(str);
	ret = 0;
	while ((str[i] == '0' || str[i] == '.') && i < len)
		i++;
	while (i < len)
	{
		if (str[i] != '.')
		{
			div = str[i] - '0';
			str[i] = div / 2 + ret + '0';
			ret = div % 2 ? 5 : 0;
		}
		i++;
	}
}

void	ft_trim_0(char *str, int s)
{
	int i;

	i = ft_strspn(str, "0");
	if (str[i] == '.')
		i--;
	if (s)
		i--;
	if (i > 0)
		ft_memmove(str, str + i, ft_strlen(str + i) + 1);
	if (s)
		str[0] = '-';
}

char	*ft_create_float(t_ul mant, int mant_length)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(620)))
		return (NULL);
	ft_memset(str, '0', 619);
	str[309] = '.';
	while (i <= mant_length)
	{
		if (((t_ul)1 << i) & mant)
			ft_strsum_dec(str, g_2_pow[mant_length - i - 1]);
		i++;
	}
	return (str);
}

/* Cette fonction renvoie l'exposant en notation scientifique 
 * et travaille sur le float contenu dans le char* pour le ramener 
 * en notation scientifique */

int		ft_reajust_zero(char *str)
{
	int		i;
	int		j;
	int		s;

	i = ft_strspn(str, "0");
	s = (str[i] == '.' ? -1 : 1);
	if (s > 0)
	{
		j = ft_indice('.', str);
		if (j != 1)
		{
			ft_memmove(str + j, str + j + 1, ft_strlen(str) - j);
			ft_memmove(str + i + 1, str + i, ft_strlen(str + i));
			str[i + 1] = '.';
		}
		j -= i + 1;
	}
	else
	{
		j = i + ft_strspn(str + i + 1, "0") + 1;
		str[0] = str[j];
		str[1] = '.';
		ft_memmove(str + 2, str + j + 1, ft_strlen(str + j));
		j--;
	}
	return (s * j);
}

/* Gestion du decoupage "a droite" des floats */

void	ft_prec_float(char *str, int prec)
{
	int point_str;
	int ret;

	if (prec < 0) // peut il y avoir une prec de zero ?
		prec = 6;
	point_str = ft_indice('.', str);
	ret = (str[point_str + prec + 1] - '0' > 4);
	str[point_str + prec + 1] = '\0';
	while (ret)
	{
		ret += str[point_str + prec] - '0'; 
		str[point_str + prec] = (ret % 10) + '0';
		ret = (ret > 9 ? 1 : 0);
		prec--;
	}
}
/*
void	ft_prec_float(char *str, int prec)
{
	int point_str;
	int exp_str;
	int ret;

	if (prec < 0) // peut il y avoir une prec de zero ?
		prec = 6;
	if ((exp_str = ft_indice('e', str)) == ft_strlen(str))
		exp_str = ft_indice('E', str);
	ret = (str[point_str + prec + 1] - '0' > 4);
	str[point_str + prec + 1] = '\0';
	while (ret)
	{
		ret += str[point_str + prec] - '0'; 
		str[point_str + prec] = (ret % 10) + '0';
		ret = (ret > 9 ? 1 : 0);
		prec--;
	}
}*/




// FOR TESTS

void	ft_putllnbr(long n)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putllnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int main()
{
	char			*str;
	double			f = 10000000000000000;
	u_float			u;
	t_ul			s;
	long			exp;
	int				i;
	t_ul			mant;
	char			*pow_10;

	pow_10 = ft_strnew(5);
	pow_10[0] = 'e';
	pow_10[1] = '\0';
	u.d = f;
	s = (((t_ul)1 << 63) & u.l) ? 1 : 0;
	mant = ((((t_ul)1 << 53) - 1) & u.l);
/*	ft_putllnbr(mant);
	ft_putchar('\n');*/
	exp = ((long)2047 & (u.l >> 52)) - 1023;
	mant |= ((t_ul)1 << 52); // conditions de denormalisation d'un double ????
	
	str = ft_create_float(mant, 53);
//	ft_putendl(str);
	while (exp)
		{
			if (exp > 0)
			{
				ft_strsum_dec(str, str);
				exp--;
			}
			if (exp < 0)
			{
				ft_strdiv_2(str);
				exp++;
			}
		}

	ft_trim_0(str, 0);
	ft_putendl(str);
//	ft_putnbr(ft_strlen(str));
	i = ft_reajust_zero(str);
	pow_10 = ft_strcat(pow_10, ft_itoa(i));
	str = ft_strcat(str, pow_10);

/*	ft_prec_float(str, 15);
	ft_putllnbr(exp);
	ft_putchar('\n');
	
	ft_putendl(str);
	ft_putnbr(ft_reajust_zero(str));
	ft_putchar('\n');
	ft_putendl(str);
	ft_trim_0(str, 1);
	*/
	ft_putendl(str);
	ft_putnbr(ft_strlen(str));

	return (0);
}
