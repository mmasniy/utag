#pragma once
#include <iostream>
#include <string>
#include <map>

class FileTag {
    public:
    void setInfo(const std::string& tag, const std::string& info) {
        m_info_about_file[tag] = info;
    }
    std::map<std::string, std::string> getInfoAboutFile() {
        return m_info_about_file;
    }
    private:
    std::map<std::string, std::string> m_info_about_file;
    /*
    std::string file_name;
    std::string song_name;
    std::string artist;
    std::string title;
    std::string album;
    std::string genre;
    std::string audioFilePath;
    std::string type;
    std::string year;
    std::string track_number;
    */
};
