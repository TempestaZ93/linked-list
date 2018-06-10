CMAKE_MINIMUM_REQUIRED ( VERSION 3.5 )

PROJECT ( linked_list )


SET ( lib_files
		"src/LinkedList.cpp")

INCLUDE_DIRECTORIES ( "include" )

SET ( CMAKE_CXX_FLAGS "-std=c++0x" )	
ADD_LIBRARY ( ll_lib ${lib_files} )
ADD_EXECUTABLE ( demo "src/Main.cpp" )
TARGET_LINK_LIBRARIES ( demo ll_lib )