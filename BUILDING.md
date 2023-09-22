# Welcome to the building instructions for the project! Please make sure to prepeare the required files and install the necessary dependencies for your current OS.

# Requirements:
  * A Super Mario World rom (Make sure to rename it to `smw.sfc`)
  * `libsdl2-dev` (The installation for this will be different for each compiler.)

# Linux/MacOS/Windows
```
./c
```

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
