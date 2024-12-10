/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:19:02 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/10 11:46:07 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

void	print_bit(size_t size, const void *value);

class Fixed
{
private:
	int					_FixedPoint_value;
	static const int	_bit_size = 8;
public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float f_nb);
	Fixed(const Fixed &Cpy);
	~Fixed();

	Fixed & operator = (const Fixed &a);


	bool operator > (const Fixed &a) const;
	bool operator < (const Fixed &a) const;
	bool operator >= (const Fixed &a) const;
	bool operator <= (const Fixed &a) const;
	bool operator == (const Fixed &a) const;
	bool operator != (const Fixed &a) const;

	Fixed operator + (const Fixed &a) const;
	Fixed &operator += (const Fixed &a);
	Fixed operator - (const Fixed &a) const;
	Fixed &operator -= (const Fixed &a);
	Fixed operator * (const Fixed &a) const;
	Fixed &operator *= (const Fixed &a);
	Fixed operator / (const Fixed &a) const;
	Fixed &operator /= (const Fixed &a);

	Fixed &operator ++ (void);
	Fixed operator ++ (int);
	Fixed &operator -- (void);
	Fixed operator -- (int);

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);


	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

	std::ostream & operator << (std::ostream &os, const Fixed &b);

#endif
