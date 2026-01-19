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
		static std::vector<Key> mKeys;
	};
}

