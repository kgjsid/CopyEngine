#include "copyApplication.h"
#include "copyInput.h"
#include "copyTime.h"

namespace copy
{
	Application::Application()
	{
		mHwnd = nullptr;
		mHdc = nullptr;
	}

	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		// GetDC : 핸들을 인자로 DC를 가져오는 메소드
		mHdc = GetDC(mHwnd);

		mPlayer.SetPosition(0.0f, 0.0f);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}