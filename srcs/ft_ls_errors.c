/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amittal <amittal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 21:18:47 by amittal           #+#    #+#             */
/*   Updated: 2017/08/21 00:13:27 by amittal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_wrong_option(char option)
{
	ft_putstr_fd("ls: illegal option -- ", 2)
	ft_putchar_fd(option, 2);
	ft_putchar_fd('\n', 2);
	ft_ls_errors_usage();
	exit(1);
}

void	ft_ls_errors_no_exists(t_file *file)
{
	ft_putstr_fd("ls: ", 2);
	if (file->name[0] == '\0')
		ft_putstr_fd("fts_open", 2);
	else
		ft_putstr_fd(file->name, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	if (file->name[0] == '\0')
		exit(1);
}

void	ft_ls_errors_no_permission(t_file *file)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file->name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(file->err), 2);
}

void	ft_ls_errors_usage(void)
{
	ft_putstr_fd("usage: ls [-RUaglrtu1] [file ...]", 2);
	ft_putchar_fd('\n', 2);
}