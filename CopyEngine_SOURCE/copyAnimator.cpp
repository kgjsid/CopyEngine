#include "copyAnimator.h"

namespace copy
{
	Animator::Animator()
		:Component(enums::eComponentType::Animator)
	{
		mAnimations = {};
		mActiveAnimation = nullptr;
		mbLoop = false;
	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() && mbLoop)
			{
				mActiveAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
	}
}