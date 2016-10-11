/// \file most_recent_svn_tag.cpp
///
/// \brief Defines desitemplate::most_recent_svn_tag().
///
#include "template.hpp"
//
//
//
std::string desitemplate::most_recent_svn_tag(const std::string& tags)
{
    std::list<std::string> taglist;
    std::string notag("0.0.1");
    std::string command = "svn ls " + tags;
    FILE *in;
    char buff[512];
    if (!(in = popen(command.c_str(),"r"))) return notag;
    while (fgets(buff, sizeof(buff), in) != NULL) {
        std::string tmp = buff;
        tmp.erase(tmp.find_last_not_of("/ \n\r\t")+1);
        taglist.push_back(tmp);
    }
    pclose(in);
    if (taglist.size() > 0 && taglist.front().length() > 0) {
        taglist.sort(desitemplate::compare_version);
        return taglist.back();
    } else {
        return notag;
    }
}
