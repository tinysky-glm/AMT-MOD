set(SOURCE
    shapelib/dbfopen.c
    shapelib/shpopen.c
    shapelib/shptree.c
)
add_library(shapelib ${SOURCE})

add_executable(dbfadd shapelib/dbfadd.c)
target_link_libraries(dbfadd shapelib)

add_executable(dbfdump shapelib/dbfdump.c)
target_link_libraries(dbfdump shapelib)

add_executable(shpadd shapelib/shpadd.c)
target_link_libraries(shpadd shapelib)

add_executable(shpcreate shapelib/shpcreate.c)
target_link_libraries(shpcreate shapelib)

add_executable(shpdump shapelib/shpdump.c)
target_link_libraries(shpdump shapelib)

add_executable(shprewind shapelib/shprewind.c)
target_link_libraries(shprewind shapelib)

add_executable(shptreedump shapelib/shptreedump.c)
target_link_libraries(shptreedump shapelib)

add_executable(shputils shapelib/shputils.c)
target_link_libraries(shputils shapelib)

