/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:55:07 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/16 16:24:44 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstring>
# include <string>
# include <iomanip>

class Fixed {
    public:
        Fixed( void );
        Fixed( int nbr );
        Fixed( float nbr );
        Fixed( const Fixed &copy );
        ~Fixed();
        
        Fixed   &operator=( const Fixed &obj );
        
        bool    operator>( const Fixed &obj ) const;
        bool    operator<( const Fixed &obj ) const;
        bool    operator>=( const Fixed &obj ) const;
        bool    operator<=( const Fixed &obj ) const;
        bool    operator!=( const Fixed &obj ) const;
        bool    operator==( const Fixed &obj ) const;
        
        float   operator+( const Fixed &obj ) const;
        float   operator-( const Fixed &obj ) const;
        float   operator*( const Fixed &obj ) const;
        float   operator/( const Fixed &obj ) const;

        Fixed   operator++( void );
        Fixed   operator++( int );
        Fixed   operator--( void );
        Fixed   operator--( int );
        
        static Fixed           &min( Fixed &first, Fixed &second );
        static const Fixed     &min( const Fixed &first, const Fixed &second );
        static Fixed           &max( Fixed &first, Fixed &second );
        static const Fixed     &max( const Fixed &first, const Fixed &second );
        
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        int     toInt( void ) const;
        float   toFloat( void ) const;

        

    private:
        int _fixedValue;
        static const int _fractBits;
        
};

std::ostream &operator<<( std::ostream &out, const Fixed &fixed );

#endif