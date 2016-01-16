#Finding all the folders in a directory
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "") #setting this as a empty string
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        LIST(APPEND dirlist ${child})
    ENDIF(IS_DIRECTORY ${curdir}/${child})
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO(SUBDIRLIST)

MACRO(FINDLIBS debug release)
  SET(deblinuxlibs "${debug}/*.a")
  SET(debwindowlibs "${debug}/*.lib")
  SET(rellinuxlibs "${release}/*.a")
  SET(relwindowlibs "${release}/*.lib")
  
  FILE(GLOB DLIBS "${deblinuxlibs}" "${debwindowlibs}")
  FOREACH(DLIBS ${DLIBS})
    GET_FILENAME_COMPONENT(DLIB "${DLIBS}" NAME)
    #Properties->Linker->Input->Additional Dependencies
    TARGET_LINK_LIBRARIES(${ProjectName} debug ${DLIB})
  ENDFOREACH(DLIBS)    

  FILE(GLOB RLIBS "${rellinuxlibs}" "${relwindowlibs}")
  FOREACH(RLIBS ${RLIBS})
    GET_FILENAME_COMPONENT(RLIB "${RLIBS}" NAME)
    #Properties->Linker->Input->Additional Dependencies
    TARGET_LINK_LIBRARIES(${ProjectName} optimized ${RLIB})
  ENDFOREACH(RLIBS)
  
ENDMACRO(FINDLIBS)