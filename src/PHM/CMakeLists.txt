#######################GCC FLAGS##############################
SET(GCC_FLAGS_DEBUG   "-std=c++14 -Wextra -Wall -pedantic ")
SET(GCC_FLAGS_RELEASE "-std=c++14 -Wextra -Wall -pedantic ")
#######################GCC FLAGS##############################

#######################UNIX FLAGS##############################
SET(UNIX_FLAGS_DEBUG   "-std=c++14 -Wextra -Wall -pedantic")
SET(UNIX_FLAGS_RELEASE "-std=c++14 -Wextra -Wall -pedantic")
#######################UNIX FLAGS##############################

#######################MSVC FLAGS##############################
SET(MSVC_FLAGS_DEBUG "/W3 /MP")
SET(MSVC_FLAGS_RELEASE "/W3 /MP")
#######################MSVC FLAGS##############################


SET(PREPROCESSOR_DEF "_CRT_SECURE_NO_WARNINGS")

####################BUILD TYPE####################
#Mutually exclusive only one can be set true
#Expect undefined results if multiple are true
SET(MAKE_EXECUTABLE FALSE)
SET(MAKE_STATIC_LIB TRUE)
SET(MAKE_SHARED_LIB FALSE)
####################BUILD TYPE####################

#######################DO NOT TOUCH##############################
#Get the folder name
GET_FILENAME_COMPONENT(ProjectName ${CMAKE_CURRENT_LIST_DIR} NAME)
#Replacing space with _ from the above directory
STRING(REPLACE " " "_" ProjectName ${ProjectName})
#######################DO NOT TOUCH##############################

############################CUSTOM FUNCTIONS###################################
function(assign_source_group)
  FOREACH(_source IN ITEMS ${ARGN})
    IF (IS_ABSOLUTE "${_source}")
      FILE(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
    ELSE()
      SET(source_rel "${_source}")
    ENDIF()
    GET_FILENAME_COMPONENT(_source_path "${_source_rel}" PATH)
    STRING(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
    SOURCE_GROUP("${_source_path_msvc}" FILES "${_source}")
  ENDFOREACH()
endfunction(assign_source_group)
############################CUSTOM FUNCTIONS###################################

#####################FINDING FILES AND FOLDER NAMES #########################

# Getting every file and putting it in the variable SRCS
FILE(GLOB SRCS *.h *.hpp *.c *.cpp)

#GLOBAL variable listVar that will be used to combine everything inside this project
LIST(APPEND listVar ${SRCS})

SUBDIRLIST( SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

#Add sub-directories and check if the sub-directories is not a empty string
IF(SUBDIRS STREQUAL "")
ELSE(NOT SUBDIRS STREQUAL "")
  FOREACH(subdir ${SUBDIRS})
    ADD_SUBDIRECTORY(${subdir})
  ENDFOREACH(subdir)
ENDIF()

#Grab the list of every folder in the directory
#And Makes it into a MSVC Filter
assign_source_group(${listVar})
#####################FINDING FILES AND FOLDER NAMES #########################

##########Adding Preprocessor Defines##########
FOREACH(predef ${PREPROCESSOR_DEF})
  ADD_DEFINITIONS(-D"${predef}")
ENDFOREACH(predef)
##########Adding Preprocessor Defines##########

##########Setting Compiler Flags#########
IF(WIN32)
  IF(MINGW)
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${GCC_FLAGS_DEBUG}")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${GCC_FLAGS_RELEASE}") 
  ELSEIF(MSVC)
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${MSVC_FLAGS_DEBUG}")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${MSVC_FLAGS_RELEASE}")
  ENDIF(MINGW)
ELSEIF(UNIX)
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${UNIX_FLAGS_DEBUG}")
  SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} ${UNIX_FLAGS_RELEASE}")
ENDIF(WIN32)
##########Setting Compiler Flags#########


#################################DONT TOUCH####################################
############################ExternalDependencies###############################
#Checking Compiler/64-32/Debug-Release
INCLUDE_DIRECTORIES("${EX_DEPEND}/${ProjectName}/include")
IF(EX_PLATFORM EQUAL 64)
  IF(MINGW)
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/mingw/64/De")
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/mingw/64/Re")   
  ELSEIF(MSVC)
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/msvc/64/De")
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/msvc/64/Re")
  ENDIF(MINGW)
ELSEIF(EX_PLATFORM EQUAL 32)
  IF(MINGW)
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/mingw/32/De")
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/mingw/32/Re")    
  ELSEIF(MSVC)
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/msvc/32/De")
    LINK_DIRECTORIES("${EX_DEPEND}/${ProjectName}/lib/msvc/32/Re")
  ENDIF(MINGW)
ENDIF(EX_PLATFORM EQUAL 64)
############################ExternalDependencies###############################
#################################DONT TOUCH####################################

INCLUDE_DIRECTORIES(${ASSIMP_INCLUDE_DIR})

IF(MAKE_EXECUTABLE STREQUAL TRUE)
 #Make the folder name the same name as the solution
  ADD_EXECUTABLE(${ProjectName} ${listVar})
ELSEIF(MAKE_STATIC_LIB STREQUAL TRUE)
 ADD_LIBRARY(${ProjectName} STATIC ${listVar})
ELSEIF(MAKE_SHARED_LIB STREQUAL TRUE)
  ADD_LIBRARY(${ProjectName} SHARED ${listVar})
ENDIF(MAKE_EXECUTABLE STREQUAL TRUE)

#Putting this executable project in a folder
SET_TARGET_PROPERTIES (${ProjectName} PROPERTIES
    FOLDER Libraries/Static)
	
SET_TARGET_PROPERTIES(${ProjectName} PROPERTIES LINKER_LANGUAGE C++)
#######################FINDING LIBS CUSTOM###################################
#######################FINDING LIBS CUSTOM###################################

IF(WIN32)
  TARGET_LINK_LIBRARIES(${ProjectName} "opengl32.lib")
ELSEIF(UNIX)
  TARGET_LINK_LIBRARIES(${ProjectName} "libGL.so")
ENDIF(WIN32)
#######################FINDING LIBS CUSTOM###################################
#######################FINDING LIBS CUSTOM###################################

#################################DONT TOUCH######################################
#########################CHECKING DEBUG AND RELEASE LIBS#########################
IF(EX_PLATFORM EQUAL 64)
  IF(WIN32)
    IF(MINGW)
      FINDLIBS("${EX_DEPEND}/${ProjectName}/lib/mingw/64/De" "${EX_DEPEND}/${ProjectName}/lib/mingw/64/Re")      
    ELSEIF(MSVC)
      FINDLIBS("${EX_DEPEND}/${ProjectName}/lib/msvc/64/De" "${EX_DEPEND}/${ProjectName}/lib/msvc/64/Re")  
    ENDIF(MINGW)
  ENDIF(WIN32)
ELSEIF(EX_PLATFORM EQUAL 32)
  IF(MINGW)
    FINDLIBS("${EX_DEPEND}/${ProjectName}/lib/mingw/32/De" "${EX_DEPEND}/${ProjectName}/lib/mingw/32/Re") 
  ELSEIF(MSVC)
    FINDLIBS("${EX_DEPEND}/${ProjectName}/lib/msvc/32/De" "${EX_DEPEND}/${ProjectName}/lib/msvc/32/Re")
  ENDIF(MINGW)
ENDIF(EX_PLATFORM EQUAL 64)
#########################CHECKING DEBUG AND RELEASE LIBS#########################
#################################DONT TOUCH######################################
