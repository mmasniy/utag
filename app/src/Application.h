#pragma once
#include "FileTag.h"

class FileTags;

class Application {
    public:
    void setFileToInfo(const FileTags& infoAboutFile);
    void setTag(const std::string& nameOfFile, const std::string& nameOfTag, const std::string& content);
    std::vector<FileTags>& getTagsInfo();
    void printInfo();
    private:
    std::vector<FileTags> m_info;
};
