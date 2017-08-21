/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_getters_types.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 23:43:58 by amittal           #+#    #+#             */
/*   Updated: 2017/08/20 23:45:21 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	*get_name(t_list *elem)
{
	t_file *file;

	file = elem->content;
	return (file->name);
}

void	*get_time(t_list *elem)
{
	t_file *file;

	file = elem->content;
	if (file->ls->options.time_last_access)
		return (&file->stat.st_atime);
	else if (file->ls->options.time_creation)
		return (&file->stat.st_ctime);
	return (&file->stat.st_mtime);
}

void	*get_time_nano(t_list *elem)
{
	t_file *file;

	file = elem->content;
	if (file->ls->options.time_last_access)
		return (&file->stat.st_atimespec.tv_nsec);
	else if (file->ls->options.time_creation)
		return (&file->stat.st_ctimespec.tv_nsec);
	return (&file->stat.st_mtimespec.tv_nsec);
}

void	*get_elem(t_list *elem)
{
	return (elem);
}

int		get_size(t_list *elem)
{
	t_file	*file;
	int		len;
	char	*str;

	file = elem->content;
	if (file->type != IS_CHAR && file->type != IS_BLOCK)
	{
		str = ft_itoa(file->stat.st_size);
		len = ft_strlen(str);
		if (str)
			free(str);
		return (len);
	}
	return (0);
}
