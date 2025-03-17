#include "Fixed.hpp"


Fixed::Fixed(): value_fix(0)
{
    std::cout<< "default constructor called\n";
}

Fixed::~Fixed(){ std::cout << "Destructor called\n"; }

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed   &Fixed::operator=(Fixed const &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value_fix = other.getRawBits();
    return *this;

}
Fixed::Fixed(const int num) : value_fix(num * (1 << fraccional))
{
    std::cout<< "int constructor called\n"; 
}

Fixed::Fixed(const float num) : value_fix(num * (1 << fraccional))
{
    std::cout<< "float constructor called\n";     
}

int Fixed::getRawBits()const
{
    std::cout << "Function member getRawBIts called\n";
    return (this->value_fix);
}
float Fixed::toFloat(void) const{
    return((float)this->value_fix / (1 << fraccional));
}

int   Fixed::toInt(void) const{
    return(this->value_fix / (1 << fraccional));
}

std:: ostream &operator<<(std:: ostream &ostream, Fixed const &fixed)
{
    ostream << fixed.toFloat();
    return ostream;
}

void    Fixed::setRawBits(int const raw){ this->value_fix = raw;}

