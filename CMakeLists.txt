cmake_minimum_required(VERSION 3.12)
project(Computer
	VERSION 1.0.0
	DESCRIPTION "A stupid and detereministic shell calculator"
	HOMEPAGE_URL "https://github.com/MrSaturnIdk/compute"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)

message(STATUS "Project version is: ${PROJECT_VERSION}")
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "CMake build type (what do you think)" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE is set to: ${CMAKE_BUILD_TYPE}")

add_executable(compute
	src/array.c
	src/main.c
)
target_include_directories(compute PRIVATE include)
target_compile_definitions(compute PRIVATE
	HOMEPAGE="${PROJECT_HOMEPAGE_URL}"
	PROJECT_VER="${PROJECT_VERSION}"
)

message(STATUS "Installing to: ${CMAKE_INSTALL_FULL_BINDIR}")
install(TARGETS compute
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
