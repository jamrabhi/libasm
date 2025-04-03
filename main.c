/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:59:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2025/04/03 19:35:19 by jamrabhi         ###   ########.fr       */
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
	printf("strlen(%s) = %zu\n", test, strlen(test));
	printf("ft_strlen(%s) = %zu\n", test, fr_strlen(test));

	char *str1 = NULL;
	char *str2 = NULL;
	printf("TEST FT_STRCPY\n");
	printf("strcpy(%s,%s) = %s\n", test, str1, strcpy(test, str1));
	printf("strcpy(%s,%s) = %s\n", test, str2, strcpy(test, str2));

    return (0);
}
