#pragma once

#include <string>

namespace videoserver
{
    class client
    {
        public:
            client(const std::string& ip, const unsigned short& port);
    }; // class client
    
} // namespace videoserver
