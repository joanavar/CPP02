#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
    
    Fixed(const int num);
    Fixed(const float num);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    float toFloat(void) const;
    int   toInt(void) const;
};

std:: ostream &operator<<(std:: ostream &ostream, Fixed const &fixed);

#endif