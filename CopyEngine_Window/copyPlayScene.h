#pragma once
#include "..\\CopyEngine_SOURCE\\copyScene.h"

namespace copy
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}

