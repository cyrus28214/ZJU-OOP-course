# Assignment02+3230106230+Liurenqin

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

output:

```txt
no        name      Art       English   Music     History   Science   Math      average
1         Liam      1                                                 4         2.5
2         Grace     5         3                                                 4
3         Isaac     5         1                   4         3                   3.25
4         Noah      2                   5                   4                   3.66667
5         Alice                         3         2                   4         3
6         Bob                 4         4                   2                   3.33333
7         Frank                         2         5         4         3         3.5
8         Jack                5         1         3                   5         3.5
9         Olivia    3                                       4                   3.5
10        Charlie   2         3                   5                             3.33333
11        Peter               5         1                   3                   3
12        Eve                 5                                       4         4.5
13        Hannah    2                                       3                   2.5
14        David                                   1                             1
          average   2.85714   3.71429   2.66667   3.33333   3.28571   4
          min       1         1         1         1         2         3
          max       5         5         5         5         4         5
```

## Run with Standard Input

The input consists of multiple lines, each representing a student's score in a specific course. Each line contains the following elements:

1. **Student Name**: A string representing the name of the student.
2. **Course Name**: A string representing the name of the course.
3. **Score**: An integer between 1 and 5, representing the student's score for that course.

Input end with an empty new line, or EOF.

Each element is separated by a space. The input may look like this:

```txt
Alice Math 4
Alice English 5
Bob Science 3
Charlie History 2
David Art 5
```

## Useful Commands

```bash
make clean # clean all generated files
make submit # create archive file for submit
```