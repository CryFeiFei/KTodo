cmake_minimum_required(VERSION 3.1.0)

project(KTodo)

set(CMAKE_CXX_STANDARD 14)

IF (WIN32)
	MESSAGE(STATUS "Now is windows")
	set(CMAKE_PREFIX_PATH "D:\\QtVersion\\Qt5.13_Build_MT_X64\\qt5.13_build_mt\\bin")
	set(Qt5_DIR "D:\\QtVersion\\Qt5.13_Build_MT_X64\\qt5.13_build_mt\\lib\\cmake\\Qt5")
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systens.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
get_target_property(QtCore_location Qt5::Widgets LOCATION)

find_package(Qt5 COMPONENTS Core REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

add_executable(KTodo
	mainwindow.ui
	mainwindow.cpp
	mainwindow.h
	main.cpp
	kviewer.cpp
	kviewer.h
	kstdafx.h
	data/kdatamgr.h
	data/kdatamgr.cpp
)

target_link_libraries(KTodo Qt5::Widgets Qt5::Core)

#todo windows copy
add_custom_command(TARGET ${PROJECT_NAME}
  PRE_BUILD 
  COMMAND echo "executing a fake command"
  COMMENT "This command will be executed before building target Test1"
 )
