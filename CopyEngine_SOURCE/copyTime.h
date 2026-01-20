#pragma once
#include "CommonInclude.h"

namespace copy
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return deltaTime; }
	private:
		static LARGE_INTEGER cpuFrequency;		// 컴퓨터의 CPU 고유 진동수
		static LARGE_INTEGER prevFrequency;		// 이전 진동수(한 프레임 이전)
		static LARGE_INTEGER currentFrequency;  // 현재 진동수(현재 프레임)
		static float deltaTime;					// 시간 환산용
	};
}
