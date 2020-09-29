#include "FileTag.h"

FileTags::FileTags(const std::string &path, QString &fileName) {
    std::string fullPath(path + fileName.toStdString());
    this->setInfo("filename", fileName);
    this->setInfo("path", QString::fromStdString(fullPath));
    TagLib::FileRef f(fullPath.c_str());
    fileRef = f;
    if (!f.isNull() && f.tag()) {
        TagLib::Tag *tag = f.tag();
        this->setInfo("title", tag->title().toCString());
        this->setInfo("artist", tag->artist().toCString());
        this->setInfo("album", tag->album().toCString());
        this->setInfo("genre", tag->genre().toCString());
        this->setInfo("year", QString::number(tag->year()));
        this->setInfo("track_number", QString::number(tag->track()));
    }
}

std::ostream &operator<<(std::ostream &out, const FileTags &file) {
    for(const auto& [key, value] : file.getAllInfo()) {
        std::cout << key << ": " << value.toStdString() << std::endl;
    }
    return out;
}

void FileTags::setInfo(const std::string &tag, const QString &info) {
    m_file_tags[tag] = info;
}

QString FileTags::getTag(const std::string &tag){
    return m_file_tags[tag];
}

std::map<std::string, QString> FileTags::getAllInfo() const {
    return m_file_tags;
}

void FileTags::upgradeFileTags(const FileTags &new_tags) {
    TagLib::FileRef file(new_tags.getAllInfo()["path"].toStdString().c_str());
    file.tag()->setTitle(new_tags.getAllInfo()["title"].toStdString());
    setInfo("title", new_tags.getAllInfo()["title"]);
    file.tag()->setArtist(new_tags.getAllInfo()["artist"].toStdString());
    setInfo("artist", new_tags.getAllInfo()["artist"]);
    file.tag()->setAlbum(new_tags.getAllInfo()["album"].toStdString());
    setInfo("album", new_tags.getAllInfo()["album"]);
    file.tag()->setGenre(new_tags.getAllInfo()["genre"].toStdString());
    setInfo("genre", new_tags.getAllInfo()["genre"]);
    file.tag()->setYear(new_tags.getAllInfo()["year"].toInt());
    setInfo("year", new_tags.getAllInfo()["year"]);
    file.tag()->setTrack(new_tags.getAllInfo()["track_number"].toInt());
    setInfo("track_number", new_tags.getAllInfo()["track_number"]);
    file.save();
}


//void FileTags::setLyrics(const std::string& sPath) {
//    TagLib::MPEG::File file(fullPath(m_path, const_cast<char *>(m_name.c_str())).c_str());
//    TagLib::ID3v2::FrameList frames = file.ID3v2Tag()->frameListMap()["USLT"];
//    TagLib::ID3v2::UnsynchronizedLyricsFrame *frame = new TagLib::ID3v2::UnsynchronizedLyricsFrame;

//    file.ID3v2Tag()->removeFrames(file.ID3v2Tag()->frameListMap()["USLT"].front()->frameID());
//    frame->setText(lyrics);
//    file.ID3v2Tag()->addFrame(frame);
//    file.save();
//}

/*
 *void Element::lyricsSet(std::string lyrics) {
    TagLib::MPEG::File file(fullPath(m_path, const_cast<char *>(m_name.c_str())).c_str());
    TagLib::ID3v2::FrameList frames = file.ID3v2Tag()->frameListMap()["USLT"];
    TagLib::ID3v2::UnsynchronizedLyricsFrame *frame =
        new TagLib::ID3v2::UnsynchronizedLyricsFrame;

    file.ID3v2Tag()->removeFrames(file.ID3v2Tag()->frameListMap()["USLT"].front()->frameID());
    frame->setText(lyrics);
    file.ID3v2Tag()->addFrame(frame);
    file.save();
}
*/
