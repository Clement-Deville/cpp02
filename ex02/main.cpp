/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/08 19:11:10 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	// Fixed a(345.45f);
	// Fixed b(200.10f);

	Fixed a(-0.4f);
	Fixed b(-0.04f);

	std::cout << a << b << std::endl;
	std::cout <<"A * B = " << a * b << std::endl;
	std::cout << "B / A = " << b / a << std::endl;
		int	temp = (a / b).getRawBits();
	print_bit(4, &temp);
		temp = a.getRawBits();
	print_bit(4, &temp);
		temp = b.getRawBits();
	print_bit(4, &temp);

	char c = 20;

	short tmp = c * 14;
	print_bit(1, &tmp);
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
