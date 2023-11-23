/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:36:36 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 18:48:36 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	static const int fractional_bits = 8;
	int	raw_value;
	
public:
	Fixed();
	Fixed(const Fixed &origin);
	Fixed(const int integer);
	Fixed(const float float_num);
	Fixed& operator=(const Fixed &origin);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed& op) const;
	bool operator<(const Fixed& op) const;
	bool operator>=(const Fixed& op) const;
	bool operator<=(const Fixed& op) const;
	bool operator==(const Fixed& op) const;
	bool operator!=(const Fixed& op) const;

	Fixed operator+(const Fixed& op) const;
	Fixed operator-(const Fixed& op) const;
	Fixed operator*(const Fixed& op) const;
	Fixed operator/(const Fixed& op) const;

	Fixed& operator++(void);
	Fixed& operator--(void);
	const Fixed operator++(int);
	const Fixed operator--(int);

	static Fixed& min(Fixed& op1, Fixed& op2);
	static const Fixed& min(const Fixed& op1, const Fixed& op2);
	static Fixed& max(Fixed& op1, Fixed& op2);
	static const Fixed& max(const Fixed& op1, const Fixed& op2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &to_print);

#endif