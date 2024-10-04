/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/04 15:59:15 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// std::ostream & operator << (std::ostream &os, const Fixed &b)
// {
// 	// print_int(*this, this->_bit_size);
// 	(void)b;
// 	os << "test" << std::endl;
// 	return (os);
// }

// int	main( void )
// {
// 	Fixed a (356);
// 	Fixed const b( 0.00222 );
// 	Fixed c (356.7);
// 	// Fixed const c( 42.42f );
// 	// Fixed const d( b );
// 	// a = Fixed( 1234.4321f );
// 	// std::cout << "a is " << a << std::endl;
// 	// std::cout << b << std::endl;
// 	std::cout << "A:" << a;
// 	std::cout << "B:" << b;
// 	std::cout << "C:" << c;
// 	std::cout << "To int A:" << a.toInt() << std::endl;
// 	std::cout << "To int B:" << b.toInt() << std::endl;
// 	std::cout << "To int C:" << c.toInt() << std::endl;
// 	// std::cout << "c is " << c << std::endl;
// 	// std::cout << "d is " << d << std::endl;
// 	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	// std::cout << (float)3.0 << std::endl;
// 	return 0;
// }

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
