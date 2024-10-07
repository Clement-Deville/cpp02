/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedFixed::Operator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:55:23 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/04 17:55:39 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator > (const Fixed &a)
{
	return (this->getRawBits() > a.getRawBits() ? true : false);
}

bool Fixed::operator < (const Fixed &a)
{
	return (this->getRawBits() < a.getRawBits() ? true : false);
}

bool Fixed::operator >= (const Fixed &a)
{
	return (this->getRawBits() >= a.getRawBits() ? true : false);
}

bool Fixed::operator <= (const Fixed &a)
{
	return (this->getRawBits() <= a.getRawBits() ? true : false);
}

bool Fixed::operator == (const Fixed &a)
{
	return (this->getRawBits() == a.getRawBits() ? true : false);
}

bool Fixed::operator != (const Fixed &a)
{
	return (this->getRawBits() != a.getRawBits() ? true : false);
}


Fixed Fixed::operator + (const Fixed &a)
{
	return (Fixed(this->getRawBits() + a.getRawBits()));
}

Fixed Fixed::operator - (const Fixed &a)
{
	return (Fixed(this->getRawBits() + a.getRawBits()));
}
// Fixed Fixed::operator * (const Fixed &a)
// {
// 	// Fixed	a;
// 	// int		result;

// 	// result = (u_int64_t(this->_FixedPoint_value) << _bit_size * u_int64_t(a._FixedPoint_value) << _bit_size) >> _bit_size;
// 	// a.setRawBits(result);
// 	// return (a);
// 	Fixed tmp;

// 	tmp.setRawBits(u_int64_t((this->_FixedPoint_value) * u_int64_t(a._FixedPoint_value)) >> _bit_size);
// 	return (tmp);
// }

Fixed Fixed::operator * (const Fixed &a)
{
	// Fixed	a;
	// int		result;

	// result = (u_int64_t(this->_FixedPoint_value) << _bit_size * u_int64_t(a._FixedPoint_value) << _bit_size) >> _bit_size;
	// a.setRawBits(result);
	// return (a);
	Fixed tmp;

	tmp.setRawBits(((this->_FixedPoint_value) * (a._FixedPoint_value)) >> _bit_size);
	return (tmp);
}

Fixed Fixed::operator / (const Fixed &a)
{
	Fixed tmp;

	tmp.setRawBits(((int)(u_int64_t(this->_FixedPoint_value) / u_int64_t(a._FixedPoint_value))));
	return (tmp);
}
