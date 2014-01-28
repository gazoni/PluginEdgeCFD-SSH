# Script de Configuracao do Plugin do EdgeCFD
# LEANDRO GAZONI
# LAMCE/COPPE/UFRJ

cmake_minimum_required(VERSION 2.8)


PROJECT(runEdgeCFD) 

IF(NOT VTK_BINARY_DIR)
FIND_PACKAGE(VTK)
IF(NOT VTK_DIR)
  MESSAGE(FATAL_ERROR "Please set VTK_DIR.")
ENDIF(NOT VTK_DIR)
INCLUDE(${VTK_USE_FILE})
ENDIF(NOT VTK_BINARY_DIR)

# use what QVTK built with
SET(QT_MOC_EXECUTABLE ${VTK_QT_MOC_EXECUTABLE} CACHE FILEPATH "")
SET(QT_UIC_EXECUTABLE ${VTK_QT_UIC_EXECUTABLE} CACHE FILEPATH "")
SET(QT_QMAKE_EXECUTABLE ${VTK_QT_QMAKE_EXECUTABLE} CACHE FILEPATH "")
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})


# Use the include path and library for Qt that is used by VTK.
INCLUDE_DIRECTORIES(
  ${QT_INCLUDE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# REALIZANDO INCLUDE NO DIRETORIO DO SSH
include_directories(FlowSsh/include)

#########################################################################
# Incluindo os Sources Files
#########################################################################
SET(Application_src 
configansys.cpp 
io.cpp 
main.cpp 
runedgecfd.cpp 
ViewVtk.cpp) 

#Incluindo os Arquivos UI inteface do QT
SET(UIS configansys.ui menuAnsys.ui runedgecfd.ui)

#Incluindo os arquivos de Header do C++
SET(runEdgeCFDHeaders 
configansys.h
formOrdenado.h
forms.h
io.h
resource.h
resource1.h
resource2.h
runedgecfd.h 
ViewVtk.h) 


SET(runEdgeCFDResources icons/runedgecfd.qrc)

# The rest should just work (sure...)
QT4_WRAP_UI(UISrcs ${UIS})
QT4_WRAP_CPP(MOCSrcs ${runEdgeCFDHeaders} )
QT4_ADD_RESOURCES(ResourceSrcs ${runEdgeCFDResources})

SOURCE_GROUP("Resources" FILES
  ${UIS}
  ${runEdgeCFDResources}
  ${EXE_ICON}
)

SOURCE_GROUP("Generated" FILES
  ${UISrcs}
  ${MOCSrcs}
  ${ResourceSrcs}
  ${RCS_SOURCES}
)

ADD_DEFINITIONS(-DQT_GUI_LIBS -DQT_CORE_LIB -DQT3_SUPPORT)
SET_SOURCE_FILES_PROPERTIES(${Application_src} PROPERTIES
                            OBJECT_DEPENDS "${UISrcs}")

# It's nice to have the ui in the windows project file...just double click on it
# and designer comes up on that ui file :)
IF (${CMAKE_BUILD_TOOL} MATCHES "msdev")
  SET (Application_src ${Application_src} ${UIS})
ENDIF (${CMAKE_BUILD_TOOL} MATCHES "msdev")
IF (${CMAKE_BUILD_TOOL} MATCHES "devenv")
  SET (Application_src ${Application_src} ${UIS})
ENDIF (${CMAKE_BUILD_TOOL} MATCHES "devenv")


IF(WIN32)
  LINK_LIBRARIES(
  ${QT_QTMAIN_LIBRARY}
  FlowSsh/lib/FlowSshC64
  )
  ADD_DEFINITIONS(-DQT_DLL)
ENDIF(WIN32)

# DEFININDO AS CONFIGURAÇAOES PARA A BILIOTECA DE SSH

# set the path to the library folder SSH
INCLUDE_DIRECTORIES(FlowSsh/lib/)

#link_directories(FlowSshC64)

# link the libraries to the executable SSH
#target_link_libraries ()



ADD_EXECUTABLE( runEdgeCFD WIN32 ${Application_src} ${UISrcs} ${MOCSrcs} ${ResourceSrcs} ${runEdgeCFDHeaders} )

TARGET_LINK_LIBRARIES( runEdgeCFD
  QVTK
  ${QT_LIBRARIES}
  #vtkRenderingQt-6.0
  vtkRendering
  #vtkGraphics
  vtkIO
  vtkCommon
  #vtkInfovis
  #vtkViews
  FlowSshC64
)


