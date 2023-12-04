/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:12:38 by hyungdki          #+#    #+#             */
/*   Updated: 2023/12/04 12:02:06 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed barycentric(Point const p1, Point const p2, Point const p3)
{
	return (p1.getx() - p3.getx()) * (p2.gety() - p3.gety())
		- (p2.getx() - p3.getx()) * (p1.gety() - p3.gety());
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;
	bool chk_neg;
	bool chk_pos;

	d1 = barycentric(point, a, b);
	d2 = barycentric(point, b, c);
	d3 = barycentric(point, c, a);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	chk_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    chk_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(chk_neg && chk_pos);
}
