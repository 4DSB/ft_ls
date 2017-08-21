/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_show_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 00:39:21 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 00:39:29 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_ls_show_size_get(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (str)
		free(str);
	return (len);
}

void	ft_ls_show_size(t_file *file)
{
	int		minor_spaces;
	int		major_spaces;

	minor_spaces = ft_ls_show_size_get(file->minor);
	major_spaces = ft_ls_show_size_get(file->major);
	if (file->type == IS_CHAR || file->type == IS_BLOCK)
	{
		ft_putchar(' ');
		while (major_spaces < file->sizes.major_spaces--)
			ft_putchar(' ');
		ft_putnbr(file->major);
		ft_putstr(", ");
		while (minor_spaces < file->sizes.minor_spaces--)
			ft_putchar(' ');
		ft_putnbr(file->minor);
		ft_putchar(' ');
	}
	else
	{
		if ((file->sizes.minor_spaces > 0 || file->sizes.major_spaces > 0))
			ft_ls_show_int(file->stat.st_size,
				file->sizes.minor_spaces + file->sizes.major_spaces + 3);
		else
			ft_ls_show_int(file->stat.st_size, file->sizes.size_spaces);
	}
}
