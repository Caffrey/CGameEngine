#pragma once

#include "cpch.h"

#include "spdlog/fmt/ostr.h"

#include "crystal/Core.h"

namespace Crystal
{
	enum class KeyCode
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, Y, Z,
		SHIFT, CTRL, ALT, N1, N2, N3, N4, N5, N6, N7, N8, N9, N0
	};

	enum class MouseCode
	{
		LMB, MMB, RMB
	};




	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};


#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	class CRYSTAL_API Event
	{
	public:
		virtual ~Event() = default;

		bool Handle = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class CRYSTAL_API EventDispatcher
	{


	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				func(static_cast<T&>(m_Event));
				m_Event.Handle = true;
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
	inline std::ostream& operator<<(std::ostream& os, const KeyCode& e)
	{
		return os << e;
	}
	inline std::ostream& operator<<(std::ostream& os, const MouseCode& e)
	{
		return os << e;
	}



}