#pragma once
#include "../Pine/PineLib.hpp"

#include <vector>
#include <string>
#include <iostream>


namespace pine
{
    class Stream
    {
    private:


    public:
        Stream(std::ostream* outputStream);
        ~Stream();
    };
}