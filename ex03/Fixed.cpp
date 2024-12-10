/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:18:47 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/10 11:46:55 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/************************************************************/
/* 					CONSTRUCTORS/DESTRUCTORS				*/
/************************************************************/
Fixed::Fixed()
{
	// std::cout << "\e[0;32mDefault constructor called\e[0m" << std::endl;
	_FixedPoint_value = 0;
}

Fixed::Fixed(const int nb)
{
	// std::cout << "\e[0;32mInt constructor called\e[0m" << std::endl;
	this->_FixedPoint_value = nb << this->_bit_size;
}

Fixed::Fixed(const float f_nb)
{
	// std::cout << "\e[0;32mFloat constructor called\e[0m" << std::endl;
	_FixedPoint_value = (int)(f_nb * float(1 << _bit_size) + (f_nb >= 0 ? 0.5 : -0.5));
}

Fixed::Fixed(const Fixed &Cpy)
{
	// std::cout << "\e[0;32mCopy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Fixed::~Fixed()
{
	// std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

/* OPERATORS */

Fixed &Fixed::operator=(const Fixed &a)
{
	// std::cout << "\e[0;32mCopy assignement operator called\e[0m"
		// << std::endl;
	_FixedPoint_value = a._FixedPoint_value;
	return (*this);
}

std::ostream & operator << (std::ostream &os, const Fixed &b)
{
	os << b.toFloat();
	return (os);
}

/************************************************************/
/* 					STATIC FUNCTIONS 						*/
/************************************************************/

/*	Takes as parameters two references to fixed-point numbers, and returns a reference to the smallest one, if they
	are equals, returns the first one */

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits() ? a : b);
}

/*	Takes as parameters two references to constant fixed-point numbers,
	and returns a reference to the smallest one, if theyare equals,
	returns the first one */

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits() ? a : b);
}

/*	Takes as parameters two references to fixed-point numbers,
	and returns a reference to the smallest one, if they
	are equals, returns the first one */

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits() ? a : b);
}

/*	Takes as parameters two references to constant
	fixed-point numbers, and returns a reference to the smallest one,
	if they are equals, returns the first one */

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits() ? a : b);
}

/************************************************************/
/* 					FUNCTIONS 								*/
/************************************************************/

int	Fixed::getRawBits( void ) const
{
	// std::cout << "\e[0;34mgetRawBits member function called\e[0m" << std::endl;
	return (_FixedPoint_value);
}
void Fixed::setRawBits( int const raw )
{
	// std::cout << "\e[0;34msetRawBits member function called\e[0m" << std::endl;
	_FixedPoint_value = raw;
}

int Fixed::toInt( void ) const
{
	return (roundf(toFloat()));
}

float Fixed::toFloat( void ) const
{
	return (float(_FixedPoint_value) / float(1 <<_bit_size));
}

/*	Comparaison operator */

bool Fixed::operator > (const Fixed &a) const
{
	return (this->getRawBits() > a.getRawBits() ? true : false);
}

bool Fixed::operator < (const Fixed &a) const
{
	return (this->getRawBits() < a.getRawBits() ? true : false);
}

bool Fixed::operator >= (const Fixed &a) const
{
	return (this->getRawBits() >= a.getRawBits() ? true : false);
}

bool Fixed::operator <= (const Fixed &a) const
{
	return (this->getRawBits() <= a.getRawBits() ? true : false);
}

bool Fixed::operator == (const Fixed &a) const
{
	return (this->getRawBits() == a.getRawBits() ? true : false);
}

bool Fixed::operator != (const Fixed &a) const
{
	return (this->getRawBits() != a.getRawBits() ? true : false);
}


/*	Operation operator */


Fixed Fixed::operator + (const Fixed &a) const
{
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() + a.getRawBits());
	return (tmp);
}

Fixed &Fixed::operator += (const Fixed &a)
{
	this->setRawBits(this->getRawBits() + a.getRawBits());
	return (*this);
}

Fixed Fixed::operator - (const Fixed &a) const
{
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() - a.getRawBits());
	return (tmp);
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

Fixed Fixed::operator * (const Fixed &a) const
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

Fixed Fixed::operator / (const Fixed &a) const
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
