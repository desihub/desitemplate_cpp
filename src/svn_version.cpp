/// \file svn_version.cpp
///
/// \brief Defines desitemplate::svn_version().
///
#include "template.hpp"
//
//
//
std::string desitemplate::svn_version(const std::string& headurl)
{
    std::string defaultVersion("0.0.1.dev");
    std::string url = headurl.substr(10,headurl.length()-12); // Strip $HeadURL stuff.
    std::size_t found = url.find("tags");
    if (found != std::string::npos) {
        std::string tag = url.substr(found+5);
        return tag.substr(0,tag.find("/"));
    } else {
        found = url.find("branches");
        if (found != std::string::npos) {
            std::string baseurl = url.substr(0,found-1);
            std::size_t slash = baseurl.find_last_of("/")+1;
            std::string product = url.substr(slash,baseurl.length()-slash);
            std::string tagurl = baseurl + "/tags";
            return desitemplate::most_recent_svn_tag(tagurl)+".dev"+desitemplate::get_svn_devstr(product);
        } else {
            found = url.find("trunk");
            if (found != std::string::npos) {
                std::string baseurl = url.substr(0,found-1);
                std::size_t slash = baseurl.find_last_of("/")+1;
                std::string product = url.substr(slash,baseurl.length()-slash);
                std::string tagurl = baseurl + "/tags";
                return desitemplate::most_recent_svn_tag(tagurl)+".dev"+desitemplate::get_svn_devstr(product);
            } else {
                return defaultVersion;
            }
        }
    }
}
