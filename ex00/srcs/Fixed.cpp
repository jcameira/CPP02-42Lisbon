/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:28:49 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/13 14:34:52 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ): _fixedValue( 0 ){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy ){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &obj){
    std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &obj )
        this->_fixedValue = obj.getRawBits();
    return ( *this );
}

Fixed::~Fixed( void ){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return ( this->_fixedValue );
}

void Fixed::setRawBits( int raw ){
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedValue = raw;
}