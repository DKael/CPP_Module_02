/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:07:18 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 17:38:44 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "[Default constructor called]\n";
	raw_value = 0;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "[Copy constructor called]\n";
	*this = origin;
}

Fixed::Fixed(const int integer)
{
	std::cout << "[Int constructor called]\n";
	raw_value = integer << Fixed::fractional_bits;
}

Fixed::Fixed(const float float_num)
{
	std::cout << "[Float constructor called]\n";
	raw_value = static_cast<int>(roundf(float_num * (1 << Fixed::fractional_bits)));
}

Fixed &Fixed::operator=(const Fixed &origin)
{
	std::cout << "[Copy assignment operator called]\n";
	if (this != &origin)
		this->raw_value = origin.raw_value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "[Destructor called]\n";
}
int Fixed::getRawBits(void) const
{
	std::cout << "[getRawBits member function called]\n";
	return raw_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "[setRawBits member function called]\n";
	raw_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(raw_value) / static_cast<float>(1 << Fixed::fractional_bits);
}

int Fixed::toInt(void) const
{
	return raw_value / (1 << Fixed::fractional_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed &to_print)
{
	out << to_print.toFloat();
	return out;
}
