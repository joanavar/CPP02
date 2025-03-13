#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    
        int                 value_fix;
        static int const    fraccional = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(Fixed const &copy);
    Fixed &operator=(Fixed const &other);
    
};

Fixed::Fixed(/* args */)
{
}

Fixed::~Fixed()
{
}

#endif