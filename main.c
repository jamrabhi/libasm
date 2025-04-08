/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:59:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2025/04/08 20:42:11 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024


size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);

int	main()
{
	printf("TEST FT_STRLEN\n");
	char *test = "Bonjour";
	printf("strlen(%s) = %lu\n", test, strlen(test));
	printf("ft_strlen(%s) = %lu\n\n", test, ft_strlen(test));

	printf("TEST FT_STRCPY\n");
	char dest[100] = "";
	printf("Before dest = \"%s\"\n", dest);
	ft_strcpy(dest, "bonjour");
	printf("After dest = \"%s\"\n\n", dest);
	
	printf("TEST FT_STRCMP\n");
	char *str1 = "bonjouR";
	char *str2 = "bonjour";
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str2, strcmp(str1, str2));
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n\n", str1, str2, ft_strcmp(str1, str2));

	printf("TEST FT_WRITE\n");
	char *hello = "Hello\n";
	// Cas normal
	errno = 0;
	ssize_t ret = write(1, hello, 6);
	printf("ret write = %zd, errno = %d (%s)\n", ret, errno, strerror(errno));
	errno = 0;
	ret = ft_write(1, hello, 6);
	printf("ret ft_write = %zd, errno = %d (%s)\n", ret, errno, strerror(errno));
	errno = 0;
	// Cas d'erreur : fd invalide
	ret = write(-1, hello, 6);
	printf("ret write = %zd, errno = %d (%s)\n", ret, errno, strerror(errno));
	errno = 0;
	ret = ft_write(-1, hello, 6);
	printf("ret ft_write = %zd, errno = %d (%s)\n\n", ret, errno, strerror(errno));
	

	printf("TEST FT_READ\n");
	char buffer[128];
	ssize_t bytes_read;
	// Cas normal : lire depuis stdin
	printf("Lecture depuis stdin ...\n");
	bytes_read = ft_read(0, buffer, sizeof(buffer)-1);
	if (bytes_read >= 0) {
		buffer[bytes_read] = '\0';  // Terminer la chaîne
		printf("ft_read : %zd bytes read, buffer = \"%s\"\n", bytes_read, buffer);
	}
	else
		printf("ft_read failed with errno = %d (%s)\n", errno, strerror(errno));
	// Cas d'erreur : fd invalide
	bytes_read = ft_read(-1, buffer, sizeof(buffer)-1);
	printf("ft_read : %zd bytes read, errno = %d (%s)\n", bytes_read, errno, strerror(errno));
	
	return (0);
}
