/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:18:47 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/03 16:43:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "\e[0;32mDefault constructor called\e[0m" << std::endl;
	_FixedPoint_value = 0;
}

Fixed::Fixed(const int nb)
{
	this->_FixedPoint_value = nb << this->_bit_size;
}

Fixed::Fixed(const float f_nb)
{
	int	real;
	float	cpy;

	cpy = f_nb;
	real = f_nb;
	this->_FixedPoint_value = real << this->_bit_size;
	// this->_FixedPoint_value += (int)(std::roundf((float)std::modf(cpy, &cpy)))
	// 	<< (sizeof(int) * 8 - this->_bit_size) >> (sizeof(int) * 8 - this->_bit_size);
}

Fixed::Fixed(const Fixed &Cpy)
{
	std::cout << "\e[0;32mCopy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

float	get_real(Fixed a, int b_size)
{
	float	number;

	// number = 0;
	// (void)b_size;
	// for (int x = 0; x < ((int)(sizeof(int) * 8)) - b_size - 1; x++)
	// {
	// 	// number += (a.getRawBits() << (x + 8)) * std::pow(2, x);
	// 	number+= ((a.getRawBits() & ( 1 << x )) >> x) * std::pow(2, x);
	// }
	number = (a.getRawBits()) >> b_size;
	std::cout << number << std::endl;
	return (number);
}

float	get_deci(Fixed a, int b_size)
{
	float	deci;

	deci = (a.getRawBits()) << ((sizeof(int)* 8) - b_size) >> b_size;
	std::cout << deci << std::endl;
	return (deci);
}

float Fixed::toFloat( void ) const
{
	float	number;

	number = get_real(*this, this->_bit_size) + get_deci(*this, this->_bit_size);
	return (number);
}

// int Fixed::toInt( void ) const
// {

// }

Fixed &Fixed::operator=(const Fixed &a)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m" << std::endl;
	_FixedPoint_value = a.getRawBits();
	return (*this);
}

std::ostream & operator << (std::ostream &os, const Fixed &b)
{
	os << b.toFloat() << std::endl;
	return (os);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "\e[0;34mgetRawBits member function called\e[0m" << std::endl;
	return (_FixedPoint_value);
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "\e[0;34msetRawBits member function called\e[0m" << std::endl;
	_FixedPoint_value = raw;
}
