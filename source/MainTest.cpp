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

    //DONE: Add name selection for the Piner (logger)
    //TODO: add log output selection
    return 0;
}