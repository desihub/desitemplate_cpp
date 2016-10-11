/// \file compare_version.cpp
///
/// \brief Defines desitemplate::compare_version().
///
#include "template.hpp"
//
//
//
bool desitemplate::compare_version(const std::string& a, const std::string& b)
{
    int parsedA[4], parsedB[4];
    desitemplate::parse_version(parsedA, a);
    desitemplate::parse_version(parsedB, b);
    return std::lexicographical_compare(parsedA, parsedA + 4, parsedB, parsedB + 4);
}
//
// int main(int argc, char **argv) {
//     std::string first(argv[1]);
//     std::string second(argv[2]);
//     std::string op = desitemplate::compare_version(first,second) ? " < " : " > ";
//     std::cout << first << op << second << std::endl;
//     return 0;
// }
