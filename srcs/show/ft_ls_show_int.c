/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_show_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 00:29:23 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 00:34:12 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_show_int(int value, int max_space)
{
	int		spaces;
	int		len;
	char	*str;

	str = ft_itoa(value);
	len = ft_strlen(str);
	if (str)
		free(str);
	spaces = max_space - len;
	while (spaces-- > 0)
		ft_putchar(' ');
	ft_putnbr(value);
	ft_putstr(" ");
}
