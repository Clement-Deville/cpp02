/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/03 17:14:12 by cdeville         ###   ########.fr       */
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

int	main( void )
{
	Fixed a (356);
	Fixed const b( 10 );
	// Fixed const c( 42.42f );
	// Fixed const d( b );
	// a = Fixed( 1234.4321f );
	// std::cout << "a is " << a << std::endl;
	// std::cout << b << std::endl;
	std::cout << "A:" << a;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	u_char test;

	test = 4231;
	std::cout << "Unsinged Char overflow test: " << (int)test << std::endl;
	std::cout << (float)3.0 << std::endl;
	return 0;
}
