/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:12:41 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 19:38:37 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	;
}

Point::Point(const Point &origin)
{
	*this = origin;
}

Point::Point(const float _x, const float _y) : x(_x), y(_y)
{
	;
}

Point& Point::operator=(const Point& origin)
{
	if (this != &origin)
	{
		Fixed* ptr_x = const_cast<Fixed*>(&x);
		Fixed* ptr_y = const_cast<Fixed*>(&y);

		*ptr_x = origin.x;
		*ptr_y = origin.y;
	}
	return *this;
}

Point::~Point()
{
	;
}

const Fixed& Point::getx() const
{
	return x;
}

const Fixed& Point::gety() const
{
	return y;
}

