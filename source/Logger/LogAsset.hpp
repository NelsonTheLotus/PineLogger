#pragma once

#include "../Pine/Settings.hpp"
#include "../Pine/Types.hpp"

#include <memory>


namespace pine
{
    class Piner;
    class Frame;
    class Buffer;

    typedef struct LogContext
    {
        log_type logType;
        log_level logLevel;
        std::string sourceName;

        /* thread
        time 
        ... */
    }LogContext;

    typedef struct LogPath
    {
        std::unique_ptr<Piner> logSource;
        std::shared_ptr<Frame> logFrame;
        std::shared_ptr<Buffer> logBuffer;

        /* Stream 
        loggerName
        ... */
        
    }LogPath;
}