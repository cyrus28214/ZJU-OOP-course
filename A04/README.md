# Assignment 004 Personal Diary

The Personal Diary is a CLI (Command Line Interface) software that consists of four programs:

1. `pdadd`: Add a new entity to the diary.
2. `pdlist`: List all entities in the diary.
3. `pdshow`: Show a specific entity in the diary.
4. `pdremove`: Remove a specific entity from the diary.

## File Structure

```bash
.
├── CMakeLists.txt
├── README.md
├── bin
│   ├── pdadd
│   ├── pdlist
│   ├── pdremove
│   └── pdshow
├── script
│   ├── compile.sh
│   ├── package.sh
│   └── test.sh
├── src
│   ├── DiaryEntry.h
│   ├── DiaryManager.cpp
│   ├── DiaryManager.h
│   ├── pdadd.cpp
│   ├── pdlist.cpp
│   ├── pdremove.cpp
│   ├── pdshow.cpp
│   ├── utils.cpp
│   └── utils.h
└── test
    ├── diaries
    ├── pdadd
    ├── pdlist
    ├── pdremove
    └── pdshow
```

## Compile

### Command

```bash
script/compile.sh
```

The `compile.sh` script compiles all the source files into executable files.

The executable files are located in the `bin` directory.

## Test

Run the following command to run all the tests:
```bash
TEST 1
Add diary 2024-10-27
Enter the content of the diary (end with a single line of "." or EOF): 
TEST 2
Add diary 2024-10-28
Enter the content of the diary (end with a single line of "." or EOF): 
TEST 3
List all (verbose)
        [ 2024-10-27 ]
Today the "learning in ZJU" platform crashed. We don't need to take the exam as planned.

        [ 2024-10-28 ]
Today I have an OOP class.

        [ 2024-10-29 ]
Nothing happened.

TEST 4
Show diary 2024-10-27
        [ 2024-10-27 ]
Today the "learning in ZJU" platform crashed. We don't need to take the exam as planned.

TEST 5
Add diary 2024-10-29
Enter the content of the diary (end with a single line of "." or EOF): 
TEST 6
List between 2024-10-28 and 2024-10-29
2024-10-28
2024-10-29
TEST 7
Remove 2024-10-28
TEST 8
List all
2024-10-27
2024-10-29
```

## Usage

### `pdadd`

```bash
Usage: pdadd <date: YYYY-MM-DD>
 - then you will be able to input the content of the diary, end with a single line of ".", or EOF
```

### `pdlist`

```bash
Usage: pdlist [<begin> <end>] [-v|--verbose]
 - print diary entries in the range [<begin>, <end>] if provided <begin> and <end>
 - print all diary entries if not
 - dates are in YYYY-MM-DD format
 - add -v or --verbose to print full diary content
```

### `pdshow`

```bash
Usage: pdshow <date: YYYY-MM-DD>
 - print the content of the entity of the date
```

### `pdremove`

```bash
Usage: pdremove <date: YYYY-MM-DD>
 - remove the diary of the target day
```
