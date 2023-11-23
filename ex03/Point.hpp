/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:12:43 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 19:40:07 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Point &origin);
	Point(const float _x, const float _y);
	Point& operator=(const Point& origin);
	~Point();

	const Fixed& getx() const;
	const Fixed& gety() const;
	
};

#endif