/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/10 11:42:29 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(-8388608);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	int test = -2147483647;
	test = test << 8 >> 8;

	int x = -1;
	float y = x;

	if (b > a)
		std::cout << "a < b" << std::endl;
	std::cout << "new x: " << x << std::endl;
	std::cout << "new y: " << y << std::endl;


	std::cout << "test:" << test << "\na:" << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a / b) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout <<
	"\n/**========================================================================\n" <<
	 "*                           Subject main\n" <<
	 "*========================================================================**/\n"
	 << std::flush;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	return (0);
}
