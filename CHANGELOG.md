# Changelog

### v0.0.10 - 08/14/2020
- Reverted changes to Main Window due to wxWidgets not liking to destroy it
  - Instead, list item and text boxes are cleared and rebuilt
- Tray icons are 32 size now

### v0.0.9 - 08/14/2020
- Fixed Windows Icons
- Main Window is now created when shown, destroyed when hidden
  - This should reduce overall memory when UI is not shown

### v0.0.8 - 08/13/2020
- Fixed Mac icons
- Built main interface v1

### v0.0.7 - 08/11/2020
- Fixed Windows icons
- Fixed some memory leaks

### v0.0.6 - 08/10/2020
- Brought main pointers to mApp for global access
- Added Instance to mApp
- Added 24 size image for Tray

### v0.0.5 - 08/08/2020
- Added Tray Icon
- Application now controlled via System Tray

### v0.0.4 - 08/07/2020
- About menu v1 complete
- Added options to menu

### v0.0.3 - 08/06/2020
- Updated CMakeLists.txt to build on Windows
- Fixed Memory Leak in About dialog

### v0.0.2 - 08/06/2020
- Custom About dialog started
- Fixed Header Guards
- Renamed "res" folder to art, added compiled art to "source/res"

### v0.0.1 - 08/06/2020
- Built basic window
- Added artwork

### v0.0.0 - 08/05/2020
- Started!
- Added wxWidgets as submodule
- Added CMakeLists.txt for building project
