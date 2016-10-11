/// \file main.cpp
///
/// \brief Defines main().
///
/// This file defines a main() function that forms the basis of a command-line
/// executable.
///
#include "template.hpp"
///
/// \brief Main program.
///
/// This function only exists to call desitemplate::version() and print its return value.
///
/// Note that the documentation for this function is here, rather than in
/// template.hpp, because main is not part of the namespace.  Nor is the
/// declaration of main() needed by the other functions.
///
/// \param argc Number of command line options.
/// \param argv The command line options.
///
/// \return The exit status that will be returned to the shell.
///
int main(int argc, char **argv)
{
    std::string tagURL("$HeadURL: https://desi.lbl.gov/svn/code/tools/desitemplate_cpp/tags/0.0.2/src/main.cpp $");
    std::string branchURL("$HeadURL: https://desi.lbl.gov/svn/code/tools/desitemplate_cpp/branches/test-coverage/src/main.cpp $");
    std::string trunkURL("$HeadURL: https://desi.lbl.gov/svn/code/tools/desitemplate_cpp/trunk/src/main.cpp $");
    std::cout << "Test SVN tag version: " << desitemplate::svn_version(tagURL) << std::endl;
    // std::cout << "Test SVN branch version: " << desitemplate::svn_version(branchURL) << std::endl;
    // std::cout << "Test SVN trunk version: " << desitemplate::svn_version(branchURL) << std::endl;
    std::cout << "Test GIT version: " << desitemplate::version() << std::endl;
    return 0;
}
