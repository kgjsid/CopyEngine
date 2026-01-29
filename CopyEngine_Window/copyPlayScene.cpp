#include "copyPlayScene.h"
#include "copyGameObject.h"
#include "copyPlayer.h"
#include "copyTransform.h"
#include "copySpriteRenderer.h"
#include "copyInput.h"
#include "copyTitleScene.h"
#include "copySceneManager.h"
#include "copyObject.h"

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
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));

		SpriteRenderer* sr = bg->AddComponet<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\Win\\CopyEngine\\Resources\\CloudOcean.png");
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
		tr->SetPosition(Vector2(0, 0));
	}
}