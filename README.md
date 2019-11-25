# RRN - Recursive Rename

## Description
[de] RRN - Recursive Rename ist ein kleines Kommandozeilen Tool das Verzeichnisse und Dateien durchsucht und durch das angegebene Zeichen ersetzt. 

[en] RRN - Recursive Rename is a small command line tool that searches directories and files and replaces them with the given character.

## Dependencies
  * cmake
  * libboost >= 1.67-dev
  * libboost-program-options1.67-dev
  * libboost-filesystem1.67-dev
  * libboost-system1.67-dev


## Build from source

```shell
git clone https://github.com/knasan/rrn.git
cd rrn
mkdir build
cmake ../
make
```

## Examples

[de] Das Verzeichnis testdir hat Dateien die Leerzeichen enthalten (ugly).
[en] The testdir directory has files that contain spaces (ugly).

```
testdir/
├── destdir 1
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 10
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 2
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 3
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 4
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 5
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 6
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 7
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
├── destdir 8
│   ├── testfile 1
│   ├── testfile 10
│   ├── testfile 2
│   ├── testfile 3
│   ├── testfile 4
│   ├── testfile 5
│   ├── testfile 6
│   ├── testfile 7
│   ├── testfile 8
│   └── testfile 9
└── destdir 9
    ├── testfile 1
    ├── testfile 10
    ├── testfile 2
    ├── testfile 3
    ├── testfile 4
    ├── testfile 5
    ├── testfile 6
    ├── testfile 7
    ├── testfile 8
    └── testfile 9

10 directories, 100 files```

[de] Um all Leerzeichen durch einen unterstrich zu ersetzten reicht der einfache Aufruf von 
[en] To replace all spaces with an underscore, simply call

`rrn -s ' ' -r '_' -d testdir`

[de] Ich Empfehle davor ein Test druchzuführen (-t), um zu sehen was rrn machen würde übergebe den Schalter (-v).
[en] I recommend taking a test (-t) to see what rrn would do by giving the switch (-v).

```shell
./rrn -d testdir/ -s ' ' -r '_' -t -v

testdir/destdir 7/testfile 3 => testdir/destdir 7/testfile_3
testdir/destdir 7/testfile 5 => testdir/destdir 7/testfile_5
testdir/destdir 7/testfile 9 => testdir/destdir 7/testfile_9
testdir/destdir 7/testfile 1 => testdir/destdir 7/testfile_1
testdir/destdir 7/testfile 10 => testdir/destdir 7/testfile_10
testdir/destdir 7/testfile 6 => testdir/destdir 7/testfile_6
testdir/destdir 7/testfile 4 => testdir/destdir 7/testfile_4
testdir/destdir 7/testfile 2 => testdir/destdir 7/testfile_2
testdir/destdir 7/testfile 8 => testdir/destdir 7/testfile_8
testdir/destdir 7/testfile 7 => testdir/destdir 7/testfile_7
testdir/destdir 7 => testdir/destdir_7
testdir/destdir 5/testfile 3 => testdir/destdir 5/testfile_3
testdir/destdir 5/testfile 5 => testdir/destdir 5/testfile_5
testdir/destdir 5/testfile 9 => testdir/destdir 5/testfile_9
testdir/destdir 5/testfile 1 => testdir/destdir 5/testfile_1
testdir/destdir 5/testfile 10 => testdir/destdir 5/testfile_10
testdir/destdir 5/testfile 6 => testdir/destdir 5/testfile_6
testdir/destdir 5/testfile 4 => testdir/destdir 5/testfile_4
testdir/destdir 5/testfile 2 => testdir/destdir 5/testfile_2
testdir/destdir 5/testfile 8 => testdir/destdir 5/testfile_8
testdir/destdir 5/testfile 7 => testdir/destdir 5/testfile_7
testdir/destdir 5 => testdir/destdir_5
testdir/destdir 4/testfile 3 => testdir/destdir 4/testfile_3
testdir/destdir 4/testfile 5 => testdir/destdir 4/testfile_5
testdir/destdir 4/testfile 9 => testdir/destdir 4/testfile_9
testdir/destdir 4/testfile 1 => testdir/destdir 4/testfile_1
testdir/destdir 4/testfile 10 => testdir/destdir 4/testfile_10
testdir/destdir 4/testfile 6 => testdir/destdir 4/testfile_6
testdir/destdir 4/testfile 4 => testdir/destdir 4/testfile_4
testdir/destdir 4/testfile 2 => testdir/destdir 4/testfile_2
testdir/destdir 4/testfile 8 => testdir/destdir 4/testfile_8
testdir/destdir 4/testfile 7 => testdir/destdir 4/testfile_7
testdir/destdir 4 => testdir/destdir_4
testdir/destdir 9/testfile 3 => testdir/destdir 9/testfile_3
testdir/destdir 9/testfile 5 => testdir/destdir 9/testfile_5
testdir/destdir 9/testfile 9 => testdir/destdir 9/testfile_9
testdir/destdir 9/testfile 1 => testdir/destdir 9/testfile_1
testdir/destdir 9/testfile 10 => testdir/destdir 9/testfile_10
testdir/destdir 9/testfile 6 => testdir/destdir 9/testfile_6
testdir/destdir 9/testfile 4 => testdir/destdir 9/testfile_4
testdir/destdir 9/testfile 2 => testdir/destdir 9/testfile_2
testdir/destdir 9/testfile 8 => testdir/destdir 9/testfile_8
testdir/destdir 9/testfile 7 => testdir/destdir 9/testfile_7
testdir/destdir 9 => testdir/destdir_9
testdir/destdir 3/testfile 3 => testdir/destdir 3/testfile_3
testdir/destdir 3/testfile 5 => testdir/destdir 3/testfile_5
testdir/destdir 3/testfile 9 => testdir/destdir 3/testfile_9
testdir/destdir 3/testfile 1 => testdir/destdir 3/testfile_1
testdir/destdir 3/testfile 10 => testdir/destdir 3/testfile_10
testdir/destdir 3/testfile 6 => testdir/destdir 3/testfile_6
testdir/destdir 3/testfile 4 => testdir/destdir 3/testfile_4
testdir/destdir 3/testfile 2 => testdir/destdir 3/testfile_2
testdir/destdir 3/testfile 8 => testdir/destdir 3/testfile_8
testdir/destdir 3/testfile 7 => testdir/destdir 3/testfile_7
testdir/destdir 3 => testdir/destdir_3
testdir/destdir 1/testfile 3 => testdir/destdir 1/testfile_3
testdir/destdir 1/testfile 5 => testdir/destdir 1/testfile_5
testdir/destdir 1/testfile 9 => testdir/destdir 1/testfile_9
testdir/destdir 1/testfile 1 => testdir/destdir 1/testfile_1
testdir/destdir 1/testfile 10 => testdir/destdir 1/testfile_10
testdir/destdir 1/testfile 6 => testdir/destdir 1/testfile_6
testdir/destdir 1/testfile 4 => testdir/destdir 1/testfile_4
testdir/destdir 1/testfile 2 => testdir/destdir 1/testfile_2
testdir/destdir 1/testfile 8 => testdir/destdir 1/testfile_8
testdir/destdir 1/testfile 7 => testdir/destdir 1/testfile_7
testdir/destdir 1 => testdir/destdir_1
testdir/destdir 10/testfile 3 => testdir/destdir 10/testfile_3
testdir/destdir 10/testfile 5 => testdir/destdir 10/testfile_5
testdir/destdir 10/testfile 9 => testdir/destdir 10/testfile_9
testdir/destdir 10/testfile 1 => testdir/destdir 10/testfile_1
testdir/destdir 10/testfile 10 => testdir/destdir 10/testfile_10
testdir/destdir 10/testfile 6 => testdir/destdir 10/testfile_6
testdir/destdir 10/testfile 4 => testdir/destdir 10/testfile_4
testdir/destdir 10/testfile 2 => testdir/destdir 10/testfile_2
testdir/destdir 10/testfile 8 => testdir/destdir 10/testfile_8
testdir/destdir 10/testfile 7 => testdir/destdir 10/testfile_7
testdir/destdir 10 => testdir/destdir_10
testdir/destdir 6/testfile 3 => testdir/destdir 6/testfile_3
testdir/destdir 6/testfile 5 => testdir/destdir 6/testfile_5
testdir/destdir 6/testfile 9 => testdir/destdir 6/testfile_9
testdir/destdir 6/testfile 1 => testdir/destdir 6/testfile_1
testdir/destdir 6/testfile 10 => testdir/destdir 6/testfile_10
testdir/destdir 6/testfile 6 => testdir/destdir 6/testfile_6
testdir/destdir 6/testfile 4 => testdir/destdir 6/testfile_4
testdir/destdir 6/testfile 2 => testdir/destdir 6/testfile_2
testdir/destdir 6/testfile 8 => testdir/destdir 6/testfile_8
testdir/destdir 6/testfile 7 => testdir/destdir 6/testfile_7
testdir/destdir 6 => testdir/destdir_6
testdir/destdir 8/testfile 3 => testdir/destdir 8/testfile_3
testdir/destdir 8/testfile 5 => testdir/destdir 8/testfile_5
testdir/destdir 8/testfile 9 => testdir/destdir 8/testfile_9
testdir/destdir 8/testfile 1 => testdir/destdir 8/testfile_1
testdir/destdir 8/testfile 10 => testdir/destdir 8/testfile_10
testdir/destdir 8/testfile 6 => testdir/destdir 8/testfile_6
testdir/destdir 8/testfile 4 => testdir/destdir 8/testfile_4
testdir/destdir 8/testfile 2 => testdir/destdir 8/testfile_2
testdir/destdir 8/testfile 8 => testdir/destdir 8/testfile_8
testdir/destdir 8/testfile 7 => testdir/destdir 8/testfile_7
testdir/destdir 8 => testdir/destdir_8
testdir/destdir 2/testfile 3 => testdir/destdir 2/testfile_3
testdir/destdir 2/testfile 5 => testdir/destdir 2/testfile_5
testdir/destdir 2/testfile 9 => testdir/destdir 2/testfile_9
testdir/destdir 2/testfile 1 => testdir/destdir 2/testfile_1
testdir/destdir 2/testfile 10 => testdir/destdir 2/testfile_10
testdir/destdir 2/testfile 6 => testdir/destdir 2/testfile_6
testdir/destdir 2/testfile 4 => testdir/destdir 2/testfile_4
testdir/destdir 2/testfile 2 => testdir/destdir 2/testfile_2
testdir/destdir 2/testfile 8 => testdir/destdir 2/testfile_8
testdir/destdir 2/testfile 7 => testdir/destdir 2/testfile_7
testdir/destdir 2 => testdir/destdir_2
```

[de] Hier das Resultat.
[en] Here is the result

```shell
./rrn -d testdir/ -s ' ' -r '_'

testdir/
├── destdir_1
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_10
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_2
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_3
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_4
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_5
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_6
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_7
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
├── destdir_8
│   ├── testfile_1
│   ├── testfile_10
│   ├── testfile_2
│   ├── testfile_3
│   ├── testfile_4
│   ├── testfile_5
│   ├── testfile_6
│   ├── testfile_7
│   ├── testfile_8
│   └── testfile_9
└── destdir_9
    ├── testfile_1
    ├── testfile_10
    ├── testfile_2
    ├── testfile_3
    ├── testfile_4
    ├── testfile_5
    ├── testfile_6
    ├── testfile_7
    ├── testfile_8
    └── testfile_9

10 directories, 100 files
```
