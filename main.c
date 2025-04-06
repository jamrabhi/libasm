/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:59:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2025/04/06 16:34:51 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);

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

    return (0);
}
