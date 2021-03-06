/// \file parse_version.cpp
///
/// \brief Defines desitemplate::parse_version().
///
#include "template.hpp"
//
//
//
void desitemplate::parse_version(int result[4], const std::string& input)
{
    std::istringstream parser(input);
    parser >> result[0];
    for(int idx = 1; idx < 4; idx++)
    {
        parser.get(); // Skip period
        parser >> result[idx];
    }
}
