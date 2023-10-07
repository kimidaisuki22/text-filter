cmake_minimum_required(VERSION 3.23.0)
project(vcpkg-port-filter VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(vcpkg-port-filter vcpkg-port-filter.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(vcpkg-port-filter PRIVATE fmt::fmt)
find_package(cy CONFIG REQUIRED)
target_link_libraries(vcpkg-port-filter PRIVATE cy::cy)
enable_testing()
add_subdirectory(test)

add_subdirectory(benchmark)

install(TARGETS vcpkg-port-filter DESTINATION bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME update_server_package)
include(CPack)

include(GNUInstallDirs)
