#pragma once

#include "crystal/Core.h"
#include "Layer.h"

#include <vector>

namespace Crystal {
	
	class CRYSTAL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* layer);
		void PopPlayer(Layer* layer);
		void PopOverLayer(Layer* layer);


		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int  m_LayerInsertIndex = 0;
	};

}