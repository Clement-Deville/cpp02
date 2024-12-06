/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/06 15:57:09 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	if (bsp(Point(4.0f, 3.0f),
			Point(3.0f, 2.0f),
			Point(1.0f, 0.0f),
			Point(2.0f,3.0f)))
		std::cout << "The point " << Point(2,3) << " is in the Triangle"
			<< std::endl;
	else
	{
		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
			<< std::endl;
	}
	if (bsp(Point(10.0f, -5.0f),
			Point(3.5f, 6.0f),
			Point(-1.0f, -5.0f),
			Point(2.0f, 3.0f)))
		std::cout << "The point " << Point(2,3) << " is in the Triangle"
		<< Point(10.0f, -5.0f) << " " << Point(3.5f, 6.0f)
		<< " " << Point(-1.0f, -5.0f)
			<< std::endl;
	else
	{
		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
		<< Point(10.0f, -5.0f) << " " << Point(3.5f, 6.0f)
		<< " " << Point(-1.0f, -5.0f)
			<< std::endl;
	}
	if (bsp(Point(1.0f, 2.0f),
			Point(1.f, -1.0f),
			Point(-1.0f, -2.0f),
			Point(3.0f, 3.0f)))
		std::cout << "The point " << Point(3,3) << " is in the Triangle"
		<< Point(1.0f, 2.0f) << " " << Point(1.0f, -1.0f)
		<< " " << Point(-1.0f, -2.0f)
			<< std::endl;
	else
	{
		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
		<< Point(10.0f, -5.0f) << " " << Point(3.5f, 6.0f)
		<< " " << Point(-1.0f, -5.0f)
			<< std::endl;
	}
	return (0);
}
