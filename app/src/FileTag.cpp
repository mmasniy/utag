#include "FileTag.h"
//
//FileTags::FileTags(const std::string &path, const std::string &fileName) {
//    std::string fullPath(path + fileName);
//    this->setInfo("filename", fileName);
//    this->setInfo("path", fullPath);
//    TagLib::FileRef f(fullPath.c_str());
//    fileRef = f;
//    if (!f.isNull() && f.tag()) {
//        TagLib::Tag *tag = f.tag();
//        this->setInfo("title", tag->title().toCString());
//        this->setInfo("artist", tag->artist().toCString());
//        this->setInfo("album", tag->album().toCString());
//        this->setInfo("comment", tag->comment().toCString());
//        this->setInfo("genre", tag->genre().toCString());
//    }
//}
//
//std::ostream &operator<<(std::ostream &out, const FileTags &file) {
//    for(const auto& [key, value] : file.getAllInfo()) {
//        std::cout << key << ": " << value << std::endl;
//    }
//    return out;
//}
//
//void FileTags::setInfo(const std::string &tag, const std::string &info) {
//    m_file_tags[tag] = info;
//}
//std::string FileTags::getTag(const std::string &tag){
//    return m_file_tags[tag];
//}
//std::map<std::string, std::string> FileTags::getAllInfo() const {
//    return m_file_tags;
//}
//void FileTags::upgradeFileTags(const FileTags &new_tags) {
//    TagLib::Tag *tag = fileRef.tag();
//    tag->setTitle(new_tags.getAllInfo()["title"]);
//    setInfo("title", new_tags.getAllInfo()["title"]);
//    tag->setArtist(new_tags.getAllInfo()["artist"]);
//    setInfo("artist", new_tags.getAllInfo()["artist"]);
//    tag->setAlbum(new_tags.getAllInfo()["album"]);
//    setInfo("album", new_tags.getAllInfo()["album"]);
//    tag->setComment(new_tags.getAllInfo()["comment"]);
//    setInfo("comment", new_tags.getAllInfo()["comment"]);
//    tag->setGenre(new_tags.getAllInfo()["genre"]);
//    setInfo("genre", new_tags.getAllInfo()["genre"]);
//}
