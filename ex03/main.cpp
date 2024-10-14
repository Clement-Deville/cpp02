/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/14 19:28:54 by cdeville         ###   ########.fr       */
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
	if (bsp(Point(4.0f, 3.0f),
			Point(3.0f, 3.0f),
			Point(1.0f, 0.0f),
			Point(2.0f,3.0f)))
		std::cout << "The point " << Point(2,3) << " is in the Triangle"
			<< std::endl;
	else
	{
		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
			<< std::endl;
	}
	return (0);
}
