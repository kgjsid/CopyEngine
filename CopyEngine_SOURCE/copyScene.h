#pragma once
#include "copyEntity.h"
#include "copyGameObject.h"

namespace copy
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}

