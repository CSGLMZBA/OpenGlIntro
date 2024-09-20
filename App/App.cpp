#include "pch.hpp"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void shaderErrors(unsigned int shader,std::string type);
void programErrors(unsigned int program);
int main()
{
    //define __APPLE__ on macos devices in case its not working
    gluContext MainContext(4,0,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "INTROOPENGL", NULL, NULL);
    MainContext.AddWindow(window);
    GLenum err = glewInit();
    if (GLEW_OK != err)
        std::cout << glewGetErrorString(err);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSwapInterval(1);
    //objects and vertex
    float vertices[] = {
    1.0f,0.5f, 0.5f, 0.0f, // top  1
    1.0f,1.0f, 0.0f, 0.0f, // bottom right 1
    1.0f,0.0f, 0.0f, 0.0f,//bottom left 1 bottom right 2
    };
    float vertices2[] = {
    1.0f,-0.5f, -0.5f, 0.0f, // top  1
    1.0f,-1.0f, 0.0f, 0.0f, // bottom right 1
    1.0f,0.0f, 0.0f, 0.0f,//bottom left 1 bottom right 2
    };
    unsigned int indices[] = { // note that we start from 0!
    0, 1, 2
    };
    EBO EBO1(indices,3, GL_STATIC_DRAW);
    
    VBO VBO1(vertices,12,GL_STATIC_DRAW);
    VBO VBO2(vertices2,12,GL_STATIC_DRAW);
    
    const char *vertexShaderSource = "#version 400 core\n"
    "layout (location = 0) in vec4 aPos;\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(aPos.y, aPos.z, aPos.w, aPos.x);\n"
    "}\0";
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);
    shaderErrors(vertexShader,"VERTEX");

    const char *fragmentShaderSource = "#version 400 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.1f, 0.2f, 1.0f);\n"
    "}\n\0";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    shaderErrors(fragmentShader,"VERTEX");
    const char *fragmentShaderSource2 = "#version 400 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);\n"
    "}\n\0";
    unsigned int fragmentShader2;
    fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShader2);
    shaderErrors(fragmentShader2,"VERTEX");
    
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    programErrors(shaderProgram);
    glDeleteShader(fragmentShader);

    unsigned int shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2,vertexShader);
    glAttachShader(shaderProgram2,fragmentShader2);
    glLinkProgram(shaderProgram2);
    programErrors(shaderProgram2);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader2);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    VBO1.Bind();
    EBO1.Bind();
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    unsigned int VAO2;
    glGenVertexArrays(1, &VAO2);
    glBindVertexArray(VAO2);
    VBO2.Bind();
    EBO1.Bind();
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glUseProgram(shaderProgram2);
    glBindVertexArray(VAO2);
    
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
        glUseProgram(shaderProgram2);
        glBindVertexArray(VAO2);
        glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteProgram(shaderProgram);
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

}
void shaderErrors(unsigned int shader,std::string type)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::"<<type<<"::COMPILATION_FAILED\n" <<
        infoLog << std::endl;   
    }
}
void programErrors(unsigned int program)
{
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS,&success);
    if(!success)
    {
        glGetProgramInfoLog(program,512,NULL,infoLog);
        std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" <<
        infoLog << std::endl;
    }
}