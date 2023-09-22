# Welcome to the building instructions for the project! Please make sure to prepeare the required files and install the necessary dependencies for your current OS.

# Requirements:
  * A Super Mario World rom (Make sure to rename it to `smw.sfc`)
  * `libsdl2-dev` (The installation for this will be different for each compiler.)
  * Super Mario World repo `git clone --recursive https://github.com/snesrev/smw`
  * [Python](https://www.python.org/) (During installation, make sure to check the "Add to PATH")
  
 For Linux/MacOS you must install these for your desired OS:
 * Ubuntu/Debian: `sudo apt install libsdl2-dev`
 * Fedora Linux: `sudo dnf in sdl2-devel`
 * Arch Linux: `sudo pacman -S sdl2`
 * macOS: `brew install sdl2`

# Linux/MacOS

```
./c
```

# Windows

# Building with MSYS2

Dependencies and requirements:

  * The `libsdl2-dev` library
  * [MSYS2](https://www.msys2.org)
  
Note: *Make sure you're using MINGW64 and you're in `smw` folder in the terminal.*

1. Install MSYS2 on your machine.
2. Place the copy of your rom in the main directory.
3. Install the necessary dependencies and SDL2 by inputting this command in MSYS2 terminal:

```sh
pacman -S mingw-w64-x86_64-SDL2 && pacman -S make && pacman -S mingw-w64-x86_64-gcc
```
4. Type `sdl2-config --cflags`, it should output:
```sh
-IC:/msys64/mingw64/include/SDL2 -Dmain=SDL_main
```
5. After that type `sdl2-config --libs`, should output:
```sh
-LC:/msys64/mingw64/lib -lmingw32 -mwindows -lSDL2main -lSDL2
```

After you've done installing everything, in the terminal, type `make`
In order to speed up the compilation, type `make -j16`


# Running SMB1 and SMBLL

Dependencies and requirements:

  * Super Mario All-Stars rom (US version and not + Mario World)
  * `zstandard`

1. Rename your obtained rom to `smas.sfc` and place it inside the `other` folder.
2. To install `zstandard` make sure you've installed Python and added to PATH. Open up CMD and type `pip install zstandard` to install the required dep.
3. In the `other` folder drag and drop your renamed rom into `extract.py` or by typing `extract.py` in the command line to extract the necessary files.
4. Move `smb1.sfc` and `smbll.sfc` to root folder.
5. Before running the games, make sure to recompile or else they won't boot up.
6. Drag your desired game to `smw.exe` in order to run.

 
