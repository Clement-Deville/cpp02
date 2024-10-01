/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:19:02 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/01 15:24:59 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					fp_size;
	static const int	bit_size = 8;
public:
	Fixed();
	Fixed(Fixed &Cpy);
	~Fixed();

	Fixed & operator = (const Fixed &a);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
