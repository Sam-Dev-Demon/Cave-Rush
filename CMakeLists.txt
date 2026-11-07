cmake_minimum_required(VERSION 3.30)

project(Cave_Rush LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(SFML_BUILD_AUDIO ON CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK ON CACHE BOOL "" FORCE)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/sfml/sfml
	GIT_TAG 3.1.0
	GIT_SHALLOW ON
	SYSTEM
	EXCLUDE_FROM_ALL
	FIND_PACKAGE_ARGS 3.1 CONFIG COMPONENTS Graphics System Window Audio Network
)

FetchContent_MakeAvailable(SFML)

add_executable(Cave_Rush
	src/core/main.cpp
	src/core/Game.cpp
	src/core/Entity.cpp
	src/core/Scene.cpp
	src/core/SceneMgr.cpp
	src/core/ResourceMgr.cpp
	src/util/Button.cpp
)

target_include_directories(Cave_Rush
	PRIVATE
	"${CMAKE_SOURCE_DIR}/include"
)

target_compile_definitions(Cave_Rush
	PRIVATE
	ROOT="${CMAKE_SOURCE_DIR}/"
)

target_link_libraries(Cave_Rush PRIVATE
	SFML::Graphics
	SFML::Audio
	SFML::Network
)

if (WIN32 AND BUILD_SHARED_LIBS)
	add_custom_command(TARGET Cave_Rush POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_RUNTIME_DLLS:Cave_Rush> $<TARGET_FILE_DIR:Cave_Rush>
	COMMAND_EXPAND_LISTS)
endif()

	