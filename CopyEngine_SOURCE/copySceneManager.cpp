#include "copySceneManager.h"

namespace copy
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<const std::wstring, Scene*> SceneManager::mScene = {};

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)			// 이전 Scene의 OnExit()
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();	// 새로 진입하는 Scene의 OnEnter();

		return iter->second;
	}

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