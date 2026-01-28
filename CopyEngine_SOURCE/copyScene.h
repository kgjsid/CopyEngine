#pragma once
#include "copyEntity.h"
#include "copyGameObject.h"
#include "copyLayer.h"
#include "CommonInclude.h"

namespace copy
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);

	private:
		std::vector<Layer*> mLayers;
	};
}

