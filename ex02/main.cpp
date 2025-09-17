/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2025/09/17 14:53:13 by cdeville         ###   ########.fr       */
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

	Fixed c(20);
	Fixed d(-2.2f);

	std::cout << "\n";
	std::cout << " C: " << c << ": should be 20." << std::endl;
	std::cout << " D: " << d << ": should be -2.2." << std::endl;

	std::cout << "c / d = " << c / d << ": should be around :" << (20 / -2.2) << std::endl;

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
