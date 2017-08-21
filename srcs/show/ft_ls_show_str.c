/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_show_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 00:37:08 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 00:37:15 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_show_str(char *str, int max_space)
{
	int		spaces;

	spaces = max_space - ft_strlen(str);
	ft_putstr(str);
	while (spaces-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}
