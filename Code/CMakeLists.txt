cmake_minimum_required(VERSION 3.0.0)
project(ShapeDetection VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED ) 

SET(SOURCES
    main.cpp
    IShape.cpp
    CViewWindow.cpp
    CTrackBar.cpp
    CParser.cpp
    CMode.cpp
    CInteractiveMode.cpp
    CCommandMode.cpp
    CColour.cpp
    Shapes/CCircle.cpp
    Shapes/CHalfCircle.cpp
    Shapes/CSquare.cpp
    Shapes/CTriangle.cpp
)
SET(HEADERS
    IShape.h
    ESelections.h
    CViewWindow.h
    CTrackBar.h
    CParser.h
    CMode.h
    CInteractiveMode.h
    CCommandMode.h
    CColour.h
    Shapes/CCircle.h
    Shapes/CHalfCircle.h
    Shapes/CSquare.h
    Shapes/CTriangle.h
)

add_executable(ShapeDetection ${SOURCES} ${HEADERS}

)

target_link_libraries( ShapeDetection ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
