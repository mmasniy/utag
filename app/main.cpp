#include <iomanip>
#include <iostream>
//#include "tag.h"

//#include "../taglib/tag.h"
#include "../../taglib/taglib/tag.h"
#include <../taglib/fileref.h>
#include <toolkit/tpropertymap.h>
// #include <tkDecls.h>

//#include <../taglib/tpropertymap.h>


using std::cout;
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

