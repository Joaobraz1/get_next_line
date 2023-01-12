/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-o <jpedro-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:27:37 by jpedro-o          #+#    #+#             */
/*   Updated: 2023/01/12 16:58:56 by jpedro-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_cleaner(char *value)
{
	int	i;

	i = -1;
	while(value[++i])
		value[i] = 0;
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	int		l1;
	int		l2;

	if(!s2)
		return(NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = malloc((l1 + l2 + 1) * sizeof(char));
	if(!result)
		return (NULL);
	i = -1;
	while(++i < l1)
		result[i] = (char)s1[i];
	j = -1;
	while(s2[++j])
		result[i++] = (char)s2[j];
	result[i] = '\0';
	free((void *)s1);
	return ((char *)result);
}
