📘 doxygen Setup guide
===

<!-- 
📘: Guide
📙: Technology
📗: Other
-->

<!--
command example:

\note
this is a note.

\todo
this is a todo.

\warning
this is a warning.

\bug
this is a bug.

\remarks
this is a remarks.

\deprecated
this is a Deprecated.

\invariant
this is a Invariant. 


\wavedrom{reg: [
{bits: 8, name: 'IPO', attr: 'RO'},
{bits: 7},
{bits: 5, name: 'BRK', attr: 'RW'},
{bits: 1, name: 'CPK'},
{bits: 3, name: 'Clear'},
{bits: 8}
]}
ref: 
https://wavedrom.com/tutorial.html
https://github.com/wavedrom/wavedrom/tree/trunk/test
-->

# Requirements

> Doxygen is the de facto standard tool for generating documentation from annotated C++ sources, but it also supports other popular programming languages such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and UNO/OpenOffice flavors), Fortran, and to some extent D. Doxygen also supports the hardware description language VHDL.

- need install package:
  * doxygen 1.9.5
  * graphviz

# install dependencies  

- install doxygen 1.9.5

```sh
wget https://www.doxygen.nl/files/doxygen-1.9.5.linux.bin.tar.gz
tar -xvf  doxygen-1.9.5.linux.bin.tar.gz
sudo cp doxygen-1.9.5/bin/doxygen /usr/bin/ 
```
- install graphviz

```sh
sudo apt install graphviz
```

# Build doc file.

## Build on script

run this script on scripts folder

```sh
scripts/make_docs.sh
```


## Make yourself

- create build_doxygen.cmake

```cmake
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
```

- add some config in CMakeLists.txt

```
if(BUILD_DOC)
include(cmakelib/build_doxygen.cmake)
build_doxygen()
endif()
```

- build 
```
cmake .. -DBUILD_DOC=ON
make docs
```

- open html file
```
make docs_open
```

# Setting from config file


edit docs/doxygen/Doxyfile.in file

```cfg
# Doxyfile 1.9.5

PROJECT_NAME           = @CMAKE_PROJECT_NAME@
PROJECT_NUMBER         = @DOCS_VERSION@
PROJECT_BRIEF          = @PROJECT_BRIEF@
OUTPUT_DIRECTORY       = @CMAKE_CURRENT_BINARY_DIR@/doxygen
FULL_PATH_NAMES        = NO
OPTIMIZE_OUTPUT_FOR_C  = YES
INLINE_SIMPLE_STRUCTS  = YES
TYPEDEF_HIDES_STRUCT   = YES
EXTRACT_STATIC         = YES
HIDE_UNDOC_MEMBERS     = YES
LAYOUT_FILE            = @DOC_DIR@/doxygen/DoxyLayout.xml
INPUT                  = ../../..
FILE_PATTERNS          = *.c \
                         *.h \
                         *.md  \
                         *.markdown

IMAGE_PATH             = @DOC_DIR@/images
RECURSIVE              = YES

#EXCLUDE               =
EXCLUDE_PATTERNS       = */lib/lv* \
                         */cJSON/*

USE_MDFILE_AS_MAINPAGE = ../../../README.md
VERBATIM_HEADERS       = NO
HTML_HEADER            = @DOC_DIR@/doxygen/theme/header.html
HTML_FOOTER            = @DOC_DIR@/doxygen/theme/footer.html
HTML_EXTRA_STYLESHEET  = @DOC_DIR@/doxygen/theme/doxygen-awesome.css \
                         @DOC_DIR@/doxygen/theme/doxygen-awesome-sidebar-only.css \
                         @DOC_DIR@/doxygen/theme/doxygen-awesome-sidebar-only-darkmode-toggle.css \
                         @DOC_DIR@/doxygen/theme/style.css

HTML_EXTRA_FILES       = @DOC_DIR@/doxygen/scripts/doxygen-awesome-darkmode-toggle.js \
                         @DOC_DIR@/doxygen/scripts/doxygen-awesome-fragment-copy-button.js \
                         @DOC_DIR@/doxygen/scripts/doxygen-awesome-paragraph-link.js \
                         @DOC_DIR@/doxygen/scripts/doxygen-awesome-interactive-toc.js \
                         @DOC_DIR@/doxygen/scripts/wavedrom.min.js \
                         @DOC_DIR@/doxygen/scripts/default.js

HTML_DYNAMIC_SECTIONS  = YES
GENERATE_TREEVIEW      = YES
FULL_SIDEBAR           = YES
DISABLE_INDEX          = NO
GENERATE_LATEX         = NO
QUIET                  = YES

# DOT Support
HAVE_DOT               = YES

# Wavedrom Support
#ALIASES += wavedrom{1}="\htmlonly <script src=\"default.js\" type=\"text/javascript\"></script><script src=\"wavedrom.min.js\" type=\"text/javascript\"></script><script type=\"WaveDrom\">{\1}</script><script type=\"text/javascript\">(function() {try {WaveDrom.ProcessAll();} catch(e) {}})();</script>\endhtmlonly"
ALIASES += wavedrom{1}="\htmlonly <script type=\"WaveDrom\">{\1}</script><script type=\"text/javascript\">(function() {try {WaveDrom.ProcessAll();} catch(e) {}})();</script>\endhtmlonly"

```