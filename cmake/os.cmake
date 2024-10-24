if(WIN32)
    add_definitions(-DWIN32)
elseif(APPLE)
    add_definitions(-DAPPLE)

    if(IOS OR CMAKE_SYSTEM_NAME STREQUAL iOS)
        add_definitions()
    else()
        add_definitions()
    endif()
else()
    add_definitions(-DUNIX)

    if(ANDROID OR CMAKE_SYSTEM_NAME STREQUAL Android)
        add_definitions(-DANDROID)
    elseif(CMAKE_SYSTEM_NAME STREQUAL Linux)
        add_definitions(-DLINUX)
    elseif(CMAKE_SYSTEM_NAME STREQUAL FreeBSD OR CMAKE_SYSTEM_NAME STREQUAL DragonFly)
        add_definitions(-DFREEBSD)
    endif()
endif()
    
