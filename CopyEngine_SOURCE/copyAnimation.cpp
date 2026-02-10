#include "copyAnimation.h"
#include "copyTime.h"

namespace copy
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
	{
		class Animator* mAnimator = nullptr;
		graphcis::Texture* mTexture = nullptr;
		std::vector<Sprite> mAnimationSheet = {};

		int mIndex = 0;
		float mTime = 0.0f;
		bool mbComplete = false;
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}
	void Animation::Render(HDC hdc)
	{
	}
	void Animation::CreateAnimation(const std::wstring& name, graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
	}
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}