# Contributing to HTK

We welcome you to join the development of HTK. This document will help you through the process.

## Commit message

Each commit has to begin by one of these acronym:
- COMP: Resolve compilation error
- FIX: Fix a bug
- FEAT: Add a new functionality
- DOC: Add/update documentation
- STYLE: Clean code + update code format
- REFACTOR: A code change that doesn't fix a bug or add a new feature
- PERF: Improve performance
- TEST: Add or update test
- CHORE: Update build process like updating cmake

## Unit tests

When you add a new functionality, it's worth to add a test in order to have a sustainable library.
In order to add a new test:
- Go to the folder 'Tests'
- Follow the sources architectures. If you have develop a new feature for VTK in the IO section, then, go to VTK_Tests/IO folder
- Create a new test files htkNameOfYourFunction_test.cxx
- Add this test file into the VTK_Tests/IO/CMakeLists.txt
- Fill your test

Your test file will be present like this :

```cpp
#include "catch.hpp"

#include "htkNameOfYourFunction.h"

TEST_CASE("Name of your test", "Specific test")
{
	// Do your test
	bool test = yourFunction();
	REQUIRE(test);
	REQUIRE(0 == 1);
}

```

For more information about catch test, go [here](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md)
