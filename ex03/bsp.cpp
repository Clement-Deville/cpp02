/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:40 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/11 19:56:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1;

	w1 = a.getY() * (b.getX() - a.getX())
		+ (point.getX() - a.getX()) * (b.getY() - a.getY())
		- point.getY() * (b.getX() - a.getX());
	w1 /= (c.getX() - a.getX()) * (b.getY() - a.getY())
		- (c.getY() - a.getY()) * (b.getX() - a.getX());
}
