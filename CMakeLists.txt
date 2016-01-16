CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2) #Because We Need Qt

#Specify build types
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "Configurations" FORCE)

#This is the project name
PROJECT(ONE)
#Finding all the folders in a directory

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../ExternalDependencies/cmake/Modules")
INCLUDE(macros)

SUBDIRLIST( SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})


# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

INCLUDE(cotire)
SET(EX_DEPEND "${CMAKE_SOURCE_DIR}/../ExternalDependencies")

############OUTPUT FILES LOCATION######################
#Where the files will be located after being being built
#ARCHIVE = STATIC, LIBRARY = Module libs, RUNTIME = EXE
SET(ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}/lib64")
SET(LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}/lib64")
SET(RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}/bin64")

SET(ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/lib64")
SET(LIBRARY_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/lib64")
SET(RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/bin64")
############OUTPUT FILES LOCATION######################

#Checking to see if compiled in 32/64
IF( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    MESSAGE( "64 bits compiler detected" )
    SET( EX_PLATFORM 64 )
    SET( EX_PLATFORM_NAME "x64" )
ELSE( CMAKE_SIZEOF_VOID_P EQUAL 8 ) 
    MESSAGE( "32 bits compiler detected" )
    SET( EX_PLATFORM 32 )
    SET( EX_PLATFORM_NAME "x86" )
ENDIF( CMAKE_SIZEOF_VOID_P EQUAL 8 )

IF( EX_PLATFORM EQUAL 64 )
  MESSAGE( "Outputting to lib64 and bin64" )
  IF(CMAKE_BUILD_TYPE MATCHES Debug)
  # ---------- Setup output Directories -------------------------
  SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY_DEBUG} CACHE PATH
    "Single Directory for all Libraries")
  
  # --------- Setup the Executable output Directory -------------
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_DIRECTORY_DEBUG} CACHE PATH
    "Single Directory for all Executables.")
  
  # --------- Setup the Executable output Directory -------------
  SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_OUTPUT_DIRECTORY_DEBUG} CACHE PATH
    "Single Directory for all static libraries.") 
  ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
    # ---------- Setup output Directories -------------------------
  SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY_RELEASE} CACHE PATH
    "Single Directory for all Libraries")
  
  # --------- Setup the Executable output Directory -------------
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_DIRECTORY_RELEASE} CACHE PATH
    "Single Directory for all Executables.")
  
  # --------- Setup the Executable output Directory -------------
  SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_OUTPUT_DIRECTORY_RELEASE} CACHE PATH
    "Single Directory for all static libraries.") 
  ENDIF(CMAKE_BUILD_TYPE MATCHES Debug) 
ELSE( EX_PLATFORM EQUAL 64 )
# ---------- Setup output Directories -------------------------
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/lib CACHE PATH
   "Single Directory for all Libraries")

# --------- Setup the Executable output Directory -------------
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/bin CACHE PATH
   "Single Directory for all Executables.")

# --------- Setup the Executable output Directory -------------
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/lib CACHE PATH
   "Single Directory for all static libraries.")
ENDIF( EX_PLATFORM EQUAL 64 )

################FINDING LIBRARY PACKAGES###########################
IF(WIN32)
  #SET(SFML_STATIC_LIBRARIES TRUE)
  IF(MSVC12)
    SET(SFML_ROOT "${EX_DEPEND}/cmake/Libraries/msvc/64/SFML-2.3.2")
    SET(WWISE_ROOT "${EX_DEPEND}/cmake/Libraries/msvc/64/Wwise-2015.1.2")
    SET(Qt_Path "${EX_DEPEND}/cmake/Libraries/msvc/64/Qt5_MSVC")
    SET(GTEST_ROOT "${EX_DEPEND}/cmake/Libraries/msvc/64/gtest-1.7")
    SET(ASSIMP_ROOT "${EX_DEPEND}/cmake/Libraries/msvc/64/assimp")
    SET(SDL_ROOT "${EX_DEPEND}/cmake/Libraries/msvc/64/SDL2")
  ELSEIF(MSVC14)
    SET(SFML_ROOT "${EX_DEPEND}/cmake/Libraries/msvc14/64/SFML-2.3.2")
    SET(WWISE_ROOT "${EX_DEPEND}/cmake/Libraries/msvc14/64/Wwise-2015.1.2")
    SET(Qt_Path "${EX_DEPEND}/cmake/Libraries/msvc14/64/Qt5_MSVC")
    SET(GTEST_ROOT "${EX_DEPEND}/cmake/Libraries/msvc14/64/gtest-1.7")
    SET(ASSIMP_ROOT "${EX_DEPEND}/cmake/Libraries/msvc14/64/assimp")
    SET(SDL_ROOT "${EX_DEPEND}/cmake/Libraries/msvc14/64/SDL2")
  ELSEIF(MINGW)
    SET(SFML_ROOT "${EX_DEPEND}/cmake/Libraries/mingw/64/SFML-2.3.2")
    SET(Qt_Path "${EX_DEPEND}/cmake/Libraries/mingw/64/Qt5_MinGW")
  ENDIF(MSVC12)  
ELSEIF(UNIX)
  SET(SFML_ROOT "${EX_DEPEND}/cmake/Libraries/linuxGCC/SFML-2.3.2")
  FIND_PACKAGE(SDL2 REQUIRED)
ENDIF(WIN32)

FIND_PACKAGE(SFML 2 REQUIRED graphics window system)
FIND_PACKAGE(ASSIMP REQUIRED)
FIND_PACKAGE(SDL2 REQUIRED)

IF(SFML_FOUND)
   INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
  ELSE()
   MESSAGE(SEND_ERROR "SFML library not found. Please set SFML_ROOT.")
ENDIF(SFML_FOUND)

SET(CMAKE_PREFIX_PATH ${Qt_Path})

FIND_PACKAGE(Wwise REQUIRED)
FIND_PACKAGE(GTest REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)

IF(MINGW)  
  FIND_PACKAGE(CURL)
  IF(CURL_FOUND)
    MESSAGE("CURL FOUND")
    INCLUDE_DIRECTORIES(${CURL_LIBRARIES})
  ENDIF(CURL_FOUND) 
ENDIF(MINGW)

################FINDING LIBRARY PACKAGES###########################


FOREACH(subdir ${SUBDIRS})
	IF(subdir STREQUAL ".idea")
	ELSE()
		ADD_SUBDIRECTORY(${subdir})
	ENDIF(subdir STREQUAL ".idea")
ENDFOREACH()