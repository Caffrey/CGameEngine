#include "cpch.h"
#include "crystal/imgui/ImguiLayer.h"
#include "crystal/Application.h"
#include "crystal/event/Event.h"
#include "crystal/platform/KeyCode.h"
#include "crystal/platform/MouseCode.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "platform/opengl/imgui_impl_opengl3.h"


namespace Crystal
{

	ImguiLayer::ImguiLayer() : Layer("ImguiLayer")
	{

	}


	ImguiLayer::~ImguiLayer()
	{

	}

	void ImguiLayer::OnAttch()
	{
		ImGui::CreateContext();

		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = CL_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = CL_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = CL_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = CL_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = CL_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = CL_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = CL_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = CL_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = CL_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = CL_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = CL_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = CL_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = CL_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = CL_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = CL_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = CL_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = CL_KEY_A;
		io.KeyMap[ImGuiKey_C] = CL_KEY_C;
		io.KeyMap[ImGuiKey_V] = CL_KEY_V;
		io.KeyMap[ImGuiKey_X] = CL_KEY_X;
		io.KeyMap[ImGuiKey_Y] = CL_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = CL_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");

	}

	void ImguiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
		m_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool  show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}



	void ImguiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseMovedEvent>(CL_BIND_EVENT(ImguiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(CL_BIND_EVENT(ImguiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<MouseButtonPressedEvent>(CL_BIND_EVENT(ImguiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(CL_BIND_EVENT(ImguiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<KeyPressedEvent>(CL_BIND_EVENT(ImguiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(CL_BIND_EVENT(ImguiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(CL_BIND_EVENT(ImguiLayer::OnKeyTypedEvent));
	}

	bool ImguiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		return false;
	}

	bool ImguiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();
		
		return false;
	}

	bool ImguiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;


		return false;
	}

	bool ImguiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImguiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKey()] = true;

		io.KeyCtrl = io.KeysDown[CL_KEY_RIGHT_CONTROL] || io.KeysDown[CL_KEY_LEFT_CONTROL];
		io.KeyShift = io.KeysDown[CL_KEY_RIGHT_SHIFT] || io.KeysDown[CL_KEY_LEFT_SHIFT];
		io.KeyAlt = io.KeysDown[CL_KEY_RIGHT_ALT] || io.KeysDown[CL_KEY_LEFT_ALT];
		io.KeySuper = io.KeysDown[CL_KEY_RIGHT_SUPER] || io.KeysDown[CL_KEY_LEFT_SUPER];

		return false;
	}

	bool ImguiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKey()] = false;
		return false;
	}

	bool ImguiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{

		ImGuiIO& io = ImGui::GetIO();
		char c = e.GetKeyCode();
		if (c > 0 && c < 0x10000)
			io.AddInputCharacter((unsigned short)c);


		return false;
	}

	bool ImguiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return false;
	}

	void ImguiLayer::OnDetch()
	{

	}

}