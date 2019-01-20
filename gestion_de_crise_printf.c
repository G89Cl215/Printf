/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:20:08 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 16:51:10 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_error(int flag, t_list **buff, t_list **conv,
														t_pattern **pattern)
{
	ft_free_pattern(pattern);
	ft_lstfree(buff);
	ft_lstfree(conv);
	if (flag == 0)
		ft_putendl("error : mix of postionnal & non-positionnal flags.");
	if (flag == 1)
		ft_putendl("error : wrong call of arguments.");
	if (flag == 2)
		ft_putendl("error : conflicting conversion types.");
	return (0);
}
