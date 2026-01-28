#pragma once
#include "copyScene.h"

namespace copy
{
	class SceneManager
	{
	public:
		// 템플릿(template)
		// 매개변수의 타입에 따라 함수/클래스를 생성하는 기능
		// template 문법을 사용하여 함수에서 자료형을 유동적으로 지정할 수 있음
		// 일반적으로 T라는 표기를 사용, 함수 또는 클래스를 호출할 때 원하는 자료형을 입력하면 해당 자료형으로 동작하는 코드 생성
		// 실행 시가 아닌 컴파일 시점에 자료형을 결정.
		// (C#의 Generic 문법과 유사)
		// 
		// ex. 아래 문법은 scene을 생성할 때, template문법을 사용하는 경우
		// Scene 클래스를 상속 받은 PlayScene, EndScene을 만들기 위함.
		// CreateScene<PlayScene>(L"PlayScene");
		// CreateScene<EndScene>(L"EndScene");
		// 위와 같이 사용할 경우, T는 특정 클래스(PlayScene, EndScene)이 된다고 생각
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
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

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		// std::map
		// 키-값 기반으로 저장되는 자료구조(C#의 SortedDictionary와 유사)
		// key 기준으로 오름차순 정렬되는 자료구조.
		// 내부 구조는 트리 구조(Red-Black Tree). 순회 시 항상 정렬된 상태
		static std::map<const std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

