#pragma once

#include <fstream>
#include <iostream>

std::string readFile(const char* name)
{
    std::fstream file(name);
    std::string result = "";
    std::string temp;
    while (std::getline(file, temp))
        result += temp + '\n';

    return result;
}
