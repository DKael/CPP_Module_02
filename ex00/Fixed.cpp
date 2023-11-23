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

Fixed& Fixed::operator=(const Fixed &origin)
{
	std::cout << "[Copy assignment operator called]\n";
	if (this != &origin)
		this->raw_value = origin.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "[Destructor called]\n";
}
int Fixed::getRawBits( void ) const
{
	std::cout << "[getRawBits member function called]\n";
	return raw_value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "[setRawBits member function called]\n";
	raw_value = raw;
}
