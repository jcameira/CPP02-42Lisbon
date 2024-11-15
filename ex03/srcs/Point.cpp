/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:49:55 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/15 19:39:27 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

Point::Point( void ): _x( 0 ), _y( 0 ) {
}

Point::Point( const float a, const float b ): _x( a ), _y( b ) {
}

Point::Point( const Point &copy ): _x( copy.getX() ), _y( copy.getY() ) {
}

Point::~Point( void ) {
}

Point   &Point::operator=( const Point &obj ) {
    return ( *this );
}

const Fixed   &Point::getX( void ) const {
    return (this->_x);
}

const Fixed   &Point::getY( void ) const {
    return (this->_y);
}