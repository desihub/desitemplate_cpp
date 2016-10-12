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
    //
    // Test parse_version()
    //
    std::string version1("1.2.3.4");
    std::string version2("1.2.3.5");
    int parse_version_result[4];
    desitemplate::parse_version(parse_version_result, version1);
    for (int i = 0; i < 4; i++) assert(parse_version_result[i] == i+1);
    //
    // Test compare_version()
    //
    assert(desitemplate::compare_version(version1, version2));
    assert(!desitemplate::compare_version(version2, version1));
    //
    // Make sure dummy svn repo is available.
    //
    char* travis_build_dir = getenv("TRAVIS_BUILD_DIR");
    if (travis_build_dir != NULL) {
        //
        // Test most_recent_svn_tag()
        //
        std::string travis(travis_build_dir);
        std::string svnTags = "file://" + travis + "/svn/tags";
        assert(desitemplate::most_recent_svn_tag(svnTags) == "1.1.0");
        // std::cout << desitemplate::most_recent_svn_tag(svnTags) << std::endl;
        //
        // Test an empty directory.
        //
        std::string svnBranches =  "file://" + travis + "/svn/branches";
        assert(desitemplate::most_recent_svn_tag(svnBranches) == "0.0.1");
        // std::cout << desitemplate::most_recent_svn_tag(svnBranches) << std::endl;
        //
        // Test get_svn_devstr()
        //
        assert(desitemplate::get_svn_devstr("desitemplate_cpp") == "2");
        // std::cout << desitemplate::get_svn_devstr("desitemplate_cpp") << std::endl;
        //
        // Test svn_version() with dummy repo.
        //
        std::string branchURL = "$HeadURL: file://" + travis + "/svn/branches/test-coverage/src/main.cpp $";
        std::cout << "Test SVN branch version: " << desitemplate::svn_version(branchURL) << std::endl;
        std::string trunkURL = "$HeadURL: file://" + travis + "/svn/trunk/src/main.cpp $";
        // std::cout << "Test SVN trunk version: " << desitemplate::svn_version(trunkURL) << std::endl;
    }
    //
    // Test svn_version()
    //
    std::string tagURL("$HeadURL: https://desi.lbl.gov/svn/code/tools/desitemplate_cpp/tags/0.0.2/src/main.cpp $");
    assert(desitemplate::svn_version(tagURL) == "0.0.2");
    // std::cout << "Test SVN tag version: " << desitemplate::svn_version(tagURL) << std::endl;
    //
    // Test version()
    //
    assert(desitemplate::version() == VERSION_STRING);
    // std::cout << "Test GIT version: " << desitemplate::version() << std::endl;
    return 0;
}
