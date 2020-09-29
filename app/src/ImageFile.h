#pragma once

#include "taglib_config.h"
#include "tfile.h"
#include "fileref.h"
#include "tag.h"
#include "tpropertymap.h"
#include "id3v2tag.h"
#include "id3v2frame.h"
#include "id3v2header.h"
#include "mpegfile.h"
#include "attachedpictureframe.h"
#include "unsynchronizedlyricsframe.h"
#include "synchronizedlyricsframe.h"


class ImageFile : public TagLib::File {
public:
    explicit ImageFile(const char* file);
    TagLib::ByteVector data();

protected:
    [[nodiscard]] TagLib::Tag *tag() const override;
    [[nodiscard]] TagLib::AudioProperties *audioProperties() const override;
    bool save() override;

private:
    static ImageFile *singleton;
};
