#include "Sign.hpp"
#include "Task.hpp"

int main()
{   
    bool state = true;
    unsigned choice1 = 0;
    unsigned choice2 = 0;
    unsigned temp;
    smd::Container people;
    std::string sign;
    smd::Sign person;

    std::cout << "Choose your fighter!!!" << std::endl;
    std::cout << "\t1. Task1" << std::endl;
    std::cout << "\t2. Task2" << std::endl;
    std::cin >> choice1;

    switch (choice1)
    {
    case 1:
        while (state)
        {
            std::cout << "Choose an option" << std::endl;
            std::cout << "\t1. Print all" << std::endl;
            std::cout << "\t2. Print by sign" << std::endl;
            std::cout << "\t3. Add person" << std::endl;
            std::cout << "\t4. Delete by index" << std::endl;
            std::cout << "\t5. Exit" << std::endl;
            std::cin >> choice2;

            switch (choice2)
            {
            case 1:
                std::cout << "All people:" << std::endl;
                people.printAll();
                break;
            case 2:
                std::cout << "Enter sign: " << std::endl;
                std::cin >> sign;
                people.printBySign(sign);
                break;
            case 3:
                std::cout << "Enter first name, last name, sign, day, month, year: " << std::endl;
                std::cin >> person;
                people.addSign(person);
                break;
            case 4:
                std::cout << "Type index to delete: " << std::endl;
                std::cin >> temp;
                people.deleteSign(temp);
                break;
            case 5:
                state = false;
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        std::cout << "Enter path to file: " << std::endl;
        std::cin >> sign;
        smd::Task task;
        task.readAndPrint(sign);
        
        break;
    default:
        break;
    }


    return 0;
}