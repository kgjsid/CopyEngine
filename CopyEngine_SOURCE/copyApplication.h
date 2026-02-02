#pragma once
#include "CommonInclude.h"
#include "copyGameObject.h"

namespace copy
{
	class Application
	{
	public:
		Application();
		~Application();

		/// <summary>
		/// 초기화 함수
		/// </summary>
		void Initialize(HWND hwnd, UINT mWidth, UINT mHeight);
		void Run();

		/// <summary>
		/// Update 함수
		/// </summary>
		void Update();
		void LateUpdate();
		void Render();

		HDC GetHdc() { return mHdc; }

	private:
		void AdjustRect(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);

	private:
		HWND mHwnd;			// 렌더링 시 항상 창의 인스턴스 정보인 핸들을 요구함.
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBuffer;

		UINT mWidth;
		UINT mHeight;

		// std::vector<Scene*> mScenes;
	};

}