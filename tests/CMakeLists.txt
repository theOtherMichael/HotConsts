#[[
	HotConsts Tester
	Run the HotConsts_Tester target from this folder ("tests").
]]

set(HC_TEST_SRC
	_tests.h
	_main.cpp

	LiteralSamples.h
	LiteralSamples.cpp

	TokenizationTests.cpp
	IdentificationTests.cpp
	ConversionTests.cpp
	OperatorTests.cpp
	ExpressionTests.cpp
	ReloadTests.cpp
)

# Executable
add_executable(HotConsts_Tester ${HC_TEST_SRC})
set_target_properties(HotConsts_Tester PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
)

# Dependency linking
target_link_libraries(HotConsts_Tester PRIVATE HotConsts::HotConsts)

# Defines
target_compile_definitions(HotConsts_Tester PRIVATE HC_RELOADING_ON)

# Build flags
target_compile_features(HotConsts_Tester PRIVATE cxx_std_17)
