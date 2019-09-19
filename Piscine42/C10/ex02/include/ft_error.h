/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:45:31 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/16 14:45:34 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

int		error(char *program, char *filename);
int		error_message(char *program, char *message);
int		illegal_offset(char *program, char *offset);
int		usage_info(char *program);

#endif
