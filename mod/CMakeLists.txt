file(GLOB_RECURSE SOURCE
    "common/*.cc"
    "utils/*.cc"
    "storage/*.cc"
    "algorithm/*.cc"
)
add_library(amt_mod ${SOURCE})
target_link_libraries(amt_mod shapelib pthread m)

if (USE_QT)
file(GLOB_RECURSE GUI_SOURCE
    "gui/*.cc")
add_executable(amt_mod_gui ${GUI_SOURCE})
target_link_libraries(amt_mod_gui amt_mod
    ${Qt5Widgets_LIBRARIES}
    ${Qt5WebEngineWidgets_LIBRARIES}
    ${Qt5Core_LIBRARIES})
endif()
