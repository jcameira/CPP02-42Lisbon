/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:55:07 by jcameira          #+#    #+#             */
/*   Updated: 2024/11/13 14:38:53 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstring>
# include <string>
# include <iomanip>

class Fixed{
    public:
        Fixed( void );
        Fixed( int nbr );
        Fixed( float nbr );
        Fixed( const Fixed &copy );
        Fixed &operator=( const Fixed &obj );
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;

    private:
        int _fixedValue;
        static const int _fractBits;
        
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif