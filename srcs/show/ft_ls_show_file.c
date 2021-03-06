/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_show_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 00:08:14 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 00:13:01 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_show_file(t_list *elem)
{
	t_file *file;

	file = elem->content;
	if (!file->exists)
		return (ft_ls_errors_no_exists(file));
	file->ls->first_processed = 1;
	if (!file->ls->options.is_full_show)
		ft_putendl(file->name);
	else
	{
		ft_ls_show_rights(file);
		ft_ls_show_int(file->stat.st_nlink, file->sizes.nlink_spaces);
		ft_ls_show_str(file->owner, file->sizes.owner_spaces);
		if (!file->ls->options.skip_group)
			ft_ls_show_str(file->group, file->sizes.group_spaces);
		ft_ls_show_size(file);
		ft_ls_show_date(elem);
		ft_putstr(file->name);
		if (file->type == IS_LINK)
		{
			ft_putstr(" -> ");
			ft_putstr(file->lname);
		}
		ft_putstr("\n");
	}
}
