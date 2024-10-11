/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:31:18 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/11 19:48:08 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point(void);
	Point(const float fx, const float fy);
	Point(const Point &Cpy);
	~Point();

	Point & operator = (const Point &a);

	Fixed getX(void) const;
	Fixed getY(void) const;
};


#endif
