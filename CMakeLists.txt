# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

cmake_minimum_required(VERSION 3.15)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "In-tree builds are not supported. Run CMake from a separate directory: cmake -B build")
endif()

set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr and automatically regenerate CMakeLists.txt
	include(cmkr.cmake OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Create a configure-time dependency on cmake.toml to improve IDE support
	configure_file(cmake.toml cmake.toml COPYONLY)
endif()

# Variables
set(CERT_NAME DrvCert)
set(TIMESTAMP_SERVER "http://timestamp.digicert.com")
set(COMPANY_NAME CompanyName)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/external/FindWDK/cmake)

project(cmkr-driver-example)

# Packages
find_package(WDK REQUIRED)

# Target: cmkr-driver-example
set(cmkr-driver-example_SOURCES
	"src/main.cpp"
	cmake.toml
)

wdk_add_driver(cmkr-driver-example ${cmkr-driver-example_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${cmkr-driver-example_SOURCES})

target_compile_features(cmkr-driver-example PUBLIC
	cxx_std_17
)

target_include_directories(cmkr-driver-example PUBLIC
	include
)

set(CMKR_TARGET cmkr-driver-example)
wdk_make_certificate(${CMKR_TARGET} ${CERT_NAME} COMPANY ${COMPANY_NAME})
wdk_sign_driver(${CMKR_TARGET} ${CERT_NAME} TIMESTAMP_SERVER ${TIMESTAMP_SERVER})

