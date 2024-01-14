
#Archiver
AR := ar
ARFLAGS :=

#Assembler
AS := as
ASFLAGS := 

#Linker
LD := ld 
LDFLAGS := 
LIBS := 

#System commands
RM := rm -f 
MKDIR := mkdir -p

#cpp compiller
CXX := g++
CXXFLAGS := -std=c++20 -O2



#Build Targets
UNIX_TARGET_EXEC := main
WIN_TARGET_EXEC := main.exe
UNIX_TARGET_LIB := pinelog.a
WIN_TARGET_LIB := pinelog.lib


#Basic dirs
ROOT_DIR := ./..
BUILD_DIR := ${ROOT_DIR}/build
SOURCE_DIR := ${ROOT_DIR}/source

#Subdirs
DEBUG_DIR := ${BUILD_DIR}/debug
RELEASE_DIR := ${BUILD_DIR}/release
OBJECTS_DIR := ${BUILD_DIR}/objects
#Sub-subdirs
SRC_SUBDIRS := $(shell find ${SOURCE_DIR}/* -type d)
SUB_FOLDERS := $(SRC_SUBDIRS:${SOURCE_DIR}/%=%)


#Files
SRC_FILES := $(shell find ${SOURCE_DIR}/ -name "*.cpp")
OBJ_FILES := $(SRC_FILES:${SOURCE_DIR}/%.cpp=%.o)

#Search Paths
vpath %.o ${OBJECTS_DIR}
vpath %.hpp ${SOURCE_DIR}
#DO NOT declare a vpath for %.cpp -> will expand and search for a rule ${SOURCE_DIR}/%.cpp in stead of %.cpp
vpath %.cpp ${SOURCE_DIR}


testmacro:
	echo "Macro: ${OBJ_FILES}"


debug: ${OBJ_FILES}
	echo "Making test with the following Objects: $? \n"
	${CXX} ${CXXFLAGS} $(addprefix ${OBJECTS_DIR}/../,$?) -o debug
#	${CXX} ${CXXFLAGS} $? -o debug


#DO NOT declare a vpath for .cpp -> will expand and search for a rule ${SOURCE_DIR}/%.cpp in stead of %.cpp
%.o: %.cpp
	echo "${CXX} ${CXXFLAGS} -c $? -o ${OBJECTS_DIR}/$@ \n\n"
	${MKDIR} ${OBJECTS_DIR}/$(dir $@)
	${CXX} ${CXXFLAGS} -c $? -o ${OBJECTS_DIR}/$@


#HPP_DEPS := PineLib.hpp
#
#PineLib.hpp : Pine/Settings.hpp
#
#MainTest.cpp:
#	echo "Got $@"
#
#${SOURCE_DIR}/Logger/Piner.cpp: $(dir $@)
#	echo "Got $@ AND $^"
#
#Render/Frame.cpp: 
#	echo "Got $@"
#
#Storage/Buffer.cpp:
#	echo "Got $@"
#
#Storage/Stream.cpp:
#	echo "Got $@"