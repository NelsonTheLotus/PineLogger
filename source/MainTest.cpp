#include "PineLog.hpp"

#include <string>
#include <iostream>
#include <exception>

int main()
{
    pine::Piner newLoggerDebug = pine::Piner("hiItsAMeMario");
    newLoggerDebug.log("Test Message.");
    newLoggerDebug.log("Test Message.");
    newLoggerDebug.log("Test Message.");

    //DONE: add log output selection
    //TODO: add ostream selection for Buffer through PineLogger
    return 0;
}