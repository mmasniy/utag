# Install script for directory: /Users/mmasniy/Desktop/utag/3dparty/taglib/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/mmasniy/.brew")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/mmasniy/.brew/lib/libtag.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/mmasniy/.brew/lib" TYPE STATIC_LIBRARY FILES "/Users/mmasniy/Desktop/utag/build/3dparty/taglib/taglib/libtag.a")
  if(EXISTS "$ENV{DESTDIR}/Users/mmasniy/.brew/lib/libtag.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/mmasniy/.brew/lib/libtag.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}/Users/mmasniy/.brew/lib/libtag.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/mmasniy/.brew/include/taglib/tag.h;/Users/mmasniy/.brew/include/taglib/fileref.h;/Users/mmasniy/.brew/include/taglib/audioproperties.h;/Users/mmasniy/.brew/include/taglib/taglib_export.h;/Users/mmasniy/.brew/include/taglib/taglib_config.h;/Users/mmasniy/.brew/include/taglib/taglib.h;/Users/mmasniy/.brew/include/taglib/tstring.h;/Users/mmasniy/.brew/include/taglib/tlist.h;/Users/mmasniy/.brew/include/taglib/tlist.tcc;/Users/mmasniy/.brew/include/taglib/tstringlist.h;/Users/mmasniy/.brew/include/taglib/tbytevector.h;/Users/mmasniy/.brew/include/taglib/tbytevectorlist.h;/Users/mmasniy/.brew/include/taglib/tbytevectorstream.h;/Users/mmasniy/.brew/include/taglib/tiostream.h;/Users/mmasniy/.brew/include/taglib/tfile.h;/Users/mmasniy/.brew/include/taglib/tfilestream.h;/Users/mmasniy/.brew/include/taglib/tmap.h;/Users/mmasniy/.brew/include/taglib/tmap.tcc;/Users/mmasniy/.brew/include/taglib/tpropertymap.h;/Users/mmasniy/.brew/include/taglib/trefcounter.h;/Users/mmasniy/.brew/include/taglib/tdebuglistener.h;/Users/mmasniy/.brew/include/taglib/mpegfile.h;/Users/mmasniy/.brew/include/taglib/mpegproperties.h;/Users/mmasniy/.brew/include/taglib/mpegheader.h;/Users/mmasniy/.brew/include/taglib/xingheader.h;/Users/mmasniy/.brew/include/taglib/id3v1tag.h;/Users/mmasniy/.brew/include/taglib/id3v1genres.h;/Users/mmasniy/.brew/include/taglib/id3v2.h;/Users/mmasniy/.brew/include/taglib/id3v2extendedheader.h;/Users/mmasniy/.brew/include/taglib/id3v2frame.h;/Users/mmasniy/.brew/include/taglib/id3v2header.h;/Users/mmasniy/.brew/include/taglib/id3v2synchdata.h;/Users/mmasniy/.brew/include/taglib/id3v2footer.h;/Users/mmasniy/.brew/include/taglib/id3v2framefactory.h;/Users/mmasniy/.brew/include/taglib/id3v2tag.h;/Users/mmasniy/.brew/include/taglib/attachedpictureframe.h;/Users/mmasniy/.brew/include/taglib/commentsframe.h;/Users/mmasniy/.brew/include/taglib/eventtimingcodesframe.h;/Users/mmasniy/.brew/include/taglib/generalencapsulatedobjectframe.h;/Users/mmasniy/.brew/include/taglib/ownershipframe.h;/Users/mmasniy/.brew/include/taglib/popularimeterframe.h;/Users/mmasniy/.brew/include/taglib/privateframe.h;/Users/mmasniy/.brew/include/taglib/relativevolumeframe.h;/Users/mmasniy/.brew/include/taglib/synchronizedlyricsframe.h;/Users/mmasniy/.brew/include/taglib/textidentificationframe.h;/Users/mmasniy/.brew/include/taglib/uniquefileidentifierframe.h;/Users/mmasniy/.brew/include/taglib/unknownframe.h;/Users/mmasniy/.brew/include/taglib/unsynchronizedlyricsframe.h;/Users/mmasniy/.brew/include/taglib/urllinkframe.h;/Users/mmasniy/.brew/include/taglib/chapterframe.h;/Users/mmasniy/.brew/include/taglib/tableofcontentsframe.h;/Users/mmasniy/.brew/include/taglib/podcastframe.h;/Users/mmasniy/.brew/include/taglib/oggfile.h;/Users/mmasniy/.brew/include/taglib/oggpage.h;/Users/mmasniy/.brew/include/taglib/oggpageheader.h;/Users/mmasniy/.brew/include/taglib/xiphcomment.h;/Users/mmasniy/.brew/include/taglib/vorbisfile.h;/Users/mmasniy/.brew/include/taglib/vorbisproperties.h;/Users/mmasniy/.brew/include/taglib/oggflacfile.h;/Users/mmasniy/.brew/include/taglib/speexfile.h;/Users/mmasniy/.brew/include/taglib/speexproperties.h;/Users/mmasniy/.brew/include/taglib/opusfile.h;/Users/mmasniy/.brew/include/taglib/opusproperties.h;/Users/mmasniy/.brew/include/taglib/flacfile.h;/Users/mmasniy/.brew/include/taglib/flacpicture.h;/Users/mmasniy/.brew/include/taglib/flacproperties.h;/Users/mmasniy/.brew/include/taglib/flacmetadatablock.h;/Users/mmasniy/.brew/include/taglib/apefile.h;/Users/mmasniy/.brew/include/taglib/apeproperties.h;/Users/mmasniy/.brew/include/taglib/apetag.h;/Users/mmasniy/.brew/include/taglib/apefooter.h;/Users/mmasniy/.brew/include/taglib/apeitem.h;/Users/mmasniy/.brew/include/taglib/mpcfile.h;/Users/mmasniy/.brew/include/taglib/mpcproperties.h;/Users/mmasniy/.brew/include/taglib/wavpackfile.h;/Users/mmasniy/.brew/include/taglib/wavpackproperties.h;/Users/mmasniy/.brew/include/taglib/trueaudiofile.h;/Users/mmasniy/.brew/include/taglib/trueaudioproperties.h;/Users/mmasniy/.brew/include/taglib/rifffile.h;/Users/mmasniy/.brew/include/taglib/aifffile.h;/Users/mmasniy/.brew/include/taglib/aiffproperties.h;/Users/mmasniy/.brew/include/taglib/wavfile.h;/Users/mmasniy/.brew/include/taglib/wavproperties.h;/Users/mmasniy/.brew/include/taglib/infotag.h;/Users/mmasniy/.brew/include/taglib/asffile.h;/Users/mmasniy/.brew/include/taglib/asfproperties.h;/Users/mmasniy/.brew/include/taglib/asftag.h;/Users/mmasniy/.brew/include/taglib/asfattribute.h;/Users/mmasniy/.brew/include/taglib/asfpicture.h;/Users/mmasniy/.brew/include/taglib/mp4file.h;/Users/mmasniy/.brew/include/taglib/mp4atom.h;/Users/mmasniy/.brew/include/taglib/mp4tag.h;/Users/mmasniy/.brew/include/taglib/mp4item.h;/Users/mmasniy/.brew/include/taglib/mp4properties.h;/Users/mmasniy/.brew/include/taglib/mp4coverart.h;/Users/mmasniy/.brew/include/taglib/modfilebase.h;/Users/mmasniy/.brew/include/taglib/modfile.h;/Users/mmasniy/.brew/include/taglib/modtag.h;/Users/mmasniy/.brew/include/taglib/modproperties.h;/Users/mmasniy/.brew/include/taglib/itfile.h;/Users/mmasniy/.brew/include/taglib/itproperties.h;/Users/mmasniy/.brew/include/taglib/s3mfile.h;/Users/mmasniy/.brew/include/taglib/s3mproperties.h;/Users/mmasniy/.brew/include/taglib/xmfile.h;/Users/mmasniy/.brew/include/taglib/xmproperties.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/mmasniy/.brew/include/taglib" TYPE FILE FILES
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/tag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/fileref.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/audioproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/taglib_export.h"
    "/Users/mmasniy/Desktop/utag/build/3dparty/taglib/taglib/../taglib_config.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/taglib.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tstring.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tlist.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tlist.tcc"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tstringlist.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tbytevector.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tbytevectorlist.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tbytevectorstream.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tiostream.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tfilestream.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tmap.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tmap.tcc"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tpropertymap.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/trefcounter.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/toolkit/tdebuglistener.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/mpegfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/mpegproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/mpegheader.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/xingheader.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v1/id3v1tag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v1/id3v1genres.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2frame.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2header.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2synchdata.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2footer.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2framefactory.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/id3v2tag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/privateframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/chapterframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpeg/id3v2/frames/podcastframe.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/oggfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/oggpage.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/oggpageheader.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/xiphcomment.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/vorbis/vorbisfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/vorbis/vorbisproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/flac/oggflacfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/speex/speexfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/speex/speexproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/opus/opusfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ogg/opus/opusproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/flac/flacfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/flac/flacpicture.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/flac/flacproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/flac/flacmetadatablock.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ape/apefile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ape/apeproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ape/apetag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ape/apefooter.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/ape/apeitem.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpc/mpcfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mpc/mpcproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/wavpack/wavpackfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/wavpack/wavpackproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/trueaudio/trueaudiofile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/trueaudio/trueaudioproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/riff/rifffile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/riff/aiff/aifffile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/riff/aiff/aiffproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/riff/wav/wavfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/riff/wav/wavproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/riff/wav/infotag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/asf/asffile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/asf/asfproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/asf/asftag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/asf/asfattribute.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/asf/asfpicture.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mp4/mp4file.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mp4/mp4atom.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mp4/mp4tag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mp4/mp4item.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mp4/mp4properties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mp4/mp4coverart.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mod/modfilebase.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mod/modfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mod/modtag.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/mod/modproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/it/itfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/it/itproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/s3m/s3mfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/s3m/s3mproperties.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/xm/xmfile.h"
    "/Users/mmasniy/Desktop/utag/3dparty/taglib/taglib/xm/xmproperties.h"
    )
endif()

