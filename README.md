# uTag
My project to work with **audio-file tags** and **metadata**! 

# Description
You can use this app to view and edit audio-file tags,
album images and lyrics.

# The app can

- [x] _opens the directory with the audio files through the GUI as well as through thecommand-line argument_
- [x] _support supports the following audio formats:_<br/>
    * **.mp3**
    * **.flac**
    * **.waw**
    * **.ogg**
    * **.aif**
- [x] _display a list of audio-file names in the requested directory_
- [x] _display/edit these audio-file tags in the GUI window:_
    * **files name**
    * **title**
    * **artist**
    * **album**
    * **track number**
    * **genre**
    * **year**
    * **absolute path to file**
- [x] _support audio files items sorting in alphabetical (ascending and descending) order bya certain tag_
- [x] _supports the display and edit of the lyrics_
- [x] _supports the tracking of history_
    * **displays activity log**
- [x] _edits an album image for an audio file and displays it via the GUI_
- [x] _fully supports Unicode. Correctly displays any character from any language_

# uTag

![Images](https://user-images.githubusercontent.com/44983824/94473374-c84b3a80-01d4-11eb-8252-ca742fd86638.png)

# Instalation

1. `git clone --recursive https://github.com/mmasniy/utag.git`
2. `cmake . -Bbuild -Wdev -Werror=dev && cmake --build ./build`
3. `/build/app/utag` or `/build/app/utag [path to directory]`

# Tools that I used

 - **Cmake** - is an open-source, cross-platform family of tools designed to build, test and package software.
 - **Qt** - is the faster, smarter way to create innovative devices, modern UIs & applications for multiple screens.
 - **TagLib** - is a library for reading and editing the meta-data of several popular audio formats. 
