#include "copyGameObject.h" 
#include "copyInput.h"

namespace copy
{
	GameObject::GameObject()
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redPen);
	}
}