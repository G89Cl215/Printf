/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_t_pattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:25:27 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/12 15:39:41 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ul	ft_int_flag(void)
{

	return ((t_ul)1 << (TYPE_START - LMOD_START + ft_indice('i', KNOWN_CONV))
			| ((t_ul)1 << TYPE_START - LMOD_START + ft_indice('d', KNOWN_CONV)));
}
