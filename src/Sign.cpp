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

    Container::Container()
    {
        this->signs = new Sign[1];
        this->size = 0;
        this->actualSize = 1;
    }

    Container::Container(const Container& obj)
    {
        this->signs = new Sign[obj.actualSize];
        for (int i = 0; i < obj.actualSize; ++i)
        {
            this->signs[i] = obj.signs[i];
        }
    }

    Container::~Container()
    {
        delete[] this->signs;
    }

    static Sign* widenSigns(const Sign* const signs, unsigned size)
    {
        Sign* copySigns = new Sign[size + 1];

        for (int i = 0; i < size; ++i)
        {
            copySigns[i] = signs[i];
        }

        return copySigns;
    }

    void Container::addSign(std::string firstName, std::string lastName, std::string sign, unsigned day, unsigned month, unsigned year)
    {
        Sign* signsCopy = widenSigns(this->signs, this->actualSize);

        signsCopy[this->actualSize].set_firstName(firstName);
        signsCopy[this->actualSize].set_lastName(lastName);
        signsCopy[this->actualSize].set_sign(sign);
        signsCopy[this->actualSize].set_birthDate(day, month, year);

        ++(this->actualSize);
        ++(this->size);
        delete[] this->signs;
        this->signs = signsCopy;
    }

    void Container::deleteSign(unsigned index)
    {
        Sign* signsNarrow = new Sign[this->actualSize - 1];

        for (int i, j = 0; i < this->actualSize; ++i)
        {
            if (i != index)
            {
                signsNarrow[j] = this->signs[i];
                ++j;
            }
        }

        delete[] this->signs;
        this->signs = signsNarrow;
    }
    
    void Container::sortByDate()
    {
        unsigned n = this->actualSize;
        bool swapped = true;

        for (int i = 0; i < n - 1; ++i)
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (this->signs[j].get_year() > this->signs[j + 1].get_year() && this->signs[j].get_month() > this->signs[j + 1].get_month() && this->signs[j].get_day() > this->signs[j + 1].get_day())
                {
                    Sign temp = this->signs[j];
                    this->signs[j] = this->signs[j + 1];
                    this->signs[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
            {
                break;
            }
        }
    }

    void Container::printAll() const
    {
        Container sortedContainer(*this);
        sortedContainer.sortByDate();

        for (int i = 1; i < this->actualSize; ++i)
        {
            std::cout << sortedContainer.signs[i];
        }
    }
    void Container::printBySign(std::string sign) const
    {
        for (int i = 1; i < this->actualSize; ++i)
        {
            if (this->signs[i].get_sign() == sign)
            {
                std::cout << this->signs[i];
            }
        }
    }
}