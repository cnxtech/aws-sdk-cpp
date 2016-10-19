macro(copyDlls exeName)
    if(PLATFORM_WINDOWS AND BUILD_SHARED_LIBS)
        foreach(arg ${ARGN})
            add_custom_command(TARGET ${exeName}
                    POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${CMAKE_BINARY_DIR}/${arg}/$<CONFIGURATION>/${arg}.dll"
                    ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>/)
        endforeach()
    endif()
endmacro()

# this function is based on the unity build function described at: https://cheind.wordpress.com/2009/12/10/reducing-compilation-time-unity-builds/
function(enable_unity_build UNITY_SUFFIX SOURCE_FILES)
    set(files ${${SOURCE_FILES}})

    # Generate a unique filename for the unity build translation unit
    set(unity_build_file ${CMAKE_CURRENT_BINARY_DIR}/ub_${UNITY_SUFFIX}.cpp)

    # Exclude all translation units from compilation
    set_source_files_properties(${files} PROPERTIES HEADER_FILE_ONLY true)

    # Open the ub file
    FILE(WRITE ${unity_build_file} "// Unity Build generated by CMake\n")

    # Add include statement for each translation unit
    foreach(source_file ${files} )
        FILE( APPEND ${unity_build_file} "#include <${source_file}>\n")
    endforeach(source_file)

    # Complement list of translation units with the name of ub
    set(${SOURCE_FILES} ${${SOURCE_FILES}} ${unity_build_file} PARENT_SCOPE)
endfunction(enable_unity_build)