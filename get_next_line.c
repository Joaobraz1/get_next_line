/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-o <jpedro-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:11:51 by jpedro-o          #+#    #+#             */
/*   Updated: 2023/01/13 15:44:09 by jpedro-o         ###   ########.fr       */
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
	printf("\nbuffer=%s\n",buff);
	if(BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		ft_cleaner(buff);
		return(NULL);
	}
	while(a > 0 && (buff[0] || read(fd, buff, BUFFER_SIZE)))
	{
		honey = ft_strjoin(honey, buff);
		b = -1;
		c = -1;
		while(buff[++b])
		{
			if(a < 0)
				buff[++c] = buff[b];
			if(buff[b] == '\n')
				a = -1;
			buff[b] ='\0';
		}
	}
	return (honey);
}

int main(int argc,char * args[])
{
	int	fd;
	int	i = 0;

	fd = open("42.txt",O_RDONLY);
	
	while(i < 11)
		printf("%d linha |%s|",(i++)+ 1, get_next_line(fd));
}