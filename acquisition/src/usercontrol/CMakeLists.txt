#file (GLOB HEADERS "*.h")
#file (GLOB SOURCES "*.cpp")



set(header_list
   ${header_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/bartemp.h
   ${CMAKE_CURRENT_SOURCE_DIR}/gaugesimple.h
   ${CMAKE_CURRENT_SOURCE_DIR}/panelwidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/slider.h
   ${CMAKE_CURRENT_SOURCE_DIR}/stylewidget.h
   ${CMAKE_CURRENT_SOURCE_DIR}/switchbutton.h
   PARENT_SCOPE
)

set(source_list
   ${source_list}
   ${CMAKE_CURRENT_SOURCE_DIR}/bartemp.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/gaugesimple.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/panelwidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/slider.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/stylewidget.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/switchbutton.cpp
   PARENT_SCOPE
)

