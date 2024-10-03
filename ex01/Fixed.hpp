/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:19:02 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/03 15:36:33 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	// int toInt( void ) const;
};

	std::ostream & operator << (std::ostream &os, const Fixed &b);

#endif
