#include "copyInput.h"

namespace copy
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initialize()
	{
		mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 1. 키가 눌렸는가
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 1-1. 눌려 있던 상태라면
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Pressed;
				// 1-2. 이전에 눌려 있지 않았다면
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}
			// 2. 키가 눌리지 않았다면
			else
			{
				// 2-1. 이전에 눌려져 있었다면
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Up;
				// 2-2. 이전에 눌려 있지 않았다면
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed = false;
			}
		}
	}
}