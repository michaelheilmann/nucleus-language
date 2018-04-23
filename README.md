# Nucleus
Nucleus is basic C project with CMake support.
Nucleus works for Windows and Linux.

## Building the demo (Windows)
Visual Studio is currently *still* supported.

Open the console.

Change the directory to the directory of this file.

Enter
```
cmake -G "Visual Studio 15 2017" CMakeLists.txt
```
to generate the project files for Win32.

Enter
```
cmake -G "Visual Studio 15 2017 Win64" CMakeLists.txt
```
to generate the project files for x64.

Open the files using Visual Studio 2017 and build all configurations.

To execute the unit tests for a particular configuration, enter
```
ctest -C <configuration>
```

```configuration``` is one of `Debug`, `Release`, `MinSizeRel`, `RelWithDebInfo`.

## Building the demo (Linux and Cygwin)
Open the console.

Change the directory to the directory of this file.

Enter
```
cmake CMakeLists.txt 
```
to generate the project files.

Enter
```
make all
```
to build.

To execute the unit tests, enter
```
ctest
```

### Compilation options (Linux and Cygwin)
For Linux and Cygwin builds, certain CMake options are supported.
The currently supported options are `With-Debug-Information=(ON|OFF)`
and `With-Optimizations=(ON|OFF)`.

For example, to enable both optimizations and debug information enter
```
cmake -DWith-Optimizations=ON -DWith-Debug-Information=ON CMakeLists.txt
```

#### Continuous Integrations Status Maxtrix

|              | master                                                                                                                                                                                   | develop |
| ------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------|
| **Travis**   | [![Build Status](https://travis-ci.org/primordialmachine/nucleus-language.svg?branch=master)](https://travis-ci.org/primordialmachine/nucleus)                                           |    -    |
| **AppVeyor** | [![Build status](https://ci.appveyor.com/api/projects/status/kvas7mxufgc4bu48/branch/master?svg=true)](https://ci.appveyor.com/project/primordialmachine/nucleus-language/branch/master) |    -    |
