#pragma once

#include <string>
#include <memory>

#include "LogAsset.hpp"

#include "../Pine/Settings.hpp"
#include "../Pine/Types.hpp"

#include "../Render/Frame.hpp"

#include "../Storage/Buffer.hpp"
#include "../Event/Manager.hpp"

namespace pine
{
    //Structure used to store all class instance of a logger
    

    class Piner
    {
    private:
        //LogContext vars
        std::string name;
        log_type logType;
        log_level logLevel;

        //LogPath vars
        std::shared_ptr<Frame> logFrame;
        std::shared_ptr<Buffer> logBuffer;
    
    public:
        Piner(std::string name, log_type pinerType = log_type::debug, log_level pinerLevel = log_level::info);
        ~Piner();

        //set/get Name, logLevel, logType

        temp_stat_int log(std::string text);

        //TODO: static logging functions
    };
}