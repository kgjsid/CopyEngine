#include "copyPlayScene.h"
#include "copyGameObject.h"
#include "copyPlayer.h"
#include "copyTransform.h"
#include "copySpriteRenderer.h"
#include "copyInput.h"
#include "copyTitleScene.h"
#include "copySceneManager.h"

namespace copy
{
	PlayScene::PlayScene()
	{
		bg = nullptr;
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		bg = new Player();
		Transform* tr = bg->AddComponet<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponet<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\Win\\CopyEngine\\Resources\\CloudOcean.png");

		AddGameObject(bg, eLayerType::BackGround);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{	// PlayScene을 다른 Scene으로 전환할 때 위치 초기화
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}