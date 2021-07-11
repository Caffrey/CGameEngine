#include "cpch.h"
#include "WindowsInput.h"

#include "crystal/Application.h"

#include "crystal/platform/KeyCode.h"
#include "crystal/platform/MouseCode.h"

#include <GLFW/glfw3.h>

namespace Crystal {

	Input* Input::s_Instance = new WindowsInput();


	bool WindowsInput::IsKeyPressImp(int keycode)
	{

		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == CL_KEY_PRESS || state == CL_KEY_REPEAT;
	}

	bool WindowsInput::IsMousePressImp(int mouseButton)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, mouseButton);

		return state == CL_MOUSE_PRESS;
	}

	float WindowsInput::IsMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;

	}

	float WindowsInput::IsMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

}