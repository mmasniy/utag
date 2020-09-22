#pragma once
#include <iostream>
#include <iomanip>
#include <dirent.h>
#include <string>
#include <map>

#include "../../taglib/taglib/tag.h"
#include <../taglib/fileref.h>
#include <toolkit/tpropertymap.h>
#include <QString>

class FileTags {
    public:
    FileTags(const std::string& path, QString& fileName);
//    ~FileTags();
    void setInfo(const std::string& tag, const QString& info);
    QString getTag(const std::string& tag);
    [[nodiscard]] std::map<std::string, QString> getAllInfo() const;
    void upgradeFileTags(const FileTags& new_tags);
    friend std::ostream& operator<<(std::ostream& out, const FileTags& file);
    private:
    TagLib::FileRef fileRef;
    std::map<std::string, QString> m_file_tags;
};
