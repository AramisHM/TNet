# executables directory

if(MSVC)
	add_executable (03.Hybrid main.cpp ./resources.rc ./ahml-icon48.ico) #with custom executable icon
	
else()
	add_executable (03.Hybrid main.cpp)
endif()

set_target_properties(03.Hybrid
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples"
)

#if we are using windows, we should link those libs
if(WIN32)
  	target_link_libraries(03.Hybrid ws2_32.lib winmm.lib)
endif()

target_link_libraries (03.Hybrid LINK_PUBLIC TNet)