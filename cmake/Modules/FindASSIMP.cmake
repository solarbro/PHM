# - Try to find Assimp
# Once done, this will define
#
#  ASSIMP_FOUND - system has Assimp
#  ASSIMP_INCLUDE_DIR - the Assimp include directories
#  ASSIMP_LIBRARIES - link these to use Assimp
SET(FIND_ASSIMP_PATHS
    ${ASSIMP_ROOT}
     /Library/Frameworks
     /usr/local
     /usr
     /sw
     /opt/local
     /opt/csw
     /opt)


FIND_PATH( ASSIMP_INCLUDE_DIR
  NAMES assimp
  PATHS ${FIND_ASSIMP_PATHS}
  PATH_SUFFIXES include
)

FIND_LIBRARY(
  ASSIMP_LIBRARY_DEBUG 
  NAMES assimpd
  PATHS ${FIND_ASSIMP_PATHS}
  PATH_SUFFIXES lib/De
)

FIND_LIBRARY(
  ASSIMP_LIBRARY_RELEASE 
  NAMES assimp
  PATHS ${FIND_ASSIMP_PATHS}
  PATH_SUFFIXES lib/Re
)

IF(ASSIMP_INCLUDE_DIR AND ASSIMP_LIBRARY_DEBUG AND ASSIMP_LIBRARY_RELEASE)
  SET( ASSIMP_FOUND TRUE )
  SET(ASSIMP_LIBRARY debug ${ASSIMP_LIBRARY_DEBUG} optimized ${ASSIMP_LIBRARY_RELEASE})
ENDIF(ASSIMP_INCLUDE_DIR AND ASSIMP_LIBRARY_DEBUG AND ASSIMP_LIBRARY_RELEASE)

IF(ASSIMP_FOUND)
   IF(NOT ASSIMP_FIND_QUIETLY)
      MESSAGE(STATUS "Found ASSIMP: ${ASSIMP_LIBRARY_RELEASE}")
   ENDIF(NOT ASSIMP_FIND_QUIETLY)
ELSE(ASSIMP_FOUND)
   IF(ASSIMP_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find libASSIMP")
   ENDIF(ASSIMP_FIND_REQUIRED)
ENDIF(ASSIMP_FOUND)