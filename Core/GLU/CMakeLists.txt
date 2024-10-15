#set the name of the library
project(glu C CXX) 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

#add all files as library
file(GLOB_RECURSE LibFiles CONFIGURE_DEPENDS Files/*.hpp Files/*.h Files/*.cpp Files/*.c) 
add_library(${PROJECT_NAME}
	${LibFiles}
)
#Alias the library name
add_library(Core::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#link needed libraries 
target_link_libraries(${PROJECT_NAME} PRIVATE libglew_static glfw stb glm::glm)

#set include directories (what relative path will be used with the #include instruction)
target_include_directories(${PROJECT_NAME}
	PUBLIC
		#in the install
		$<INSTALL_INTERFACE:Include>
		#in here
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/Files
		${CMAKE_CURRENT_SOURCE_DIR}/Include
)