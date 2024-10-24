include(FetchContent)

message(STATUS "Fetching Boost lib...")

CPMAddPackage(
    NAME boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.85.0
)

message(STATUS "Download completed...")

find_package(Boost REQUIRED)
message(STATUS "Adding Boost headers...")

file(GLOB files "${Boost_SOURCE_DIR}/libs/*/include")
foreach(filename ${files})
    include_directories(${filename})
endforeach()

file(GLOB files "${Boost_SOURCE_DIR}/libs/*/*/include")
foreach(filename ${files})
    include_directories(${filename})
endforeach()


set(BOOST_LIBS Boost::system Boost::filesystem Boost::chrono Boost::context Boost::coroutine Boost::thread Boost::multiprecision Boost::json Boost::atomic Boost::program_options)
