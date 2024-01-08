#include "../Pine/PineLib.hpp"
#include "Message.hpp"

#include <string>

namespace pine
{
    Message::Message(std::string text, LogContext msgCtx, LogPath msgPath)
    : textMessage(text), logCtx(msgCtx), logPath(msgPath)
    {
        return;
    }

    Message::~Message()
    {
        return;
    }

    temp_stat_int Message::setText(std::string newText)
    {
        this->textMessage = newText;
        return 0;
    }

    temp_stat_int Message::setLogCtx(LogContext newCtx)
    {
        this->logCtx = newCtx;
        return 0;
    }

    temp_stat_int Message::setLogPath(LogPath newPath)
    {
        this->logPath = newPath;
        return 0;
    }
}