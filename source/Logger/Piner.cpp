#include "../Pine/PineLib.hpp"
#include "Piner.hpp"

//TEMPORARY FOR DEBUG
// -
#include <string>

#include "LogAsset.hpp"
#include "../Render/Frame.hpp"
#include "../Storage/Buffer.hpp"

namespace pine
{
    Piner::Piner(std::string name, log_type pinerType, log_level pinerLevel)
    : name(name), logType(pinerType), logLevel(pinerLevel)
    {
        this->logFrame = std::make_shared<Frame>(Frame());
        this->logBuffer = std::make_shared<Buffer>(Buffer());

        return;
    };

    Piner::~Piner()
    {
        return;
    };

    int Piner::log(std::string text)
    {
        LogContext msgCtx = {this->logType, this->logLevel, this->name};
        std::string message = this->logFrame->generateMessage(text, msgCtx);
        Buffer::immediateLog(message, std::cout);

        return 0;
    }
}