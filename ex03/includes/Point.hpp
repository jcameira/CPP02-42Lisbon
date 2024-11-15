/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:49:45 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/15 19:11:47 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <Fixed.hpp> 

class Point {
    public:
        Point( void );
        Point( const float a, const float b );
        Point( const Point &copy );
        ~Point( void );

        Point   &operator=( const Point &obj);

        const Fixed &getX( void ) const;
        const Fixed &getY( void ) const;

    private:
        const Fixed _x;
        const Fixed _y;

};

#endif