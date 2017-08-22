/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_getters_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 23:43:40 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 14:29:19 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	get_nlink_size(t_list *elem)
{
	int		len;
	char	*str;
	t_file	*file;

	file = elem->content;
	str = ft_itoa(file->stat.st_nlink);
	len = ft_strlen(str);
	if (str)
		free(str);
	return (len);
}

int	get_group_size(t_list *elem)
{
	t_file *file;

	file = elem->content;
	return (ft_strlen(file->group));
}

int	get_owner_size(t_list *elem)
{
	t_file *file;

	file = elem->content;
	return (ft_strlen(file->owner));
}

int	get_minor_size(t_list *elem)
{
	int		len;
	char	*str;
	t_file	*file;

	file = elem->content;
	if (file->type == IS_CHAR || file->type == IS_BLOCK)
	{
		str = ft_itoa(file->minor);
		len = ft_strlen(str);
		if (str)
			free(str);
		return (len);
	}
	return (0);
}

int	get_major_size(t_list *elem)
{
	int		len;
	char	*str;
	t_file	*file;

	file = elem->content;
	if (file->type == IS_CHAR || file->type == IS_BLOCK)
	{
		str = ft_itoa(file->major);
		len = ft_strlen(str);
		if (str)
			free(str);
		return (len);
	}
	return (0);
}
