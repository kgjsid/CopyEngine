#pragma once
#include "..\\CopyEngine_SOURCE\\copySceneManager.h"
#include "copyPlayScene.h"


namespace copy
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}