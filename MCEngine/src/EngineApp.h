#pragma once
#include "Macros.h"

namespace MCEngine {
	class ENGINE_API EngineApp
	{
	public:
		int start();
        static EngineApp* getEngineApp()
        {
            if (engineApp == nullptr)
            {
                engineApp = new EngineApp();

                return engineApp;
            }
            else
            {
                return engineApp;
            }
        }
	private:
		static EngineApp* engineApp;
	protected:
        EngineApp();
		~EngineApp();
	};
}