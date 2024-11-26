#pragma once
#include "gluSet.hpp"

namespace glu{
class Shader
{
private:
    unsigned int mRendererID;
    std::unordered_map<std::string, unsigned int> mUniforms;
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    std::tuple<std::string, std::string> ShadersToStr(const char* vertexPath, const char* fragmentPath);
    void ShaderErrors(unsigned int shader,std::string type);
    void ProgramErrors(unsigned int program);
    void Use();
public:
    void SetUniform(const std::string& name, int a);
    void SetUniform(const std::string& name, int a1, int a2);
    void SetUniform(const std::string& name, int a1, int a2, int a3);
    void SetUniform(const std::string& name, int a1, int a2, int a3, int a4);
    void SetUniform(unsigned int location, int a);
    void SetUniform(unsigned int location, int a1, int a2);
    void SetUniform(unsigned int location, int a1, int a2, int a3);
    void SetUniform(unsigned int location, int a1, int a2, int a3, int a4);

    void SetUniform(const std::string& name, float a);
    void SetUniform(const std::string& name, float a1, float a2);
    void SetUniform(const std::string& name, float a1, float a2, float a3);
    void SetUniform(const std::string& name, float a1, float a2, float a3, float a4);
    void SetUniform(unsigned int location, float a);
    void SetUniform(unsigned int location, float a1, float a2);
    void SetUniform(unsigned int location, float a1, float a2, float a3);
    void SetUniform(unsigned int location, float a1, float a2, float a3, float a4);

    void SetUniform(const std::string& name, bool a);
    void SetUniform(const std::string& name, bool a1, bool a2);
    void SetUniform(const std::string& name, bool a1, bool a2, bool a3);
    void SetUniform(const std::string& name, bool a1, bool a2, bool a3, bool a4);
    void SetUniform(unsigned int location, bool a);
    void SetUniform(unsigned int location, bool a1, bool a2);
    void SetUniform(unsigned int location, bool a1, bool a2, bool a3);
    void SetUniform(unsigned int location, bool a1, bool a2, bool a3, bool a4);

    void SetUniform(const std::string& name, glm::mat4& Matrix,bool Transpose = false);
    void SetUniform(unsigned int location, glm::mat4& Matrix,bool Transpose = false);
};
}