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

### Linux

```shell
git clone https://github.com/knasan/rrn.git
cd rrn
mkdir build
cmake ../
make
```

## macOS Dependencies

[de] macOS Konfiguration

* Xcode aus dem App-Store installieren
  * führe `xcode-select --install` in der konsole aus (aktiviert Entwickler Komandozeilen Tools)
  * homebrew Konfigurieren [Homebrew](https://brew.sh/index_de)
    * `brew update`
    * `brew install cmake`
    * `brew instal boost`
    * `brew install git` nur wenn du noch kein Git Installiert hast.
    In der Konsole in deinem Workspace welchseln und folgende Befehle ausführen.
    `git clone https://github.com/knasan/rrn.git`
    `cd rrn`
    `mkdir build`
    `clang++ -std=c++17 ../main.cpp ../rrn.cpp  -lboost_system -lboost_filesystem -lboost_program_options -I/usr/local/lib/include/ -o rrn`

[en] macOS configuration

* Install Xcode from the App Store
* execute `xcode-select --install` in the console (activates developer command line tools)
* homebrew Configure [Homebrew](https://brew.sh/index_de)
  * `brew update`
  * `brew install cmake`
  * `brew instal boost`
  * `brew install git` only if you have not installed git yet.
  
Change to the console in your workspace and execute the following commands.

* `git clone https://github.com/knasan/rrn.git`
  * `cd rrn`
  * `mkdir build`
  * `clang++ -std=c++17 ../main.cpp ../rrn.cpp  -lboost_system -lboost_filesystem -lboost_program_options -I/usr/local/lib/include/ -o rrn`

## Examples

[de] Das Verzeichnis testdir hat Dateien die Leerzeichen enthalten (ugly).

[en] The testdir directory has files that contain spaces (ugly).

```shell
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
.....
10 directories, 100 files
```

[de] Um all Leerzeichen durch einen unterstrich zu ersetzten reicht der einfache Aufruf von.

[en] To replace all spaces with an underscore, simply call.

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
....
```

[de] In Version 0.0.2 kann optional Dateien und/oder Verzeichnisse ausgeschlossen werden. Die Datei oder das Verzeichnis muss als Absolutenpfad angegeben werden. In diesem Beispiel wird das Verzeichnis "testdir/destdir 7" und die Datei "testdir/destdir 5/testfile_03" ausgelassen.

[en] In version 0.0.2 files and/or directories can optionally be excluded. The file or directory must be specified as an absolute path. In this example the directory "testdir/destdir 7" and the file "testdir/destdir 5/testfile_03" are omitted.


```shell
./rrn -d testdir/ -s ' ' -r '_' -t -v -e 'testdir/destdir 7' -e 'testdir/destdir 5/testfile_03'
```
