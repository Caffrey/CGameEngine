#pragma once

#include "crystal/Core.h"
#include "crystal/Input.h"
namespace Crystal
{
	class  WindowsInput : public Input
	{

	protected:
		virtual bool IsKeyPressImp(int keycode) override;

		virtual bool IsMousePressImp(int mouseButton)override ;
		virtual float IsMouseXImpl()override ;
		virtual float IsMouseYImpl()override ;
		virtual std::pair<float, float> GetMousePositionImpl()override ;
	};
}