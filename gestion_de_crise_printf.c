/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:20:08 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/10 19:00:05 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_error(int flag, t_list **buff, t_list **pattern)
{
	ft_lstfree(pattern);
	ft_lstfree(buff);
	if (flag == 0)
		ft_putendl("error : mix of postionnal & non-positionnal flags");
	return (0);
}
