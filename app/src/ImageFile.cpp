#include "ImageFile.h"

TagLib::ByteVector ImageFile::data() {
    return readBlock(length());
}

TagLib::Tag *ImageFile::tag() const {
    return 0;
}

TagLib::AudioProperties *ImageFile::audioProperties() const {
    return 0;
}

bool ImageFile::save() {
    return false;
}

ImageFile::ImageFile(const char *file) : TagLib::File(file) {
}
