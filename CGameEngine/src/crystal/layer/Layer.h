#pragma once

#include "crystal/Core.h"
#include "crystal/event/Event.h"


namespace Crystal {
	class CRYSTAL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");

		virtual ~Layer();

		virtual void OnAttch() {}
		virtual void OnDetch() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		virtual void ImguiRenderer() {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};
}