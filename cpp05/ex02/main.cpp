#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "forms/ShrubberyCreationForm.hpp"
#include "forms/RobotomyRequestForm.hpp"
#include "forms/PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    try
    {
        std::cout << "===== Bureaucrats =====" << std::endl;

        Bureaucrat low("Low", 140);
        Bureaucrat mid("Mid", 50);
        Bureaucrat boss("Boss", 1);

        std::cout << low << std::endl;
        std::cout << mid << std::endl;
        std::cout << boss << std::endl;

        std::cout << "\n===== Forms =====" << std::endl;

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n===== SIGNING =====" << std::endl;

        low.signForm(shrub);
        mid.signForm(robot);
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        std::cout << "\n===== EXECUTION =====" << std::endl;

        low.executeForm(shrub);     // should fail
        mid.executeForm(robot);     // maybe fail
        boss.executeForm(shrub);    // success
        boss.executeForm(robot);    // random
        boss.executeForm(pardon);   // success

        std::cout << "\n===== DIRECT EXECUTE TEST =====" << std::endl;

        shrub.execute(boss);
        robot.execute(boss);
        pardon.execute(boss);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
