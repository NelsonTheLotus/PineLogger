#pragma once
#include "../Pine/PineLib.hpp"

#include <string>
#include <vector>
#include <array>

#include "../Logger/LogAsset.hpp"

namespace pine
{   
    //PINE_CORE
    typedef struct ReplaceUnit
    {
        std::string::size_type replacePos;
        std::string (*tokenToString)(LogContext);
    }ReplaceUnit;

    typedef enum format_chars : char 
    {
        openFormat = '[',
        closeFormat = ']',
        escapeFormat = '!'
    }format_char;

    //tokenToString functions
    std::string getTypeString(LogContext textCtx);
    std::string getLevelString(LogContext textCtx);
    std::string getNameString(LogContext textCtx);

    class Frame
    {
    private:
        std::string skeleton;
        std::vector<ReplaceUnit> replaceUnits;

    public:
        /* Frame(std::string skeleton = "[level]: [type] -> [text]"); */
        Frame(std::string skeleton = "[type] - [level]: [text]");
        ~Frame();
        temp_stat_int setSkeleton(std::string newSkel);

        std::string generateMessage(std::string text, LogContext textCtx);
    };
}