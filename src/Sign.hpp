#pragma once

#include <string>
#include <iostream>

namespace smd
{
    class Human
    {
    public:
        Human();
        Human(std::string firstName, std::string lastName, unsigned day, unsigned month, unsigned year);
        Human(const Human& obj);

        void set_firstName(std::string firstName);
        void set_lastName(std::string lastName);
        void set_birthDate(unsigned day, unsigned month, unsigned year);

        std::string get_firstName() const;
        std::string get_lastName() const;
        const unsigned* get_birthDate() const;
        unsigned get_day() const;
        unsigned get_month() const;
        unsigned get_year() const;

    protected:
        std::string firstName;
        std::string lastName;
        unsigned birthDate[3];
    };

    class Sign : public Human
    {
    public:
        Sign();
        Sign(std::string firstName, std::string lastName, std::string sign, unsigned day, unsigned month, unsigned year);
        Sign(const Sign& obj);

        void set_sign(std::string sign);

        std::string get_sign() const;

    private:
        std::string sign;
    };
    std::ostream& operator << (std::ostream &os, const Sign &obj);
    std::istream& operator >> (std::istream& in, Sign& obj);
    Sign* widenSigns(const Sign* const signs, unsigned size);

    class Container
    {
    public:
        Container();
        Container(const Container& obj);
        ~Container();

        void addSign(const Sign& obj);
        void addSign(std::string firstName, std::string lastName, std::string sign, unsigned day, unsigned month, unsigned year);
        void deleteSign(unsigned index);
        void sortByDate();
        void printAll() const;
        void printBySign(std::string sign) const;

    private:
        Sign* signs;
        unsigned actualSize;
    };

}