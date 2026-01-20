#include "copyTime.h"

namespace copy
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTime = 0.0f;

	void Time::Initialize()
	{
		// CPU 고유 진동수
		QueryPerformanceFrequency(&cpuFrequency);

		// 프로그램이 시작 했을 때 현재 진동수
		QueryPerformanceCounter(&prevFrequency);
	}

	void Time::Update()
	{	
		QueryPerformanceCounter(&currentFrequency);
		
		// 한 Update에 걸린 진동수
		float differenceFrequency
			= static_cast<float>(currentFrequency.QuadPart - prevFrequency.QuadPart);

		// Update에 걸린 진동 수 / 고유 진동 수 => 한 Update시 걸린 시간
		deltaTime = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);

		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		// 누적 시간 계산
		static float time = 0.0f;

		time += deltaTime;
		// fps 측정
		float fps = 1.0f / deltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", time);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}