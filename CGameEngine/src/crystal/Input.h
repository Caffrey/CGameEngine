#pragma once

#include "crystal/Core.h"
#include <utility>

namespace Crystal
{
	class CRYSTAL_API Input
	{
	public:
		inline static bool IsKeyPress(int keycode) { return s_Instance->IsKeyPressImp(keycode); }
		inline static bool IsMouseButtonPress(int mouseButton) { return s_Instance->IsMousePressImp(mouseButton); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->IsMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->IsMouseYImpl(); }

	protected:
		virtual bool IsKeyPressImp(int keycode) = 0;
		virtual bool IsMousePressImp(int mouseButton) = 0;
		virtual float IsMouseXImpl() = 0;
		virtual float IsMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;

	private:
		static Input* s_Instance;
	};
}