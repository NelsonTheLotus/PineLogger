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
        std::ostream *ouputSource;

    public:
        Buffer(std::ostream *output);
        ~Buffer();

        static int immediateLog(std::string message, std::ostream& outputStream);
        
    };
}