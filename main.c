/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:59:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2025/04/07 18:47:28 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

int main()
{
	char *test = "Bonjour";
	printf("TEST FT_STRLEN\n");
	printf("strlen(%s) = %lu\n", test, strlen(test));
	printf("ft_strlen(%s) = %lu\n", test, ft_strlen(test));

	char dest[100] = "";
	printf("TEST FT_STRCPY\n");
	printf("Before dest = \"%s\"\n", dest);
	ft_strcpy(dest, "bonjour");
	printf("After dest = \"%s\"\n", dest);
	
	char *str1 = "bonjouR";
	char *str2 = "bonjour";
	printf("TEST FT_STRCMP\n");
	printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str2, strcmp(str1, str2));
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str2, ft_strcmp(str1, str2));

    return (0);
}
