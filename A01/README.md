# Assignment01+3230106230+Liurenqin

## Environment

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

## Compile

```bash
make # build ./main
```

## Run with Test Data

```bash
./main < ./code/data.in
```

## Run with Standard Input

Input format:

Ten lines. Each line contains 1 string and 3 intergers (from 1 to 5), representing the name and 3 scores of a student.

Example:

```txt
K.Weng  5       5       5
T.Dixon 4       3       2
V.Chu   3       4       5
L.Tson  4       3       4
L.Lee   3       4       3
I.Young 4       2       5
K.Hiro  4       2       1
G.Ping  4       4       4
H.Gu    2       3       4
J.Jon   5       4       3
```

## Useful Commands

```bash
make clean # clean all generated files
make submit # create archive file for submit
```