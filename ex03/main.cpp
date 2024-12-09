/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:04:35 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/09 20:17:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	Point A(0, 0);
	Point B(6, 0);
	Point C(3, 6);
	
	std::cout << 
	"/**============================================\n" <<
	 "*               Testing INSIDE POINTS\n" <<
	 "*=============================================**/\n" << std::endl;
	{
		Point P1(2, 1);
		Point P2(4, 1);
		Point P3(3, 3);
		Point P4(1.5, 2);
		Point P5(3, 2);

		Point *tab[5] = {&P1, &P2, &P3, &P4, &P5};

		for (int i = 0; i < 5; i++)
		{
			if (bsp(A, B, C, *tab[i]))
				std::cout << "The point " << *tab[i] << " is in the Triangle"
					<< std::endl;
			else
			{
				std::cout << "The point " << *tab[i] << " is not in the Triangle"
				<< std::endl;
			}
		}
	}

	std::cout << 
	"\n\n/**============================================\n" <<
	 "*               Testing EDGE POINTS\n" <<
	 "*=============================================**/\n" << std::endl;
	{
		Point P1(3, 0);
		Point P2(1.5, 0.75);
		Point P3(4.5, 1.5);
		Point P4(0, 0);
		Point P5(6, 0);

		//! Probleme de precision pour les edges 
		Point *tab[5] = {&P1, &P2, &P3, &P4, &P5};

		for (int i = 0; i < 5; i++)
		{
			if (bsp(A, B, C, *tab[i]))
				std::cout << "The point " << *tab[i] << " is in the Triangle"
					<< std::endl;
			else
			{
				std::cout << "The point " << *tab[i] << " is not in the Triangle"
				<< std::endl;
			}
		}
	}

	std::cout << 
	"\n\n/**============================================\n" <<
	 "*               Testing OUSTIDES POINTS\n" <<
	 "*=============================================**/\n" << std::endl;
	{
		Point P1(3, -1);
		Point P2(-1, 1);
		Point P3(7, 2);
		Point P4(3, 7);
		Point P5(5, 5);

		//! Probleme de precision pour les edges 
		Point *tab[5] = {&P1, &P2, &P3, &P4, &P5};

		for (int i = 0; i < 5; i++)
		{
			if (bsp(A, B, C, *tab[i]))
				std::cout << "The point " << *tab[i] << " is in the Triangle"
					<< std::endl;
			else
			{
				std::cout << "The point " << *tab[i] << " is not in the Triangle"
				<< std::endl;
			}
		}
	}
	return (0);
}

// int	main( void )
// {
// 	if (bsp(Point(4.0f, 3.0f),
// 			Point(3.0f, 2.0f),
// 			Point(1.0f, 0.0f),
// 			Point(2.0f,3.0f)))
// 		std::cout << "The point " << Point(2,3) << " is in the Triangle"
// 			<< std::endl;
// 	else
// 	{
// 		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
// 			<< std::endl;
// 	}
// 	if (bsp(Point(10.0f, -5.0f),
// 			Point(3.5f, 6.0f),
// 			Point(-1.0f, -5.0f),
// 			Point(2.0f, 3.0f)))
// 		std::cout << "The point " << Point(2,3) << " is in the Triangle"
// 		<< Point(10.0f, -5.0f) << " " << Point(3.5f, 6.0f)
// 		<< " " << Point(-1.0f, -5.0f)
// 			<< std::endl;
// 	else
// 	{
// 		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
// 		<< Point(10.0f, -5.0f) << " " << Point(3.5f, 6.0f)
// 		<< " " << Point(-1.0f, -5.0f)
// 			<< std::endl;
// 	}
// 	if (bsp(Point(1.0f, 2.0f),
// 			Point(1.f, -1.0f),
// 			Point(-1.0f, -2.0f),
// 			Point(3.0f, 3.0f)))
// 		std::cout << "The point " << Point(3,3) << " is in the Triangle"
// 		<< Point(1.0f, 2.0f) << " " << Point(1.0f, -1.0f)
// 		<< " " << Point(-1.0f, -2.0f)
// 			<< std::endl;
// 	else
// 	{
// 		std::cout << "The point " << Point(2,3) << " is not in the Triangle"
// 		<< Point(10.0f, -5.0f) << " " << Point(3.5f, 6.0f)
// 		<< " " << Point(-1.0f, -5.0f)
// 			<< std::endl;
// 	}
// 	return (0);
// }
