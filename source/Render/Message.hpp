#pragma once

#include "../Pine/Settings.hpp"
#include "../Pine/Types.hpp"

#include <memory>
#include <string>

//FORWARD DECALRE ONLY
/* #include "../Render/Frame.hpp"
#include "../Storage/Buffer.hpp"
#include "../Storage/Stream.hpp" */

class pine::Frame;
class pine::Buffer;
class pine::Stream;


namespace pine
{
    typedef struct LogContext
    {
        log_type logType;
        log_level logLevel;

        /* thread
        time 
        ... */
    }LogContext;

    typedef struct LogPath
    {
        std::shared_ptr<Frame> logFrame;
        std::shared_ptr<Buffer> logBuffer;

        /* Stream 
        ... */
        
    }LogPath;


    class Message
    {
    private:
        std::string textMessage;

        LogContext logCtx;
        LogPath logPath;

    public:
        Message(std::string text, LogContext msgCtx = {log_type::trace, log_level::info}, LogPath msgPath = {nullptr, nullptr});
        ~Message();

        temp_stat_int setText(std::string newText);
        temp_stat_int setLogCtx(LogContext newCtx);
        temp_stat_int setLogPath(LogPath newPath);
    };
}