/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                     +:+ +:+         +:+     */
/*   By: jpedro-o <joaobraz1204@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:11:51 by jpedro-o          #+#    #+#             */
/*   Updated: 2022/03/13 13:40:01 by jpedro-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int	i;
	int 		aux;
	char 		*value;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = -1;
	if(!(value = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return(NULL);
	while (aux = read(fd,value[i + 1], 1) && value[i + 1] != '\n' || value[i + 1] != '\0')
		i++;
	value[i] ='\0';
	ret = malloc(sizeof(char) * (ft_strlen(value) + 1));
	ret[ft_strlcpy(ret, value, ft_strlen(value))] = '\0';
	return(ret);
}

int main(int argc,char * args[])
{
	int	fd;

	fd = open("42",O_RDONLY);
	
	printf("%s", get_next_line(fd));
}