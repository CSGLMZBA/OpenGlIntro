#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
class Camera
{
    private:
    glm::vec3 direction;
    float pitch,yaw,fov,width,height;
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::mat4 view;
    glm::mat4 projection;

    public:
    Camera()
    {
        pitch = 00.0f;
        yaw  = 00.0f;
        fov = 80.0f;
        width = 800;
        height = 600;
        cameraPos = glm::vec3(-10.0f, 0.0f, 3.0f);
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(direction);
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        projection = glm::perspective(glm::radians(fov), (float)(width / height), 0.2f,
        100.0f);
    }
    void MovePos(glm::vec3& Val)
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * Val.x;

        cameraPos += Val.y * cameraUp;

        cameraPos += Val.z * cameraFront;

        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }
    void ChangeAngle(float& aYaw, float& aPitch)
    {
        yaw = aYaw;
        pitch = aPitch;
        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(direction);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }
    void SetDimentions(float aWidth, float aHeight)
    {
        width = aWidth;
        height = aHeight;
        projection = glm::perspective(glm::radians(fov),(float)(width / height), 0.2f, 100.0f);
    }
    void ChangeFov(float changeval)
    {
        fov+= changeval;
        if (fov < 1.0f)
            fov = 1.0f;
        if (fov > 80.0f)
            fov = 80.0f;
        projection = glm::perspective(glm::radians(fov), (float)(width / height), 0.2f,
        100.0f);
    }
    glm::mat4& GetViewMatrix()
    {
        return view;
    }
    glm::mat4& GetProjectionMatrix()
    {
        return projection;
    }
    
};