# Basic Modern CMake Explanation and Example

*This repository is for learning purposes and in progress. Written by Jakub Pavelka.*
Basics of the Modern cmake to future proof your build system.

## Index

- [Index](#index)
- [Targets](#targets)
  - [Executables](#executables)
  - [Static and Shared Libraries](#static-and-shared-libraries)
  - [Interface Libraries](#interface-libraries)
  - [Custom Targets](#custom-targets)
  - [Aliases](#aliases)
- [Compile and Linker Flags](#compile-and-linker-flags)
- [Build Types](#build-types)
- [Example explanation](#example-explanation)

## Targets

In CMake it's important to have one thing in mind to keep your project scalable: **Define only what needs to be defined for each part**. Fortunately there is a easy way out **targets**.

There are 3 basic types of targets:

- Executables (Binaries). Defined with `add_executable(...)` command
- Libraries. Defined with `add_library(...)`. These can also be divided in 3 types
  - Static. This is  default or `add_library(<name> STATIC ...)`
  - Shared. `add_library(<name> SHARED ...)`
  - Interface (header-only). `add_library(<name> INTERFACE)`
- Custom targets. Defined with `add_custom_target(...)`. These are special and the text below will not go too much into them.

Note: *Not all of following information does not correspond to the custom targets*

Everything you wan to set up for each target is done with special commands usually starting with `target_*` prefix. This will help you to make CMakeLists more readable as well as help you separate what is important for each source/header file.

### Executables

Executable can be any binary that is final product of compilation and linkage to be executed.

### Static and Shared Libraries

Two basic types of libraries. The Cmake in both cases does the same thing, that is to create a binary object to be linked to your final executable target.

### Interface Libraries

Special type of a "library" in cmake basically this type of target is not responsible for any source files but just bundles number of headers together to keep them in one target with their exclusive settings regarding to linker and compile flags or defines.

### Custom targets

This is another and even more special type of target. There you can describe any command to be done during the building stage of the build system process.

### Aliases

Every target can have alias defined. For libraries it is a common practice to do that. Defining alias is done like this

```cmake
add_library(a)
add_library(B::a ALIAS a)
```

## Compile and Linker Flags

As written above there are some commands for targets to be configured regarding the compile and link flags and also cmake supports many so-called features for compilation.

These commands are:

- [`target_compile_definitions`](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html) Here you can set definition for target.
- [`target_compile_features`](https://cmake.org/cmake/help/latest/command/target_compile_features.html) This command will let you select compile features
- [`target_compile_options`](https://cmake.org/cmake/help/latest/command/target_compile_options.html) This command sets compile options for target.
- [`target_include_directories`](https://cmake.org/cmake/help/latest/command/target_include_directories.html) Here you define the path where should target search for include files
- [`target_link_directories`](https://cmake.org/cmake/help/latest/command/target_link_directories.html) To find specific library you sometimes need to specify the directory where it is. You have this command for it.
- [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) Defines what libraries will be linked to current target.
- [`target_link_options`](https://cmake.org/cmake/help/latest/command/target_link_options.html) This command sets linker options for target.
- [`target_precompile_headers`](https://cmake.org/cmake/help/latest/command/target_precompile_headers.html) This defines which headers should be precompiled.
- [`target_sources`](https://cmake.org/cmake/help/latest/command/target_sources.html) Here you specify which sources will be built for specified target.

Features are basically predefined aliases for compiler specific flags with some generalized meaning e.g. cxx_std_XY stand for selecting c++ standard version to XY.

- [C compile features](https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_C_KNOWN_FEATURES.html)
- [C++ Compile features](https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html)

## Build Types

 In addition to your flags CMake adds some basic flags to your binaries by default these flags are determined by the **build type** you are using during configuration stage.
 There are four build types (explained with gcc flags):

- Release `-O3`
- Debug `-g -Og`
- RelWithDebInfo `-g -O2`
- MinSizeRel `-Os`

## Example explanation

This repo is also an example for preferred way of wiring software to be mainly modular and simple.
The program consists from 4 parts which are divided to 3 libraries, 2 are header-only (interface) libraries and one static library. Fourth part is main program.

- [Graphics::Colors](src/colours/CMakeLists.txt)
- [Graphics::Rainbow](src/graphic/CMakeLists.txt)
- [Utility::ArgParser](src/utility/CMakelists.txt)
- [example](src/CMakeLists.txt)
- [Base cmake](CMakeLists.txt)
