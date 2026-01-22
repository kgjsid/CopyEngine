#include "copyApplication.h"
#include "copyInput.h"
#include "copyTime.h"
#include "copySceneManager.h"

namespace copy
{
	Application::Application()
	{
		mHwnd = nullptr;
		mHdc = nullptr;
		mWidth = 0;
		mHeight = 0;
		mBackHdc = nullptr;
		mBackBuffer = nullptr;
	}

	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		AdjustRect(hwnd, width, height);

		CreateBuffer(width, height);

		Input::Initialize();
		Time::Initialize();

		SceneManager::Initialize();
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

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		ClearRenderTarget();

		// 백버퍼에 먼저 그림
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		CopyRenderTarget(mBackHdc, mHdc);
	}

	void Application::AdjustRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		// GetDC : 핸들을 인자로 DC를 가져오는 메소드
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0,
			mWidth,
			mHeight, 0);
		ShowWindow(hwnd, true);
	}

	void Application::CreateBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::ClearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::CopyRenderTarget(HDC source, HDC dest)
	{	// 백버퍼에 렌더링 된 것을 옮김
		// BackBuffer에 있는 것을 원본 Buffer에 복사
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}