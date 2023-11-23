/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:36:28 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 22:03:01 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a;
	Point b(10.0f,0.0f);
	Point c(0.0f,10.0f);
	Point chk(3.5f, 6.6f);

	std::cout << "a : " << a.getx() << ", " << a.gety() << '\n';
	std::cout << "b : " << b.getx() << ", " << b.gety() << '\n';
	std::cout << "c : " << c.getx() << ", " << c.gety() << '\n';
	std::cout << "chk : " << chk.getx() << ", " << chk.gety() << '\n';

	if (bsp(a,b,c,chk) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";

	return 0;
}
