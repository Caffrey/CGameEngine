#include "cpch.h"
#include "LayerStack.h"

namespace Crystal {
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
		layer->OnAttch();
	}

	void LayerStack::PushOverLayer(Layer* layer)
	{
		m_Layers.emplace_back(layer);
		layer->OnAttch();
	}

	void LayerStack::PopPlayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			(*it)->OnDetch();
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			(*it)->OnDetch();
			m_Layers.erase(it);
		}
	}

}