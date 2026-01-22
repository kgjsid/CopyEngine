#pragma once
#include "..\\CopyEngine_SOURCE\\copySceneManager.h"
#include "copyPlayScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\CopyEngine_Window.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\CopyEngine_Window.lib")
#endif

namespace copy
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}