/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:55:01 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/16 14:55:10 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

char	*ft_strcpy(char *dest, char *src);
char	*ft_ncpy(char *dest, char *src, unsigned int size);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_ncmp(char *s1, char *s2, unsigned int n);

#endif
