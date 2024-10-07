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

	std::cout << "This:     ";
	print_bit(sizeof(int), &this->_FixedPoint_value);
	std::cout << "A:        ";
	print_bit(sizeof(int), &a._FixedPoint_value);
	tmp.setRawBits(((this->_FixedPoint_value) * (a._FixedPoint_value)) >> _bit_size);
	int temp = tmp.getRawBits();
	std::cout << "This * A: ";
	print_bit(sizeof(int), &temp);
	return (tmp);
}

Fixed Fixed::operator / (const Fixed &a)
{
	Fixed tmp;

	u_int64_t temp_int = u_int64_t(this->getRawBits()) << 16;
	temp_int = u_int64_t(this->getRawBits()) << 16;
	temp_int /= u_int64_t(a.getRawBits());
	temp_int = temp_int >> 8;
	tmp.setRawBits((int)temp_int);
	return (tmp);
}

// Fixed Fixed::operator / (const Fixed &a)
// {
// 	Fixed tmp;

// 	int test = this->getRawBits() << 16;
// 	u_int64_t btest = u_int64_t(test);
// 	print_bit(4, &test);
// 	std::cout << "btest a: " << btest << std::endl;
// 	std::cout << *this << std::endl;
// 	print_bit(sizeof(u_int64_t), &btest);
// 	test = a.getRawBits();
// 	print_bit(4, &test);
// 	std::cout << test << std::endl;
// 	std::cout << a << std::endl;
// 	btest = u_int64_t(test);
// 	print_bit(sizeof(u_int64_t), &btest);
// 	std::cout << "btest a: " << btest << std::endl;
// 	// tmp.setRawBits(((int)(((u_int64_t(this->_FixedPoint_value) << 16) / u_int64_t(a._FixedPoint_value)))));

// 	u_int64_t temp = u_int64_t(this->getRawBits()) << 16;
// 	std::cout << "First assign:";
// 	print_bit(8, &temp);
// 	std::cout << temp << std::endl;
// 	temp = u_int64_t(a.getRawBits());
// 	std::cout << "A assign:";
// 	print_bit(8, &temp);
// 	std::cout << temp << std::endl;
// 	temp = u_int64_t(this->getRawBits()) << 16;
// 	temp /= u_int64_t(a.getRawBits());
// 	std::cout << "Division before bitshift: ";
// 	print_bit(8, &temp);
// 	std::cout << temp << std::endl;
// 	temp = temp >> 16;
// 	std::cout << "Division after bitshift: ";
// 	print_bit(8, &temp);
// 	std::cout << temp << std::endl;
// 	tmp.setRawBits((int)temp);
// 	test = tmp.getRawBits();
// 	print_bit(4, &test);
// 	std::cout << tmp << std::endl;
// 	return (tmp);
// }

// Fixed Fixed::operator / (const Fixed &a)
// {
// 	Fixed tmp;

// 	int test = this->getRawBits();
// 	print_bit(4, &test);
// 	std::cout << test << std::endl;
// 	std::cout << *this << std::endl;
// 	u_int64_t btest = u_int64_t(this->getRawBits());
// 	print_bit(sizeof(u_int64_t), &btest);
// 	test = a.getRawBits();
// 	print_bit(4, &test);
// 	std::cout << test << std::endl;
// 	std::cout << a << std::endl;
// 	btest = u_int64_t(a.getRawBits());
// 	print_bit(sizeof(u_int64_t), &btest);
// 	std::cout << btest << std::endl;
// 	tmp.setRawBits((int)(u_int64_t(this->_FixedPoint_value) / u_int64_t(a._FixedPoint_value)));
// 	test = tmp.getRawBits();
// 	print_bit(4, &test);
// 	std::cout << tmp << std::endl;
// 	return (tmp);
// }
