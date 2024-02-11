#include "../Pine/PineLib.hpp"
#include "Buffer.hpp"

#include <string>
#include <iostream>

namespace pine
{
    Buffer::Buffer()
    {
        return;
    }

    Buffer::~Buffer()
    {
        return;
    }

    temp_stat_int Buffer::immediateLog(std::string message, std::ostream& outputStream)
    {
        outputStream << message << std::endl;
        return 0;
    }
}