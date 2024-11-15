/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:28:49 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/15 17:31:02 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ): _fixedValue( 0 ) {
}

Fixed::Fixed( int nbr ) {
    this->_fixedValue = nbr << this->_fractBits;
}

Fixed::Fixed( float nbr ) {
    this->_fixedValue = nbr * ( 1 << this->_fractBits );
}

Fixed::Fixed( const Fixed &copy ) {
    *this = copy;
}

Fixed::~Fixed( void ) {
}

Fixed   &Fixed::operator=( const Fixed &obj ) {
    if ( this != &obj )
        this->_fixedValue = obj.getRawBits();
    return ( *this );
}

bool    Fixed::operator>( const Fixed &obj ) const {
    return ( this->toFloat() > obj.toFloat() );
}

bool    Fixed::operator<( const Fixed &obj ) const {
    return ( this->toFloat() < obj.toFloat() );
}

bool    Fixed::operator>=( const Fixed &obj ) const {
    return ( this->toFloat() >= obj.toFloat() );
}

bool    Fixed::operator<=( const Fixed &obj ) const {
    return ( this->toFloat() <= obj.toFloat() );
}

bool    Fixed::operator!=( const Fixed &obj ) const {
    return ( this->toFloat() != obj.toFloat() );
}

bool    Fixed::operator==( const Fixed &obj ) const {
    return ( this->toFloat() == obj.toFloat() );
}

float   Fixed::operator+( const Fixed &obj ) const {
    return ( this->toFloat() + obj.toFloat() );
}

float   Fixed::operator-( const Fixed &obj ) const {
    return ( this->toFloat() - obj.toFloat() );
}

float   Fixed::operator*( const Fixed &obj ) const {
    return ( this->toFloat() * obj.toFloat() );
}

float   Fixed::operator/( const Fixed &obj ) const {
    return ( this->toFloat() / obj.toFloat() );
}

Fixed   Fixed::operator++( void ) {
    this->_fixedValue++;
    return ( *this );
}

Fixed   Fixed::operator++( int value ) {
    Fixed   tmp = *this;
    if ( !value )
        value = 1;
    this->_fixedValue += value;
    return ( tmp );
}

Fixed   Fixed::operator--( void ) {
    this->_fixedValue--;
    return ( *this );
}

Fixed   Fixed::operator--( int value ) {
    Fixed   tmp = *this;
    if ( !value )
        value = 1;
    this->_fixedValue -= value;
    return ( tmp );
}

Fixed   &Fixed::min( Fixed &first, Fixed &second ) {
    if ( first > second )
        return ( second );
    return ( first );
}

const Fixed &Fixed::min( const Fixed &first, const Fixed &second ) {
    if ( first > second )
        return ( second );
    return ( first );
}

Fixed   &Fixed::max( Fixed &first, Fixed &second ) {
    if ( first > second )
        return ( first );
    return ( second );
}

const Fixed &Fixed::max( const Fixed &first, const Fixed &second ) {
    if ( first > second )
        return ( first );
    return ( second );
}

int Fixed::getRawBits( void ) const {
    return ( this->_fixedValue );
}

void    Fixed::setRawBits( int raw ) {
    this->_fixedValue = raw;
}

int Fixed::toInt( void ) const {
    return ( this->_fixedValue >> this->_fractBits );
}

float   Fixed::toFloat( void ) const {
    return ( ( float )this->_fixedValue / ( float )( 1 << this->_fractBits ) );
}

std::ostream    &operator<<( std::ostream &out, const Fixed &fixed ) {
    return ( out << fixed.toFloat() );
}