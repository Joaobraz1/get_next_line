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
	int			a;
	int			b;
	int			c;
	static char	buff[BUFFER_SIZE + 1];
	char		*honey;

	honey = NULL;
	a = 1;
	if(BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return(0);
	while(a > 0 && read(fd, buff, BUFFER_SIZE))
	{
		printf("\nbuff: |%s|\n", buff);
		honey = ft_strjoin(honey, buff);
		printf("\nhoney: |%s|\n", honey);
		b = -1;
		c = -1;
		while(buff[++b])
		{
			if(a < 0)
			{
				buff[++c] = buff[b];
			}
			if(buff[b] == '\n')
				a = -1;
		}
		buff[b] ='\0';
	}
	printf("\nbuff: |%s|\n", buff);
	return (honey);
}

int main(int argc,char * args[])
{
	int	fd;

	fd = open("42.txt",O_RDONLY);
	
	printf("\nprimeiro|%s|\n", get_next_line(fd));
	printf(" \nsegundo|%s|\n", get_next_line(fd));
}