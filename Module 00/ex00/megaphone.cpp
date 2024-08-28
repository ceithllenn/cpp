/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvallet <elvallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:23:14 by elvallet          #+#    #+#             */
/*   Updated: 2024/08/28 08:46:32 by elvallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		while (argc > 1 && argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)std::toupper(argv[i][j]);
				j++;
			}
			argc--;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
