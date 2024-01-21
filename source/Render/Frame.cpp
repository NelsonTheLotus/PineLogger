#include "../Pine/PineLib.hpp"
#include "Frame.hpp"

#include <string>
#include <array>
#include <algorithm>
#include <vector>
//TEMPO
#include <iostream>

namespace pine
{
    
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

    TokenUnit nameToken = {"name", getNameString};
    TokenUnit typeToken = {"type", getTypeString};
    TokenUnit levelToken = {"level", getLevelString};
    TokenUnit textToken = {"text", nullptr};
    std::array<TokenUnit, 4> unitTokens = {nameToken, typeToken, levelToken, textToken};

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
        //Index all units to replace
        this->replaceUnits.clear();
        for(auto token : unitTokens)
        {
            std::string unitString = char(format_chars::openFormat) + token.tokenName + char(format_chars::closeFormat);
            int tokenLength = unitString.length();
            std::string::size_type searchStartPos = 0;
            std::string::size_type nextUnitPos = newSkel.find(unitString, searchStartPos);
           
            while(std::string::npos != nextUnitPos)
            {
                //Check for no escape char
                int escapeFormat = nextUnitPos-1;
                if((0 > escapeFormat) || (format_chars::escapeFormat != newSkel[escapeFormat]))
                {
                    //set a unit index
                    ReplaceUnit newUnitIndex = {tokenLength, nextUnitPos, token.toStringFunc};
                    this->replaceUnits.push_back(newUnitIndex);
                }

                searchStartPos = nextUnitPos + unitString.length();
                nextUnitPos = newSkel.find(unitString, searchStartPos);
            }
        }

        //sort so that generation can replace in order of appearance
        std::sort(this->replaceUnits.begin(), this->replaceUnits.end(), [](ReplaceUnit &unitA, ReplaceUnit &unitB){return unitA.replacePos<unitB.replacePos;});
        int replacePosOffset = 0;

        //erase the tokens inside the skeleton and update the replace position
        for(auto &unit : this->replaceUnits)
        {
            unit.replacePos += replacePosOffset;
            newSkel.erase(unit.replacePos, unit.tokenLength);
            replacePosOffset -= unit.tokenLength;
            unit.tokenLength = 0;
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