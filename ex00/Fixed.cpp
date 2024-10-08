/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:18:47 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/04 17:27:16 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "\e[0;32mDefault constructor called\e[0m" << std::endl;
	_FixedPoint_value = 0;
}

Fixed::Fixed(Fixed &Cpy)
{
	std::cout << "\e[0;32mCopy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &a)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m" << std::endl;
	_FixedPoint_value = a.getRawBits();
	return (*this);
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
