/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conv_tools.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:26:30 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 14:29:31 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_TOOLS_H
# define FLOAT_TOOLS_H


void	ft_strsum_dec(char *str, char *to_add);
void	ft_strdiv_2(char *str);
char	*ft_trim_0(char *str, int s);
char	*ft_create_float(t_ul mant, int mant_length);
int		ft_reajust_zero(char *str);

#endif
