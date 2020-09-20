# Changelog

### v0.1.0 - 09/19/2020
- Added command line flags for Linux/Mac
- Loads .mak files (defaults to ~/.mak)
- Populates UI with contents of .mak
- Added threadmap storage

### v0.0.10 - 09/14/2020
- Reverted changes to Main Window due to wxWidgets not liking to destroy it
  - Instead, list item and text boxes are cleared and rebuilt
- Tray icons are 32 size now

### v0.0.9 - 09/14/2020
- Fixed Windows Icons
- Main Window is now created when shown, destroyed when hidden
  - This should reduce overall memory when UI is not shown

### v0.0.8 - 09/13/2020
- Fixed Mac icons
- Built main interface v1

### v0.0.7 - 09/11/2020
- Fixed Windows icons
- Fixed some memory leaks

### v0.0.6 - 09/10/2020
- Brought main pointers to mApp for global access
- Added Instance to mApp
- Added 24 size image for Tray

### v0.0.5 - 09/08/2020
- Added Tray Icon
- Application now controlled via System Tray

### v0.0.4 - 09/07/2020
- About menu v1 complete
- Added options to menu

### v0.0.3 - 09/06/2020
- Updated CMakeLists.txt to build on Windows
- Fixed Memory Leak in About dialog

### v0.0.2 - 09/06/2020
- Custom About dialog started
- Fixed Header Guards
- Renamed "res" folder to art, added compiled art to "source/res"

### v0.0.1 - 09/06/2020
- Built basic window
- Added artwork

### v0.0.0 - 09/05/2020
- Started!
- Added wxWidgets as submodule
- Added CMakeLists.txt for building project
