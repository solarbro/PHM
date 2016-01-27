#Grabbing every single 
FILE(GLOB SRCS *.h *.hpp *.c *.cpp)

#Gets the sub directory list
SUBDIRLIST( SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
IF(SUBDIRS STREQUAL "")
  MESSAGE("There is nothing here")
ELSE(NOT SUBDIRS STREQUAL "")
  FOREACH(subdir ${SUBDIRS})
    ADD_SUBDIRECTORY(${subdir})
  ENDFOREACH()
  SET(listVar ${listVar} ${SRCS} PARENT_SCOPE)
ENDIF()

