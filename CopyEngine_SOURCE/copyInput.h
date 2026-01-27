#pragma once
#include "CommonInclude.h"

namespace copy
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;	// 해당 키(W, S, C...)
			eKeyState state;	// 키의 상태
			bool bPressed;		// 눌린 상태인지
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Up; }
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Pressed; }

	private:
		// std::vector
		// 연속된 메모리를 사용하는 동적 배열(C#의 리스트와 유사)
		// 연속된 메모리이므로 접근이 빠르고 뒤에 추가하는 행위는 매우 빠름
		// 다만 중간의 삽입 삭제는 느리며 캐시 효율이 좋음
		static std::vector<Key> mKeys;
	};
}

