#file (GLOB HEADERS "*.h")
#file (GLOB SOURCES "*.cpp")



set(header_list
   ${header_list}

   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevice.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicecontrol.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicepanel.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicepanelx.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmmain.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmplot.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmplotpanel.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmstylewidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/CSensorData.h
   ${CMAKE_CURRENT_SOURCE_DIR}/frmconfig.h
   PARENT_SCOPE
)

set(source_list
   ${source_list}

   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevice.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicecontrol.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicepanel.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicepanelx.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmmain.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmplot.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmplotpanel.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmstylewidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/CSensorData.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/frmconfig.cpp
   PARENT_SCOPE
)

set(ui_list
   ${ui_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevice.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicecontrol.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicepanel.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmdevicepanelx.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmmain.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmplot.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmplotpanel.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmstylewidget.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/CSensorData.ui
   ${CMAKE_CURRENT_SOURCE_DIR}/frmconfig.ui
   PARENT_SCOPE
)


