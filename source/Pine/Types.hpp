#pragma once
// DO NOT INCLUDE PineLib.hpp !!!

namespace pine
{
    typedef enum log_type : int 
    {
        pine,
        system,
        trace,
        debug,
        app,
        user
    }log_type;

    typedef enum log_level : int 
    {
        fatal,
        critical,
        warning,
        info,
        event
    }log_level;

    //Used to return a function success status. May be ignored.
    typedef enum status_void : int 
    {
        success = EXIT_SUCCESS,
        failure = EXIT_FAILURE,
        EXIT
    }status_void;

    typedef int temp_stat_int;
}