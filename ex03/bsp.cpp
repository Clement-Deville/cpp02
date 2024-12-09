/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:40 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/09 20:37:15 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Fixed	vector_size(const Point &A, const Point &B)
// {
// 	Fixed ab_size;
// 	// float tmp;

// 	std::cout << "A: " << A << std::endl;
// 	std::cout << "B: " << B << std::endl;
// 	ab_size = ((B.getX() - A.getX()) * (B.getX() - A.getX())
// 		+ (B.getY() - A.getY()) * (B.getY() - A.getY()));
// 	// ab_size = (B.getX() - A.getX());
// 	std::cout << "ab_size " << ab_size << std::endl;
// 	std::cout << "TMP: " << ab_size.toFloat() << std::endl;
// 	ab_size = Fixed((float)std::sqrt((double)ab_size.toFloat()));
// 	return (ab_size);
// }


// bool	check_degenerate_triangle(Point const a, Point const b, Point const c)
// {
// 	// //! NOT FIXED ?
// 	// if (((c.getY() - a.getY()) * (b.getX() - a.getX())
// 	// - (b.getY() - a.getY()) * (c.getX() - a.getX()))
// 	// / (c.getX() - a.getX())
// 	// == Fixed(0))
// 	// 	return (true);
// 	// return (false);
// 	Fixed ab_size = vector_size(a, b);
// 	Fixed bc_size = vector_size(c, b);
// 	Fixed ac_size = vector_size(a, c);

// 	std::cout << "Side sizes:\nAB: " << ab_size << "\nBC: "
// 		<< bc_size << "\nAC: " << ac_size << std::endl;
// 	if ((vector_size(a, b) + vector_size(b, c) <= vector_size(a, c))
// 		|| (vector_size(a, c) + vector_size(b, c) <= vector_size(a, b))
// 		|| (vector_size(a, b) + vector_size(a, c) <= vector_size(b, c)))
// 		return (true);
// 	return (false);
// }

Fixed	get_area(const Point &A, const Point &B, const Point &C)
{
	Fixed area = Fixed(0.5f) * ( A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()) ) ;
	if (area < Fixed(0))
		return (area * Fixed(-1));
	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Fixed w1;
	// Fixed w2;
	// Fixed Ax(a.getX()), Ay(a.getY()), Bx(b.getX()), By(b.getY()),
	// 	Cx(c.getX()), Cy(c.getY()), Px(point.getX()), Py(point.getY());
	Fixed other_areas[3];
	
	// if (check_degenerate_triangle(a, b, c) == true)
	// {
	// 	return (false);
	// }
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

	std::cout << "\n\nTriangle Area: " << Triangle_area << "\n";
	std::cout << "Area 1: " << other_areas[0] << "\n";
	std::cout << "Area 2: " << other_areas[1] << "\n";
	std::cout << "Area 3: " << other_areas[2] << "\n\n";
	if (other_areas[0] + other_areas[1] + other_areas[2] <= Triangle_area
		&& other_areas[0] != 0 && other_areas[1] != 0 && other_areas[2] != 0)
		return (true);
	else
		return (false);

}
