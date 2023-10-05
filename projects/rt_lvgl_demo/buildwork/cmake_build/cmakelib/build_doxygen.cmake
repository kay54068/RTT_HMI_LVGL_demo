macro(build_doxygen)

find_package(Doxygen)
if(DOXYGEN_FOUND)

 
    set(DOXYGEN_IN "${DOC_DIR}/doxygen/Doxyfile.in")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    set(DOXYGNE_HTML ${CMAKE_CURRENT_BINARY_DIR}/doxygen/html/index.html)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)


    message(STATUS "Doxygen will output to ${DOXYGEN_OUT}")
    
    # note the option All which allows to build the docs together with the application
    add_custom_target( docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} "${DOXYGEN_OUT}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating documentation with Doxygen"
        VERBATIM)

    add_custom_target( docs_open ALL
        COMMAND firefox "${DOXYGNE_HTML}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Open doxygen genarate HTML"
        VERBATIM)

else()
    message(WARNING "Doxygen not found")
endif()
endmacro()

#ref:
# https://cmake.org/cmake/help/latest/module/FindDoxygen.html
