/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:36:28 by hyungdki          #+#    #+#             */
/*   Updated: 2023/12/04 12:20:20 by hyungdki         ###   ########.fr       */
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
	Point chk0(1.0f, 1.0f);
	Point chk1(3.5f, 6.5f);
	Point chk2(3.5f, 6.4f);
	Point chk3(0.0f, 6.0f);
	Point chk4 = b;

	std::cout << "a : " << a.getx() << ", " << a.gety() << '\n';
	std::cout << "b : " << b.getx() << ", " << b.gety() << '\n';
	std::cout << "c : " << c.getx() << ", " << c.gety() << '\n';
	std::cout << "chk : " << chk.getx() << ", " << chk.gety() << '\n';
	std::cout << "chk0 : " << chk0.getx() << ", " << chk0.gety() << '\n';
	std::cout << "chk1 : " << chk1.getx() << ", " << chk1.gety() << '\n';
	std::cout << "chk2 : " << chk2.getx() << ", " << chk2.gety() << '\n';
	std::cout << "chk3 : " << chk3.getx() << ", " << chk3.gety() << '\n';

	if (bsp(a,b,c,chk) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";

	if (bsp(a,b,c,chk0) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";
	
	if (bsp(a,b,c,chk1) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";

	if (bsp(a,b,c,chk2) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";

	if (bsp(a,b,c,chk3) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";

	if (bsp(a,b,c,chk4) == true)
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point isn't inside the triangle\n";

	return 0;
}
