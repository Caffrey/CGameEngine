#pragma once

#include "crystal/Core.h"
#include "crystal/layer/Layer.h"

#include "crystal/event/ApplicationEvent.h"
#include "crystal/event/MouseEvent.h"
#include "crystal/event/KeyEvent.h"


namespace Crystal
{
	class CRYSTAL_API ImguiLayer : public Layer
	{
	public:

		ImguiLayer();
		~ImguiLayer();

		void OnAttch();
		void OnDetch();
		void OnUpdate() override;
		void OnEvent(Event& event) override;


	private:
		
		bool OnMouseMovedEvent(MouseMovedEvent &e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);

	private:
		float m_time = 0;
	};


}