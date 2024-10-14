/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:32:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/14 12:32:06 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	std::cout << "\e[0;32mDefault constructor called\e[0m" << std::endl;
}

Point::Point(const float fx, const float fy) : x(fx), y(fy)
{
	std::cout << "\e[0;32mFloat constructor called\e[0m" << std::endl;
}

Point::Point(const Point &Cpy) : x(Cpy.x), y(Cpy.y)
{
	std::cout << "\e[0;32mCopy constructor called\e[0m"
		<< std::endl;
}

Point::~Point()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

/**========================================================================
 *                           OPERATORS
 *========================================================================**/

Point & Point::operator = (const Point &a)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m"
		<< std::endl;
	(void)a;
	return (*this);
}

std::ostream & operator << (std::ostream &os, const Point &b)
{
	os << "X: " << b.getX() << ", Y: " << b.getY();
	return (os);
}

/**========================================================================
 *                           MEMBER FUNCTIONS
 *========================================================================**/

Fixed	Point::getX(void) const
{
	return(this->x);
}

Fixed	Point::getY(void) const
{
	return(this->y);
}
