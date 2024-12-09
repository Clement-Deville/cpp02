/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:40 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/09 23:14:34 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Fixed	get_area(const Point &A, const Point &B, const Point &C)
{
	Fixed area = Fixed(0.5f) * ( A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()) ) ;
	if (area < Fixed(0))
		return (area * Fixed(-1));
	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed other_areas[3];

	Fixed Triangle_area = get_area(a, b , c);
	std::cout << "Triangle area: " << Triangle_area << std::endl;
	if (Triangle_area == Fixed(0))
	{
 		std::cerr << "The triangle is a degenerate triangle, the point can't be inside" << std::endl;
		return (false); //! Checking If degenerate
	}
	other_areas[0] = get_area(a, b , point);
	other_areas[1] = get_area(a, point , c);
	other_areas[2] = get_area(point, b , c);

	// std::cout << "\n\nTriangle Area: " << Triangle_area << "\n";
	// std::cout << "Area 1: " << other_areas[0] << "\n";
	// std::cout << "Area 2: " << other_areas[1] << "\n";
	// std::cout << "Area 3: " << other_areas[2] << "\n\n";
	if (other_areas[0] + other_areas[1] + other_areas[2] <= Triangle_area
		&& other_areas[0] != 0 && other_areas[1] != 0 && other_areas[2] != 0)
		return (true);
	else
		return (false);
}
