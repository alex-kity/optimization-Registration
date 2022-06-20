#file (GLOB HEADERS "*.h")
#file (GLOB SOURCES "*.cpp")



set(header_list
   ${header_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/frminputnum.h
   PARENT_SCOPE
)

set(source_list
   ${source_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/frminputnum.cpp
   PARENT_SCOPE
)

set(ui_list
   ${ui_list} 
   ${CMAKE_CURRENT_SOURCE_DIR}/frminputnum.ui
   PARENT_SCOPE
)


