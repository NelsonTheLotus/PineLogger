#include "../Pine/PineLib.hpp"
#include "Frame.hpp"

#include <string>
#include <array>
//TEMPO
#include <iostream>

namespace pine
{
    std::array<std::string, 4> replaceableUnitNames = {"type", "level", "name", "text"};

    std::string getTypeString(LogContext textCtx)
    {
        std::string typeString = "Uknown";
        switch (textCtx.logType)
        {
        case log_type::pine: typeString = "pine"; break;
        case log_type::system: typeString = "system"; break;
        case log_type::trace: typeString = "trace"; break;
        case log_type::debug: typeString = "debug"; break;
        case log_type::app: typeString = "app"; break;
        case log_type::user: typeString = "user"; break;
        
        default:
            break;
        }

        return typeString;
    }

    std::string getLevelString(LogContext textCtx)
    {
        std::string levelString = "Uknown";
        switch (textCtx.logType)
        {
        case log_level::fatal: levelString = "fatal"; break;
        case log_level::critical: levelString = "critical"; break;
        case log_level::warning: levelString = "warning"; break;
        case log_level::info: levelString = "info"; break;
        case log_level::event: levelString = "event"; break;
        
        default:
            break;
        }

        return levelString;
    }

    std::string getNameString(LogContext textCtx)
    {
        return textCtx.sourceName;
    }


    Frame::Frame(std::string skeleton)
    {
        this->setSkeleton(skeleton);
        return;
    }

    Frame::~Frame()
    {
        return;
    }

    temp_stat_int Frame::setSkeleton(std::string newSkel)
    {
        int tokenNameIndex = 0;
        for(auto tokenString : replaceableUnitNames)
        {
            //TODO: OPTIMZE
            std::string unitString = char(format_chars::openFormat) + tokenString + char(format_chars::closeFormat);
            std::string::size_type searchStartPos = 0;
            std::string::size_type nextUnitPos = newSkel.find(unitString, searchStartPos);
            while(std::string::npos != nextUnitPos)
            {
                //check for escape char
                int escapeFormat = nextUnitPos-1;
                if(0 <= escapeFormat) 
                {
                    if(newSkel[escapeFormat] == format_chars::escapeFormat) 
                    {
                        searchStartPos = nextUnitPos + unitString.length();
                        nextUnitPos = newSkel.find(unitString, searchStartPos);
                        continue;
                    }
                }

                    //no match found
                std::string (*tokenToString)(LogContext);
                switch (tokenNameIndex)
                {
                    case 0: tokenToString = getTypeString; break;
                    case 1: tokenToString = getLevelString; break;
                    case 2: tokenToString = getNameString; break;
                    case 3:
                    default: tokenToString = nullptr; break;
                }

                newSkel.erase(nextUnitPos, unitString.length());
                ReplaceUnit newReplaceUnit = {nextUnitPos, tokenToString};
                this->replaceUnits.push_back(newReplaceUnit);

                nextUnitPos = newSkel.find(unitString, searchStartPos);
            }
            tokenNameIndex++;
        }
        this->skeleton = newSkel;
        return 0;
    }

    std::string Frame::generateMessage(std::string message, LogContext textCtx)
    {
        std::string newMessage = this->skeleton;
        int replaceOffset = 0;

        for(auto replaceUnit : this->replaceUnits)
        {
            std::string replaceText = message;
            if(replaceUnit.tokenToString != nullptr)
            {
                replaceText = replaceUnit.tokenToString(textCtx);
            }

            newMessage.insert(replaceUnit.replacePos + replaceOffset, replaceText);
            replaceOffset += replaceText.length();
        }

        return newMessage;
    }

}