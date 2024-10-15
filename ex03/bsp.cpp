/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:40 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/15 12:47:55 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	check_degenerate_triangle(Point const a, Point const b, Point const c)
{
	std::cout << "YO: " << ((c.getY() - a.getY()) * (b.getX() - a.getX())
	- (b.getY() - a.getY()) * (c.getX() - a.getX()))
	/ (c.getX() - a.getX()) << std::endl;
	if (((c.getY() - a.getY()) * (b.getX() - a.getX())
	- (b.getY() - a.getY()) * (c.getX() - a.getX()))
	/ (c.getX() - a.getX())
	== Fixed(0))
		return (true);
	return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1;
	Fixed w2;

	if (check_degenerate_triangle(a, b, c) == true)
	{
		std::cerr << "The triangle is a degenerate triangle, the point can't be inside" << std::endl;
		return (false);
	}
	if (b.getX() - a.getX() != Fixed(0)
		&& (c.getX() - a.getX()) * (b.getY() - a.getY())
			- (c.getY() - a.getY()) * (b.getX() - a.getX()) != Fixed(0))
	{
		w2 = a.getY() * (b.getX() - a.getX())
			+ (point.getX() - a.getX()) * (b.getY() - a.getY())
			- point.getY() * (b.getX() - a.getX());
		w2 /= (c.getX() - a.getX()) * (b.getY() - a.getY())
			- (c.getY() - a.getY()) * (b.getX() - a.getX());
		w1 = point.getX() - a.getX() - w2 * (c.getX() - a.getX());
		w1 /= b.getX() - a.getX();
	}
	else
	{
		w1 = a.getX() * (c.getY() - a.getY())
		+ (point.getY() - a.getY()) * (c.getX() - a.getX())
		- point.getX() * (c.getY() - a.getY());
		w1 /= (b.getY() - a.getY()) * (c.getX() - a.getX())
			- (b.getX() - a.getX()) * (c.getY() - a.getY());
		w2 = point.getY() - a.getY()
			- w1 * (b.getY() - a.getY());
		w2 /= c.getY() - a.getY();
	}
	if (w1 == Fixed(0) && w1 < Fixed(1)
		&& w2 == Fixed(0) && w2 < Fixed(1)
		&& w1 + w2 < Fixed(1))
		return (true);
	return (false);
}
