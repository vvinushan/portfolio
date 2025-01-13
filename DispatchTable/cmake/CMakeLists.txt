cmake_minimum_required(VERSION "3.19.0")

project("LabBook1")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable("${PROJECT_NAME}" "Main.cpp" )



install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
install(FILES "Main.cpp" "Fighter.h" "Fighter.cpp" "Player.h" "Player.cpp" "EasyNPC.h" "EasyNPC.cpp" "HardNPC.h" "HardNPC.cpp" DESTINATION src)

# Group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES ".*\\.cpp")
      set(GROUP "src${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
      set(GROUP "include${GROUP}")
    endif()