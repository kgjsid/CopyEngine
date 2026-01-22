#pragma once
#include "copySceneManager.h"
#include "copyPlayScene.h"

namespace copy
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		// SceneManager::CreateScene<EndScene>(L"EndScene");
		// SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}