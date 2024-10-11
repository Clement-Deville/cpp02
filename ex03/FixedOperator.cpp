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

/*	Comparaison operator */

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


/*	Operation operator */


Fixed Fixed::operator + (const Fixed &a)
{
	return (Fixed(this->getRawBits() + a.getRawBits()));
}

Fixed &Fixed::operator += (const Fixed &a)
{
	this->setRawBits(this->getRawBits() + a.getRawBits());
	return (*this);
}

Fixed Fixed::operator - (const Fixed &a)
{
	return (Fixed(this->getRawBits() - a.getRawBits()));
}

Fixed &Fixed::operator -= (const Fixed &a)
{
	this->setRawBits(this->getRawBits() - a.getRawBits());
	return (*this);
}

/*	Utile pour debug le binaire */

void	print_bit(size_t size, const void *value)
{
	for (int i = (signed long)size * 8 - 1; i >= 0 ; i--)
	{
		if (i == 7)
			std::cout << ".";
		std::cout << ((*(u_int64_t*)value >> i) & 1) ;
	}
	std::cout << std::endl;
}

/*	Ici, on caste dans un u_int64_t pour eviter overflow du a l'upscale d'une multiplication

	Explications : http://www.coranac.com/tonc/text/fixed.htm */

Fixed Fixed::operator * (const Fixed &a)
{
	Fixed tmp;

	tmp.setRawBits(u_int64_t((this->_FixedPoint_value) * u_int64_t(a._FixedPoint_value)) >> _bit_size);
	return (tmp);
}

Fixed &Fixed::operator *= (const Fixed &a)
{
	this->setRawBits(u_int64_t((this->_FixedPoint_value) * u_int64_t(a._FixedPoint_value)) >> _bit_size);
	return (*this);
}

/*	Ici, on caste dans un u_int64_t pour pouvoir upscale notre nombre de
	_bit_size bits pour eviter underflow du a l'underscale d'une division
	Explications : http://www.coranac.com/tonc/text/fixed.htm */

Fixed Fixed::operator / (const Fixed &a)
{
	Fixed tmp;

	u_int64_t temp_int = u_int64_t(this->getRawBits()) << _bit_size;
	temp_int /= u_int64_t(a.getRawBits());
	tmp.setRawBits((int)temp_int);
	return (tmp);
}

Fixed &Fixed::operator /= (const Fixed &a)
{
	u_int64_t temp_int = u_int64_t(this->getRawBits()) << _bit_size;
	temp_int /= u_int64_t(a.getRawBits());
	this->setRawBits((int)temp_int);
	return (*this);
}

/*  */

/************************************************************/
/* 				INCREMENT/DECREMENT OPERATOR 				*/
/************************************************************/

	Fixed	&Fixed::operator ++ (void)
	{
		this->setRawBits(this->getRawBits() + 1);
		return (*this);
	}

	Fixed	Fixed::operator ++ (int)
	{
		Fixed	tmp;

		tmp.setRawBits(this->getRawBits());
		this->setRawBits(this->getRawBits() + 1);
		return (tmp);
	}

	Fixed	&Fixed::operator -- (void)
	{
		this->setRawBits(this->getRawBits() - 1);
		return (*this);
	}

	Fixed	Fixed::operator -- (int)
	{
		Fixed	tmp;

		tmp.setRawBits(this->getRawBits());
		this->setRawBits(this->getRawBits() - 1);
		return (tmp);
	}


