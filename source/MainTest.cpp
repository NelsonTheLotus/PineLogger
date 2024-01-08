#include "PineLog.hpp"

#include <string>
#include <iostream>
#include <exception>

int main()
{
    pine::Piner newLoggerDebug = pine::Piner("newLogger");
    newLoggerDebug.log("Test Message.");


    /* newLoggerDebug.backlog("testmessage");

    newLoggerDebug << "test message"; */

    //DONE: Added frame message generation
    //TODO: Add name selection for the Piner (logger)
    return 0;
}