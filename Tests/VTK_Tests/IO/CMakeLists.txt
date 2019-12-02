add_executable(VTK_IO_Tests
	htkReadImage_test.cxx
)

target_link_libraries(VTK_IO_Tests PUBLIC htkTestBase HTKVTKLib)

add_test(NAME htkReadImage_test COMMAND VTK_IO_Tests)