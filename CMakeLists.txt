cmake_minimum_required(VERSION 3.16)

project(Nmap VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup()

qt_add_executable(appNmap
    main.cpp
)

qt_add_qml_module(appNmap
      URI Nmap
      VERSION 1.0
      QML_FILES
            Main.qml
      SOURCES
            Analyzer.hpp Analyzer.cpp
            Autogen.cpp

)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scan.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scan.xml
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appNmap PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appNmap
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appNmap
    PRIVATE Qt6::Quick
    Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS appNmap
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
