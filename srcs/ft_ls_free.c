/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 01:05:53 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 01:06:00 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_free_file(void *content, size_t content_size)
{
	t_file *file;

	file = content;
	ft_ls_free_file_one(file);
	content_size = 0;
}

void	ft_ls_free_file_one(t_file *file)
{
	if (!file)
		return ;
	if (file->name)
		free(file->name);
	if (file->path)
		free(file->path);
	if (file->owner)
		free(file->owner);
	if (file->group)
		free(file->group);
	if (file->type == IS_LINK && file->lname)
		free(file->lname);
	if (file)
		free(file);
}
