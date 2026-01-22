#include "copySceneManager.h"

namespace copy
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<const std::wstring, Scene*> SceneManager::mScene = {};

	void SceneManager::Initialize()
	{

	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}