#file (GLOB HEADERS "*.h")
#file (GLOB SOURCES "*.cpp")



set(header_list
   ${header_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/appdata.h
   ${CMAKE_CURRENT_SOURCE_DIR}/appinit.h
   ${CMAKE_CURRENT_SOURCE_DIR}/base64helper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/iconhelper.h
   ${CMAKE_CURRENT_SOURCE_DIR}/quihelper.h
   PARENT_SCOPE
)

set(source_list
   ${source_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/appdata.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/appinit.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/base64helper.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/iconhelper.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/quihelper.cpp
   PARENT_SCOPE
)

#set(ui_list
#   ${ui_list} 
#   ${CMAKE_CURRENT_SOURCE_DIR}/*.ui
#   PARENT_SCOPE
#)

set( qrc_list
	${qrc_list}
	${CMAKE_CURRENT_SOURCE_DIR}/qrc/font.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/qrc/image.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/qrc/qm.qrc
	PARENT_SCOPE
)
