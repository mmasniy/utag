#include <iomanip>
#include <string>
#include <iostream>
#include <dirent.h>
#include "../../taglib/taglib/tag.h"
#include <../taglib/fileref.h>
#include <toolkit/tpropertymap.h>



int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./utag [dir name]\n";
    }
    DIR *d;
    struct dirent *dr;
    if ((d = opendir(argv[1])) == 0) {
        std::cerr << "Не могу открыть " << argv[1] << "\n";
    }
    int i = 0;
    while ((dr = readdir(d)) != 0) {
        if (i < 2) {
            ++i;
            continue;
        }
        std::cout << dr->d_name << std::endl;
        std::string path = std::string(argv[1]) + "/" + std::string(dr->d_name);
        TagLib::FileRef f(path.c_str());
        if (!f.isNull() && f.tag()) {
            TagLib::Tag *tag = f.tag();
            std::cout << "-- TAG (basic) --" << std::endl;
            std::cout << "title   - \"" << tag->title() << "\"" << std::endl;
            std::cout << "artist  - \"" << tag->artist() << "\"" << std::endl;
            std::cout << "album   - \"" << tag->album() << "\"" << std::endl;
            std::cout << "year    - \"" << tag->year() << "\"" << std::endl;
            std::cout << "comment - \"" << tag->comment() << "\"" << std::endl;
            std::cout << "track   - \"" << tag->track() << "\"" << std::endl;
            std::cout << "genre   - \"" << tag->genre() << "\"" << std::endl;
            std::cout << std::endl;
            TagLib::PropertyMap tags = f.file()->properties();
            unsigned int longest = 0;
            for (TagLib::PropertyMap::ConstIterator i = tags.begin();
                 i != tags.end(); ++i) {
                if (i->first.size() > longest) {
                    longest = i->first.size();
                }
            }
            std::cout << "-- TAG (properties) --" << std::endl;
            for (TagLib::PropertyMap::ConstIterator i = tags.begin();
                 i != tags.end(); ++i) {
                for (TagLib::StringList::ConstIterator j = i->second.begin();
                     j != i->second.end(); ++j) {
                    std::cout << std::left << std::setw(longest) << i->first << " - "
                         << '"' << *j << '"' << std::endl;
                }
            }
        }
        if (!f.isNull() && f.audioProperties()) {
            TagLib::AudioProperties *properties = f.audioProperties();
            int seconds = properties->length() % 60;
            int minutes = (properties->length() - seconds) / 60;
            std::cout << "-- AUDIO --" << std::endl;
            std::cout << "bitrate     - " << properties->bitrate() << std::endl;
            std::cout << "sample rate - " << properties->sampleRate() << std::endl;
            std::cout << "channels    - " << properties->channels() << std::endl;
            std::cout << "length      - " << minutes << ":" << std::setfill('0')
                 << std::setw(2) << seconds << std::endl;
        }
    }
    return 0;
}

/*
 * using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    cout << "******************** \"" << argv[1] << "\" ********************" << endl;
    TagLib::FileRef f(argv[1]);
    if(!f.isNull() && f.tag()) {
        TagLib::Tag *tag = f.tag();
        cout << "-- TAG (basic) --" << endl;
        cout << "title   - \"" << tag->title()   << "\"" << endl;
        cout << "artist  - \"" << tag->artist()  << "\"" << endl;
        cout << "album   - \"" << tag->album()   << "\"" << endl;
        cout << "year    - \"" << tag->year()    << "\"" << endl;
        cout << "comment - \"" << tag->comment() << "\"" << endl;
        cout << "track   - \"" << tag->track()   << "\"" << endl;
        cout << "genre   - \"" << tag->genre()   << "\"" << endl;
        TagLib::PropertyMap tags = f.file()->properties();
        unsigned int longest = 0;
        for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
            if (i->first.size() > longest) {
                longest = i->first.size();
            }
        }
        cout << "-- TAG (properties) --" << endl;
        for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
            for(TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j) {
                cout << std::left << std::setw(longest) << i->first << " - " << '"' << *j << '"' << endl;
            }
        }
    }
    if(!f.isNull() && f.audioProperties()) {
        TagLib::AudioProperties *properties = f.audioProperties();
        int seconds = properties->length() % 60;
        int minutes = (properties->length() - seconds) / 60;
        cout << "-- AUDIO --" << endl;
        cout << "bitrate     - " << properties->bitrate() << endl;
        cout << "sample rate - " << properties->sampleRate() << endl;
        cout << "channels    - " << properties->channels() << endl;
        cout << "length      - " << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << endl;
    }
    return 0;
}
 */

/*

if (argc != 2) {
return 1;
}
cout << "******************** \"" << argv[1] << "\" ********************" << endl;







TagLib::PropertyMap tags = f.file()->properties();

unsigned int longest = 0;
for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
if (i->first.size() > longest) {
longest = i->first.size();
}
}

cout << "-- TAG (properties) --" << endl;
for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
for(TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j) {
cout << std::left << std::setw(longest) << i->first << " - " << '"' << *j << '"' << endl;
}
}

}

if(!f.isNull() && f.audioProperties()) {

TagLib::AudioProperties *properties = f.audioProperties();

int seconds = properties->length() % 60;
int minutes = (properties->length() - seconds) / 60;

cout << "-- AUDIO --" << endl;
cout << "bitrate     - " << properties->bitrate() << endl;
cout << "sample rate - " << properties->sampleRate() << endl;
cout << "channels    - " << properties->channels() << endl;
cout << "length      - " << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << endl;
}
*/
