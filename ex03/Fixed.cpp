/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:07:18 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 19:11:09 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	raw_value = 0;
}

Fixed::Fixed(const Fixed &origin)
{
	*this = origin;
}

Fixed::Fixed(const int integer)
{
	raw_value = integer * (1 << Fixed::fractional_bits);
}

Fixed::Fixed(const float float_num)
{
	raw_value = static_cast<int>(roundf(float_num * (1 << Fixed::fractional_bits)));
}

Fixed &Fixed::operator=(const Fixed &origin)
{
	if (this != &origin)
		this->raw_value = origin.raw_value;
	return *this;
}

Fixed::~Fixed()
{
	;
}
int Fixed::getRawBits(void) const
{
	return raw_value;
}

void Fixed::setRawBits(int const raw)
{
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

bool Fixed::operator>(const Fixed& op) const
{
	return raw_value > op.raw_value;
}

bool Fixed::operator<(const Fixed& op) const
{
	return raw_value < op.raw_value;
}

bool Fixed::operator>=(const Fixed& op) const
{
	return raw_value >= op.raw_value;
}

bool Fixed::operator<=(const Fixed& op) const
{
	return raw_value <= op.raw_value;
}

bool Fixed::operator==(const Fixed& op) const
{
	return raw_value == op.raw_value;
}

bool Fixed::operator!=(const Fixed& op) const
{
	return raw_value != op.raw_value;
}

Fixed Fixed::operator+(const Fixed& op) const
{
	return Fixed(this->toFloat() + op.toFloat());
}

Fixed Fixed::operator-(const Fixed& op) const
{
	return Fixed(this->toFloat() - op.toFloat());
}

Fixed Fixed::operator*(const Fixed& op) const
{
	return Fixed(this->toFloat() * op.toFloat());
}

Fixed Fixed::operator/(const Fixed& op) const
{
	return Fixed(this->toFloat() / op.toFloat());
}

Fixed& Fixed::operator++(void)
{
	raw_value++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	raw_value--;
	return *this;
}

const Fixed Fixed::operator++(int)
{
	const Fixed tmp(*this);
	raw_value++;
	return tmp;
}

const Fixed Fixed::operator--(int)
{
	const Fixed tmp(*this);
	raw_value--;
	return tmp;
}

Fixed& Fixed::min(Fixed& op1, Fixed& op2)
{
	return op1.raw_value > op2.raw_value ? op2 : op1;
}

const Fixed& Fixed::min(const Fixed& op1, const Fixed& op2)
{
	return op1.raw_value > op2.raw_value ? op1 : op2;
}

Fixed& Fixed::max(Fixed& op1, Fixed& op2)
{
	return op1.raw_value > op2.raw_value ? op1 : op2;
}

const Fixed& Fixed::max(const Fixed& op1, const Fixed& op2)
{
	return op1.raw_value > op2.raw_value ? op1 : op2;
}

