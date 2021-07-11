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

		virtual void OnAttch() override;
		virtual void OnDetch()override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;
		virtual void ImguiRenderer()override;
		void Begin();
		void End();

	private:
		float m_time = 0;
	};


}