/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:36:36 by hyungdki          #+#    #+#             */
/*   Updated: 2023/11/23 17:38:44 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	static const int fractional_bits = 8;
	int	raw_value;
	
public:
	Fixed();
	Fixed(const Fixed &origin);
	Fixed& operator=(const Fixed &origin);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif