#include "copyScene.h"

namespace copy
{
	Scene::Scene()
	{
		mGameObjects = {};
	}

	Scene::~Scene()
	{
	
	}
	void Scene::Initialize()
	{

	}
	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}