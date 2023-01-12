/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-o <jpedro-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:27:37 by jpedro-o          #+#    #+#             */
/*   Updated: 2023/01/12 15:31:25 by jpedro-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
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

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (0);
	i = -1;
	while (s1[++i])
		result[i] = (char)s1[i];
	j = -1;
	while (s2[++j])
	{
		result[i] = (char)s2[j];
		i++;
	}
	result[i] = '\0';
	return ((char *)result);
}
// int main()
// {
// 	char *ola="ola\ntudo";

// 	printf("%s", ft_strjoin("ola\ntudo", "ok\nman"));
// }