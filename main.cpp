/*
** EPITECH PROJECT, 2024
** papaya
** File description:
** library
*/

#include "Papaya.hpp"

int main(void)
{
    std::vector<std::string> keys = {"name", "age", "job"};
    Papaya papaya("data/", "people", keys);
    papaya.addLine({"Jane", "22", "designer"});
    papaya.view();
    papaya.removeData("name", "John", "name");
    std::cout << std::endl;
    std::cout << std::endl;
    papaya.view();
    papaya.updateLine("name", "Jane", {"Jane", "23", "Designer"});
    std::cout << std::endl;
    std::cout << std::endl;
    papaya.view();
    papaya.addLine({"Pedro", "42", "Developper"});
    std::cout << std::endl;
    std::cout << std::endl;
    papaya.view();
    papaya.save();
    return 0;
}
