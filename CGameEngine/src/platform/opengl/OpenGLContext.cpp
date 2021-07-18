#include "cpch.h"
#include "OpenGLContext.h"

#include "crystal/CLog.h"
#include "crystal/Core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>



Crystal::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle):m_WindowHandle(windowHandle)
{
	CL_CORE_ASSERT(m_WindowHandle, "Window Handle Is Null !");
}

void Crystal::OpenGLContext::Init()
{
	// ^
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	CL_CORE_ASSERT(status, "Failed to init  glad!");
}

void Crystal::OpenGLContext::SwapBuffer()
{
	glfwSwapBuffers(m_WindowHandle);

}
