#pragma once
#include "crystal/layer/Layer.h"

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
		float m_time = 0;
	};


}