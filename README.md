## [HTK - The Helper Toolkit]

Introduction
============

HTK is an open-source software system that will help developers
of C++, VTK, OpenCV, ITK,... to develop faster. This library lists
common functions that can be easily use without redevelop it every times.


Reporting Bugs
==============

If you found an issue or a bug, please report it in the HTK tracker


Requirements
============

You have the possibility to use only some of the available libs by checking
CMake entries :
- Common : Common functionalities related to C++ (HTK_USE_COMMON)
- VTK : Functionalities related to VTK (HTK_USE_VTK)

If you want to use a lib which uses an external lib (like VTK), you have to
previously have a built lib on your computer. There is no superbuild.

Contributing
============

See [CONTRIBUTING.md](CONTRIBUTING.md) for instructions to contribute.
