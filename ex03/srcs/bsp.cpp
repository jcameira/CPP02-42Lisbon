/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:50:50 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/16 22:32:51 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

float   crossProduct( Point const a, Point const b, Point const point ) {
    return ( ( ( b.getX() - a.getX() ) * ( point.getY() - a.getY() ) ) - ( ( b.getY() - a.getY() ) * ( point.getX() - a.getX() ) ) );
}

bool    bsp( Point const a, Point const b, Point const c, Point const point ) {
    float   AB = crossProduct( a, b, point );
    float   BC = crossProduct( b, c, point );
    float   CA = crossProduct( c, a, point );

    return ( ( AB >= 0 && BC >= 0 && CA >= 0 ) || ( AB <= 0 && BC <= 0 && CA <= 0 ) );
}