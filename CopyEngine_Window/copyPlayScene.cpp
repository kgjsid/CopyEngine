#include "copyPlayScene.h"
#include "copyGameObject.h"
#include "copyPlayer.h"
#include "copyTransform.h"
#include "copySpriteRenderer.h"

namespace copy
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Player* pl = new Player();

		Transform* tr = pl->AddComponet<Transform>();
		tr->SetPos(800, 450);
		tr->SetName(L"TR");

		SpriteRenderer* sr = pl->AddComponet<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(pl);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}