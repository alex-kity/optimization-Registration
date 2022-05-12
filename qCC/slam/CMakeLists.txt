
set(header_list
   ${header_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/ColorChangeTool.h
   ${CMAKE_CURRENT_SOURCE_DIR}/CSlamLadirDialog.h
   ${CMAKE_CURRENT_SOURCE_DIR}/CGYLCommon.h
   ${CMAKE_CURRENT_SOURCE_DIR}/CDataChange.h
   PARENT_SCOPE
)

set(source_list
   ${source_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/ColorChangeTool.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/CSlamLadirDialog.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/CDataChange.cpp
   PARENT_SCOPE
)

set(ui_list
   ${ui_list} 
   ${CMAKE_CURRENT_SOURCE_DIR}/ColorChangeTool.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/CSlamLadirDialog.ui
   PARENT_SCOPE
)

set( qrc_list
	${qrc_list}
	${CMAKE_CURRENT_SOURCE_DIR}/slam.qrc
	PARENT_SCOPE
)
