#pragma once
#include "../Pine/PineLib.hpp"

#include <vector>
#include <string>
#include <iostream>

namespace pine
{
    class Buffer
    {
    private:

    public:
        Buffer();
        ~Buffer();

        static int immediateLog(std::string message, std::ostream& outputStream);
        
    };
}