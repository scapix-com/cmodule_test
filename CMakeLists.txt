cmake_minimum_required(VERSION 3.14)

project(cmodule_test CXX)
set(target cmodule_test)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.*)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${sources})

add_executable(${target} ${sources})

# dependencies

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.32.tar.gz"
  URL_HASH SHA256=e6937c95d73188a5add846b27cd00160fe4f6ea31af33be417d2ab7ac19bd8d2
)
FetchContent_MakeAvailable(cmodule)

find_package(Boost REQUIRED)
target_link_libraries(${target} PUBLIC Boost::headers)

find_package(Boost REQUIRED COMPONENTS filesystem)
target_link_libraries(${target} PUBLIC Boost::filesystem)

find_package(Boost REQUIRED COMPONENTS filesystem iostreams context)
target_link_libraries(${target} PUBLIC Boost::filesystem Boost::iostreams Boost::context)

find_package(ZLIB REQUIRED)
target_link_libraries(${target} PRIVATE ZLIB::ZLIB)

find_package(BZip2 REQUIRED)
target_link_libraries(${target} PRIVATE BZip2::BZip2)

find_package(pybind11 REQUIRED)
target_link_libraries(${target} PRIVATE pybind11::module)
set_target_properties(${target} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")
