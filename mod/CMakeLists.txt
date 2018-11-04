file(GLOB_RECURSE SOURCE
    "utils/*.cc")
add_library(amt_mod ${SOURCE})
target_link_libraries(amt_mod pthread m)

file(GLOB_RECURSE GUI_SOURCE
    "gui/*.cc")
add_executable(amt_mod_gui ${GUI_SOURCE})
target_link_libraries(amt_mod_gui amt_mod)
