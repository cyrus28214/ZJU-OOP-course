# Assignment 003 Adventure

This is a CLI game. In this game you need to keep away from the monster, find and save the princess!

## File Structure

**NOTE**: You can check `.cpp` files to see the comments and docs.

```bash
.
├── CMakeLists.txt
├── README.md
├── main.cpp
├── src
│   ├── Castle.cpp
│   ├── Castle.h
│   ├── CastleGenerator.cpp
│   ├── CastleGenerator.h
│   ├── Direction.cpp
│   ├── Direction.h
│   ├── Game.cpp
│   ├── Game.h
│   ├── Player.cpp
│   ├── Player.h
│   ├── Room.cpp
│   ├── Room.h
│   ├── util.cpp
│   └── util.h
└── test
    └── in.txt
```

## Compile

### Tested Environment

```bash
# Operating System
$ uname -a
Linux Cyrus28214 5.15.133.1-microsoft-standard-WSL2 #1 SMP Thu Oct 5 21:02:42 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux

# Compiler Version
$ g++ --version
g++ (Ubuntu 13.2.0-23ubuntu4) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### Command

```bash
mkdir build # make directory
cd build && cmake .. # configure
cmake --build . # compile
```

Or you can use my `./compile.sh` script.

```bash
./compile.sh
-- Configuring done (0.1s)
-- Generating done (0.3s)
-- Build files have been written to: /mnt/d/courses/OOP/A03/build
[100%] Built target Adventure
编译完成。是否要运行程序？(y/N): y
    ___       __                 __                
   /   | ____/ /   _____  ____  / /___  __________ 
  / /| |/ __  / | / / _ \/ __ \/ __/ / / / ___/ _ \
 / ___ / /_/ /| |/ /  __/ / / / /_/ /_/ / /  /  __/
/_/  |_\__,_/ |___/\___/_/ /_/\__/\__,_/_/   \___/ 
     
Welcome to the game Adventure!
```

### Run with Test Data

```bash
cd build
./Adventure < ../test/in.txt
```

### Run with Standard Input

```bash
cd build
./Adventure
```

### Play

First, the game will prompt you to input the seed or leave empty to generate one.

```bash
./Adventure
    ___       __                 __                
   /   | ____/ /   _____  ____  / /___  __________ 
  / /| |/ __  / | / / _ \/ __ \/ __/ / / / ___/ _ \
 / ___ / /_/ /| |/ /  __/ / / / /_/ /_/ / /  /  __/
/_/  |_\__,_/ |___/\___/_/ /_/\__/\__,_/_/   \___/ 
     
Welcome to the game Adventure!

Input the seed of the game (leave empty to generate a random one): 
Use seed 582250.
You stand at the grand entrance of a mysterious castle. The air is thick with silence, and the walls seem to whisper secrets. Somewhere deep inside, a princess awaits rescue, but the castle holds dangers. Only the brave can venture inside and bring her to safety. With every step, the darkness grows stronger. Will you be the hero who saves her? Or will the castle's secrets consume you? Your journey begins now.

You have a new target, type "target" to check out
You have a new target, type "target" to check out
        [ Lobby ]
You are in the lobby of the castle. The walls are high, with faded tapestries hanging down, telling stories of battles long forgotten. A chandelier hangs crookedly from the ceiling, its crystals covered in dust. The air is still, but you can feel the weight of the castle's history around you.
There are 3 exits: west east north 
What do you want to do (type ? for help): 
```

You can type `?` to see help:

```bash
What do you want to do (type ? for help): help
Commands:
 - go <DIRECTION>: Move in that direction.
 - target: Check the targets.
 - info: Print player info
 - quit: Quit the game
 - help,?: Show this help message.
```

Enjoy the game!