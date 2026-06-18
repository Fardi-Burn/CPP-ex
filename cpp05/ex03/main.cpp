#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "forms/ShrubberyCreationForm.hpp"
#include "forms/RobotomyRequestForm.hpp"
#include "forms/PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    try
    {
        std::cout << "===== Bureaucrats =====" << std::endl;

        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 40);
        Bureaucrat low("Low", 140);

        std::cout << boss << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        std::cout << "\n===== Intern =====" << std::endl;

        Intern intern;

        std::cout << "\n===== FORM CREATION =====" << std::endl;

        AForm *f1 = intern.makeForm("ShrubberyCreationForm", "home");
        AForm *f2 = intern.makeForm("RobotomyRequestForm", "Marvin");
        AForm *f3 = intern.makeForm("PresidentialPardonForm", "Arthur Dent");

        std::cout << "\n===== INVALID FORM =====" << std::endl;

        AForm *f4 = intern.makeForm("UnknownForm", "test");

        std::cout << "\n===== SIGNING =====" << std::endl;

        if (f1) low.signForm(*f1);
        if (f2) mid.signForm(*f2);
        if (f3) boss.signForm(*f3);

        std::cout << "\n===== EXECUTION =====" << std::endl;

        if (f1) boss.executeForm(*f1);
        if (f2) boss.executeForm(*f2);
        if (f3) boss.executeForm(*f3);

        std::cout << "\n===== DIRECT EXECUTION TEST =====" << std::endl;

        if (f1) f1->execute(boss);
        if (f2) f2->execute(boss);
        if (f3) f3->execute(boss);

        std::cout << "\n===== CLEANUP =====" << std::endl;

        delete f1;
        delete f2;
        delete f3;
        delete f4;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
