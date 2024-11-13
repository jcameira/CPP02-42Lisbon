/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:28:49 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/13 15:05:45 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ): _fixedValue( 0 ){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int nbr ){
    std::cout << "Int constructor called" << std::endl;
    this->_fixedValue = nbr << this->_fractBits;
}

Fixed::Fixed( float nbr ){
    std::cout << "Float constructor called" << std::endl;
    this->_fixedValue = nbr * ( 1 << this->_fractBits );
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

int Fixed::toInt( void ) const {
    return ( this->_fixedValue >> this->_fractBits );
}

float Fixed::toFloat( void ) const {
    return ( ( float )this->_fixedValue / ( float )( 1 << this->_fractBits ) );
}

std::ostream &operator<<( std::ostream &out, const Fixed &fixed ){
    return ( out << fixed.toFloat() );
}