#set the name of the executable
project(AppName)

#add all files as executables (use of glob is not recommended glob uses all of the files in the current folder glob recurse checks all of the files in the current folder and below configure depends 
#makes it so it checks for new files every single time adding a step up to compilation time)
file(GLOB_RECURSE APP CONFIGURE_DEPENDS *.cpp *h)
add_executable(${PROJECT_NAME} ${APP})

#precompile headers to aliviate a little the compilation time
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

# link needed libraries: target_link_libraries(${PROJECT_NAME} PRIVATE example )

#link libraries from core
target_link_libraries(${PROJECT_NAME} PRIVATE Core::CoreLib libglew_static glfw)

#Link assets folder to the build folder for each type so it works on any compiler or IDE
add_custom_command(
#this line ensures that there will be a folder to create the first symlink if its not automatically generated so it works with gcc
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory 
        "$<CONFIG>"
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/Assets "$<CONFIG>/Assets"
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_SOURCE_DIR}/Assets "Assets"
)