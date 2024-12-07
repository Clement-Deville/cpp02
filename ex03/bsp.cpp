/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:40 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/07 16:54:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	vector_size(const Point &A, const Point &B)
{
	Fixed ab_size;
	// float tmp;

	std::cout << "A: " << A << std::endl;
	std::cout << "B: " << B << std::endl;
	ab_size = ((B.getX() - A.getX()) * (B.getX() - A.getX())
		+ (B.getY() - A.getY()) * (B.getY() - A.getY()));
	// ab_size = (B.getX() - A.getX());
	std::cout << "ab_size " << ab_size << std::endl;
	std::cout << "TMP: " << ab_size.toFloat() << std::endl;
	ab_size = Fixed((float)std::sqrt((double)ab_size.toFloat()));
	return (ab_size);
}

Fixed	get_area(const Point &A, const Point &B, const Point &C)
{
	Fixed	Base, Height;

	Base = vector_size(A, B);
	Height = 
}

bool	check_degenerate_triangle(Point const a, Point const b, Point const c)
{
	// //! NOT FIXED ?
	// if (((c.getY() - a.getY()) * (b.getX() - a.getX())
	// - (b.getY() - a.getY()) * (c.getX() - a.getX()))
	// / (c.getX() - a.getX())
	// == Fixed(0))
	// 	return (true);
	// return (false);
	Fixed ab_size = vector_size(a, b);
	Fixed bc_size = vector_size(c, b);
	Fixed ac_size = vector_size(a, c);

	std::cout << "Side sizes:\nAB: " << ab_size << "\nBC: "
		<< bc_size << "\nAC: " << ac_size << std::endl;
	if ((vector_size(a, b) + vector_size(b, c) <= vector_size(a, c))
		|| (vector_size(a, c) + vector_size(b, c) <= vector_size(a, b))
		|| (vector_size(a, b) + vector_size(a, c) <= vector_size(b, c)))
		return (true);
	return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1;
	Fixed w2;
	Fixed Ax(a.getX()), Ay(a.getY()), Bx(b.getX()), By(b.getY()),
		Cx(c.getX()), Cy(c.getY()), Px(point.getX()), Py(point.getY());

	if (check_degenerate_triangle(a, b, c) == true)
	{
		std::cerr << "The triangle is a degenerate triangle, the point can't be inside" << std::endl;
		return (false);
	}
	// if (b.getX() - a.getX() != Fixed(0)
	// 	&& (c.getX() - a.getX()) * (b.getY() - a.getY())
	// 		- (c.getY() - a.getY()) * (b.getX() - a.getX()) != Fixed(0))
	// {
	// 	w2 = a.getY() * (b.getX() - a.getX())
	// 		+ (point.getX() - a.getX()) * (b.getY() - a.getY())
	// 		- point.getY() * (b.getX() - a.getX());
	// 	w2 /= (c.getX() - a.getX()) * (b.getY() - a.getY())
	// 		- (c.getY() - a.getY()) * (b.getX() - a.getX());
	// 	w1 = point.getX() - a.getX() - w2 * (c.getX() - a.getX());
	// 	w1 /= b.getX() - a.getX();
	// 	// w2 = a.getY() * (b.getX() - a.getX())
	// 	// 	+ (point.getX() - a.getX()) * (b.getY() - a.getY())
	// 	// 	- point.getY() * (b.getX() - a.getX());
	// 	// w2 /= (c.getX() - a.getX()) * (b.getY() - a.getY())
	// 	// 	- (c.getY() - a.getY()) * (b.getX() - a.getX());
	// 	// w1 = point.getX() - a.getX() - w2 * (c.getX() - a.getX());
	// 	// w1 /= b.getX() - a.getX();
	// 	std::cout << "\n1--->" << std::endl;
	// }
	// else
	// {
	// 	w1 = a.getX() * (c.getY() - a.getY())
	// 	+ (point.getY() - a.getY()) * (c.getX() - a.getX())
	// 	- point.getX() * (c.getY() - a.getY());
	// 	w1 /= (b.getY() - a.getY()) * (c.getX() - a.getX())
	// 		- (b.getX() - a.getX()) * (c.getY() - a.getY());
	// 	w2 = point.getY() - a.getY()
	// 		- w1 * (b.getY() - a.getY());
	// 	w2 /= c.getY() - a.getY();
	// 	// 		w1 = a.getX() * (c.getY() - a.getY())
	// 	// + (point.getY() - a.getY()) * (c.getX() - a.getX())
	// 	// - point.getX() * (c.getY() - a.getY());
	// 	// w1 /= (b.getY() - a.getY()) * (c.getX() - a.getX())
	// 	// 	- (b.getX() - a.getX()) * (c.getY() - a.getY());
	// 	// w2 = point.getY() - a.getY()
	// 	// 	- w1 * (b.getY() - a.getY());
	// 	// w2 /= c.getY() - a.getY();
	// 	std::cout << "\n2--->" << std::endl;
	// }
	if (Cy - Ay != Fixed(0))
	{
		w1 = Ax * (Cy - Ay) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
		w1 /= (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);

		w2 = Py - Ay - w1 * (By - Ay);
		w2 /= Cy - Ay;
	}
	else
	{
		w2 =

		w1 = Py - Ay - w2 * (Cy - Ay);
		w1 /= By - Ay;
	}
	std::cout << "\nSTD::\nW1: " << w1 << "\nW2: " << w2 << std::endl;
	if (w1 >= Fixed(0)
		&& w2 >= Fixed(0)
		&& w1 + w2 <= Fixed(1))
		return (true);
	return (false);
}
