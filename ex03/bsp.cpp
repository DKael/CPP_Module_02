/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:12:38 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 22:02:41 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed shoelace_formula(Point const p1, Point const p2, Point const p3)
{
	// return p1.getx() * p2.gety() + p2.getx() * p3.gety() + p3.getx() * p1.gety()
	// 	- p1.gety() * p2.getx() - p2.gety() * p3.getx() - p3.gety() * p1.getx();
	return (p1.getx() - p3.getx()) * (p2.gety() - p3.gety())
		- (p2.getx() - p3.getx()) * (p1.gety() - p3.gety());
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;
	bool chk_neg;
	bool chk_pos;

	d1 = shoelace_formula(point, a, b);
	d2 = shoelace_formula(point, b, c);
	d3 = shoelace_formula(point, c, a);

	//std::cout << "d1 : " << d1 << ", d2 : " << d2 << ", d3 : " << d3 << '\n';

	chk_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    chk_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(chk_neg && chk_pos);
}
