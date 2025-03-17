#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(): value_fix(0)
{
    //std::cout<< "default constructor called\n";
}

Fixed::~Fixed(){ std::cout << "Destructor called\n"; }

Fixed::Fixed(Fixed const &copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    std::cout << this->getRawBits() << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value_fix = other.getRawBits();
    return *this;

}
Fixed::Fixed(const int num) : value_fix(num * (1 << fraccional))
{
    //std::cout<< "int constructor called\n"; 
}

Fixed::Fixed(const float num) : value_fix(num * (1 << fraccional))
{
    //std::cout<< "float constructor called\n";     
}

int Fixed::getRawBits()const
{
    //std::cout << "Function member getRawBIts called\n";
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

bool    Fixed::operator<(const Fixed &other) const
{
    return (getRawBits() < other.getRawBits());
}

bool    Fixed::operator>(const Fixed &other) const
{
    return (getRawBits() > other.getRawBits());
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (getRawBits() <= other.getRawBits());
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (getRawBits() >= other.getRawBits());
}

bool    Fixed::operator==(const Fixed &other) const
{
    return (getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (getRawBits() != other.getRawBits());
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(getRawBits() + other.getRawBits());
    return res;
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(getRawBits() - other.getRawBits());
    return res;
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(
        roundf(((int64_t)getRawBits() * other.getRawBits()) / (1 << fraccional)) 
    );
    return res;
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(
        roundf(((int64_t)this->getRawBits() * (1 << fraccional)) / other.getRawBits())
    );
    return res;
}

Fixed&  Fixed::operator++()
{
    this->value_fix++;
    return *this;
}

Fixed&  Fixed::operator--()
{
    this->value_fix--;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);

    ++(*this);
    return tmp;
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);

    --(*this);
    return tmp;
}

const Fixed &Fixed::min(const Fixed &A, const Fixed &B)
{
    if (A <= B)
        return A;
    else
        return B;
}

Fixed   &Fixed::min(Fixed &A, Fixed &B)
{
    if (A <= B)
        return A;
    else
        return B;
}

const Fixed &Fixed::max(const Fixed &A, const Fixed &B)
{
    if (A >= B)
        return A;
    else
        return B;
}

Fixed   &Fixed::max(Fixed &A, Fixed &B)
{
    if (A >= B)
        return A;
    else
        return B;
}
