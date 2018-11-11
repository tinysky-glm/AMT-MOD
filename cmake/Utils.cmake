#An option that the user can select. Can accept condition to control when option is available for user.
# Usage:
#   bana_option(<option_variable> "doc string" <initial value or boolean expression> [IF <condition>])
function(mod_option variable description value)
    set(__value ${value})
    set(__condition "")
    set(__varname "__value")
    foreach(arg ${ARGN})
  	if(arg STREQUAL "IF" OR arg STREQUAL "if")
   	    set(__varname "__condition")
  	else()
   	    list(APPEND ${__varname} ${arg})
  	endif()
    endforeach()
    unset(__varname)
    if("${__condition}" STREQUAL "")
 	set(__condition 2 GREATER 1)
    endif() 
    if(${__condition})
	if("${__value}" MATCHES ";")
      	    if(${__value})
       		option(${variable} "${description}" ON)
     	    else()
       		option(${variable} "${description}" OFF)
     	    endif()
   	elseif(DEFINED ${__value})
     	    if(${__value})
       		option(${variable} "${description}" ON)
     	    else()
       		option(${variable} "${description}" OFF)
     	    endif()
   	else()
     	    option(${variable} "${description}" ${__value})
   	endif()
    else()
   	unset(${variable} CACHE)
    endif()
endfunction()

# Helper for test function
function(mod_add_test dir extension)
    file(GLOB TEST_SOURCE "${dir}/*${extension}")
    foreach(file ${TEST_SOURCE})
   	string(REGEX REPLACE ".*${dir}/" "" file_exe0 ${file})
   	string(REPLACE "${extension}" "" file_exe ${file_exe0})
   	add_executable(${file_exe} ${file})
   	target_link_libraries(${file_exe} ${ARGN})
   	#set_target_properties(${file_exe} PROPERTIES COMPILE_FLAGS "-g --coverage")
   	add_test(${file_exe} ${file_exe} COMMAND ${file_exe})
    endforeach()
endfunction()

# Helper for benchmark function
function(mod_add_bench dir extension)
    file(GLOB TEST_SOURCE "${dir}/*${extension}")
    foreach(file ${TEST_SOURCE})
    	string(REGEX REPLACE ".*${dir}/" "" file_exe0 ${file})
   	string(REPLACE "${extension}" "" file_exe ${file_exe0})
   	add_executable(${file_exe} ${file})
   	target_link_libraries(${file_exe} ${ARGN})
    endforeach()
endfunction()

