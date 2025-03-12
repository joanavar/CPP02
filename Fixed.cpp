#include "Fixed.hpp"


Fixed::Fixed(): value_fix(0)
{
    std::cout << "Fixed object is created for Constructor default\n";
}

Fixed::~Fixed()
{
    std::cout << "Fixed object destroyed\n";
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called\n";
    this->value_fix = other.getRawBits();
}
Fixed   &Fixed::operator=(Fixed const &other)
{
    std::cout << "Copy assigment constructor called\n";
    if (this != &other)
        this->value_fix = other.getRawBits();
    return *this;
}

 int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function is called\n";
    return(this->value_fix);
}

void    Fixed::setRawBits(int const raw)
{
    this->value_fix = raw;
}