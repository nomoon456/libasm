/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbouju <elbouju@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:16:04 by elbouju           #+#    #+#             */
/*   Updated: 2020/06/16 20:26:40 by elbouju          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

extern	int	ft_strlen(char *str);
extern	char	*ft_strcpy(char *dest, const char *src);
extern	int	ft_strcmp(const char *s1, const char *s2);
extern	int	ft_write(int fd, char *str, size_t len);
extern	int	ft_read(int fd, char *str, size_t len);

void	test_strlen()
{
	printf("my strlen = {%d}\n", ft_strlen("Hello, World  123"));
	printf("real strlen = {%lu}\n", strlen("Hello, World  123"));

}

void	test_strcpy()
{
	printf("my strscpy = {%s}\n", ft_strcpy(strdup("1234567891011"), "Hello, World"));
	printf("real strscpy = {%s}\n", strcpy(strdup("1234567891011"), "Hello, World"));
}

void	test_strcmp()
{
	printf("with 12345 and 12345 test\n");
	printf("my strcmp = {%d}\n", ft_strcmp("12345", "12345"));
	printf("real strcmp = {%d}\n", strcmp("12345", "12345"));
	printf("with 12345 and 1234567 test\n");
	printf("my strcmp = {%d}\n", ft_strcmp("12345", "1234567"));
	printf("real strcmp = {%d}\n", strcmp("12345", "1234567"));
	printf("with 1234567 and 12345 test\n");
	printf("my strcmp = {%d}\n", ft_strcmp("1234567", "12345"));
	printf("real strcmp = {%d}\n", strcmp("1234567", "12345"));
}

void	test_write()
{
	printf(" = my write = {%d}\n", ft_write(1, " salut toi  1233", 5));
	printf(" = real write  = {%lu}\n", write(1, " salut toi  1233", 5));
}

void	test_read()
{
	int fd;
	int len = 15;
	char Vstr[len + 1];
	char Fstr[len + 1];
	
	fd = open("Makefile", O_RDONLY);
	ft_read(fd, Fstr, len);
	close(fd);
	fd = open("Makefile", O_RDONLY);
	read(fd, Vstr, len);
	close(fd);
	printf("my read = {%s}\n", Fstr);
	printf("real read = {%s}\n", Vstr);
}

int 	main(int ac, char **av)
{
	test_strlen();
	printf("\n");
	test_strcpy();
	printf("\n");
	test_strcmp();
	printf("\n");
	test_write();
	printf("\n");
	test_read();
}
