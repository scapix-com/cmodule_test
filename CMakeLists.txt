cmake_minimum_required(VERSION 3.28...4.5)

project(cmodule_test LANGUAGES C CXX)
set(target cmodule_test)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "source/*")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

add_executable(${target} ${sources})

# dependencies

#option(BUILD_SHARED_LIBS "Build shared libraries" ON)

#option(BOOST_IOSTREAMS_ENABLE_ZLIB "" OFF)
#option(BOOST_IOSTREAMS_ENABLE_BZIP2 "" OFF)
#option(BOOST_IOSTREAMS_ENABLE_LZMA "" OFF)
#option(BOOST_IOSTREAMS_ENABLE_ZSTD "" OFF)

#find_package(OpenSSL REQUIRED)
#target_link_libraries(${target} PRIVATE OpenSSL::SSL OpenSSL::Crypto)

find_package(LibLZMA REQUIRED)
target_link_libraries(${target} PUBLIC LibLZMA::LibLZMA)

find_package(LibLZMA REQUIRED)
target_link_libraries(${target} PUBLIC LibLZMA::LibLZMA)

set(ZSTD_BUILD_SHARED ON) # for Boost::iostream
find_package(zstd REQUIRED)
target_link_libraries(${target} PUBLIC zstd::libzstd)

find_package(Boost REQUIRED)
target_link_libraries(${target} PUBLIC Boost::headers)

find_package(Boost REQUIRED COMPONENTS filesystem)
target_link_libraries(${target} PUBLIC Boost::filesystem)

find_package(Boost REQUIRED COMPONENTS filesystem iostreams context)
target_link_libraries(${target} PUBLIC Boost::filesystem Boost::iostreams Boost::context)

find_package(Boost REQUIRED COMPONENTS asio)
target_link_libraries(${target} PUBLIC Boost::asio)

find_package(ZLIB REQUIRED)
target_link_libraries(${target} PRIVATE ZLIB::ZLIB)

find_package(BZip2 REQUIRED)
target_link_libraries(${target} PRIVATE BZip2::BZip2)

find_package(pybind11 REQUIRED)
target_link_libraries(${target} PRIVATE pybind11::module)
set_target_properties(${target} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")

# curl option
#set(CMAKE_USE_OPENSSL ON)

find_package(CURL REQUIRED)
target_link_libraries(${target} PRIVATE CURL::libcurl)

# test CMAKE_FOLDER
add_executable(target2 ${sources})
#target_link_libraries(target2 PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(target2 PUBLIC Boost::headers)
target_link_libraries(target2 PUBLIC Boost::filesystem)
target_link_libraries(target2 PUBLIC Boost::filesystem Boost::iostreams Boost::context)
target_link_libraries(target2 PUBLIC LibLZMA::LibLZMA)
target_link_libraries(target2 PRIVATE ZLIB::ZLIB)
target_link_libraries(target2 PRIVATE BZip2::BZip2)
target_link_libraries(target2 PRIVATE pybind11::module)
target_link_libraries(target2 PRIVATE CURL::libcurl)
target_link_libraries(target2 PRIVATE Boost::asio)
