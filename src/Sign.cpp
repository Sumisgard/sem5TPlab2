#include "Sign.hpp"

namespace smd 
{
    Human::Human()
    {
        this->firstName = "";
        this->lastName = "";
        this->birthDate[0] = 0;
        this->birthDate[1] = 0;
        this->birthDate[2] = 0;
    }

    Human::Human(std::string firstName, std::string lastName, unsigned day, unsigned month, unsigned year)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->birthDate[0] = day;
        this->birthDate[1] = month;
        this->birthDate[2] = year;
    }

    Human::Human(const Human& obj)
    {
        this->firstName = obj.firstName;
        this->lastName = obj.lastName;
        this->birthDate[0] = obj.birthDate[0];
        this->birthDate[1] = obj.birthDate[1];
        this->birthDate[2] = obj.birthDate[2];
    }

    void Human::set_firstName(std::string firstName)
    {
        this->firstName = firstName;
    }

    void Human::set_lastName(std::string lastName)
    {
        this->lastName = lastName;
    }

    void Human::set_birthDate(unsigned day, unsigned month, unsigned year)
    {
        this->birthDate[0] = day;
        this->birthDate[1] = month;
        this->birthDate[2] = year;
    }

    std::string Human::get_firstName() const
    {
        return this->firstName;
    }

    std::string Human::get_lastName() const
    {
        return this->lastName;
    }

    const unsigned* Human::get_birthDate() const
    {
        return this->birthDate;
    }

    unsigned Human::get_day() const
    {
        return this->birthDate[0];
    }

    unsigned Human::get_month() const
    {
        return this->birthDate[1];
    }

    unsigned Human::get_year() const
    {
        return this->birthDate[2];
    }

    Sign::Sign() : Human()
    {
        this->sign = "";
    }

    Sign::Sign(std::string firstName, std::string lastName, std::string sign, unsigned day, unsigned month, unsigned year) : Human(firstName, lastName, day, month, year)
    {
        this->sign = sign;
    }

    Sign::Sign(const Sign& obj): Human(obj)
    {
        this->sign = obj.sign;
    }

    void Sign::set_sign(std::string sign)
    {
        this->sign = sign;
    }

    std::string Sign::get_sign() const
    {
        return this->sign;
    }

    std::ostream& operator << (std::ostream &os, const Sign &obj)
    {
        return os << obj.get_firstName() << " " << obj.get_lastName() << " " << obj.get_sign() << " " << obj.get_day() << " " << obj.get_month() << " " << obj.get_year() << "\n";
    }

    std::istream& operator >> (std::istream& in, Sign& obj)
    {
        std::string firstName;
        std::string lastName;
        std::string sign;
        unsigned day;
        unsigned month;
        unsigned year;

        in >> firstName >> lastName >> sign >> day >> month >> year;

        obj.set_firstName(firstName);
        obj.set_lastName(lastName);
        obj.set_sign(sign);
        obj.set_birthDate(day, month, year);
    }
}