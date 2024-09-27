#include <GLU/shader.hpp>

Shader::Shader(const char *vertexPath, const char *fragmentPath) 
{
    auto [vShaderSourceS,fShaderSourceS] = ShadersToStr(vertexPath, fragmentPath);
    const char* vShaderSource = vShaderSourceS.c_str(); 
     const char* fShaderSource = fShaderSourceS.c_str(); 
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vShaderSource,NULL);
    glCompileShader(vertexShader);
    ShaderErrors(vertexShader,"VERTEX");
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fShaderSource,NULL);
    glCompileShader(fragmentShader);
    ShaderErrors(fragmentShader,"SOURCE");
    mRendererID = glCreateProgram();
    glAttachShader(mRendererID,vertexShader);
    glAttachShader(mRendererID, fragmentShader);
    glLinkProgram(mRendererID); 
    ProgramErrors(mRendererID);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

}
Shader::~Shader() 
{
    glDeleteProgram(mRendererID);
}

std::tuple<std::string, std::string> Shader::ShadersToStr(const char* vertexPath, const char* fragmentPath) 
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file’s buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    
    return {vertexCode, fragmentCode};
}

void Shader::ShaderErrors(unsigned int shader,std::string type)
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
void Shader::ProgramErrors(unsigned int program)
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
void Shader::Use() 
{
    glUseProgram(mRendererID);
}

void Shader::SetUniform(const std::string& name, int a) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform1i(mUniforms[name], a);
}

void Shader::SetUniform(const std::string& name, int a1, int a2) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform2i(mUniforms[name], a1,a2);
}

void Shader::SetUniform(const std::string& name, int a1, int a2, int a3) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform3i(mUniforms[name], a1,a2,a3);
}

void Shader::SetUniform(const std::string& name, int a1, int a2, int a3, int a4) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform4i(mUniforms[name], a1,a2,a3,a4);
}

void Shader::SetUniform(unsigned int location, int a) {
    glUniform1i(location, a);
}

void Shader::SetUniform(unsigned int location, int a1, int a2) {
    glUniform2i(location, a1,a2);
}

void Shader::SetUniform(unsigned int location, int a1, int a2, int a3) {
    glUniform3i(location, a1,a2,a3);
}

void Shader::SetUniform(unsigned int location, int a1, int a2, int a3, int a4) {
    glUniform4i(location, a1,a2,a3,a4);
}

void Shader::SetUniform(const std::string& name, float a) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform1f(mUniforms[name], a);
}

void Shader::SetUniform(const std::string& name, float a1, float a2) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform2f(mUniforms[name], a1,a2);
}

void Shader::SetUniform(const std::string& name, float a1, float a2, float a3) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform3f(mUniforms[name], a1,a2,a3);
}

void Shader::SetUniform(const std::string& name, float a1, float a2, float a3, float a4) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform4f(mUniforms[name], a1,a2,a3,a4);
}

void Shader::SetUniform(unsigned int location, float a) {
    glUniform1f(location, a);
}

void Shader::SetUniform(unsigned int location, float a1, float a2) {
    glUniform2f(location, a1,a2);
}

void Shader::SetUniform(unsigned int location, float a1, float a2, float a3) {
    glUniform3f(location, a1,a2,a3);
}

void Shader::SetUniform(unsigned int location, float a1, float a2, float a3, float a4) {
    glUniform4f(location, a1,a2,a3,a4);
}

void Shader::SetUniform(const std::string& name, bool a) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform1i(mUniforms[name], (int)a);
}

void Shader::SetUniform(const std::string& name, bool a1, bool a2) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform2i(mUniforms[name], (int)a1,(int)a2);
}

void Shader::SetUniform(const std::string& name, bool a1, bool a2, bool a3) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform3i(mUniforms[name], (int)a1,(int)a2,(int)a3);
}

void Shader::SetUniform(const std::string& name, bool a1, bool a2, bool a3, bool a4) 
{
    if (mUniforms.find(name) != mUniforms.end())
    {
        mUniforms[name] = glGetUniformLocation(mRendererID, name.c_str());
    }
    glUniform4i(mUniforms[name], (int)a1,(int)a2,(int)a3,(int)a4);
}

void Shader::SetUniform(unsigned int location, bool a) {
    glUniform1i(location, (int)a);
}

void Shader::SetUniform(unsigned int location, bool a1, bool a2) {
    glUniform2i(location, (int)a1,(int)a2);
}

void Shader::SetUniform(unsigned int location, bool a1, bool a2, bool a3) {
    glUniform3i(location, (int)a1,(int)a2,(int)a3);
}

void Shader::SetUniform(unsigned int location, bool a1, bool a2, bool a3, bool a4) {
    glUniform4i(location, (int)a1,(int)a2,(int)a3,(int)a4);
}
