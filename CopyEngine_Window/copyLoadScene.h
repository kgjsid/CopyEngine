#pragma once
#include "..\\CopyEngine_SOURCE\\copySceneManager.h"

#include "copyPlayScene.h"
#include "copyTitleScene.h"

namespace copy
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}