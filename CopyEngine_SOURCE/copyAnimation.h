#pragma once
#include "copyResource.h"
#include "copyTexture.h"

namespace copy
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{		// 애니메이션 프레임의 이미지 하나를 Sprite
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
			{
				leftTop = Vector2::Zero;
				size = Vector2::Zero;
				offset = Vector2::Zero;
				duration = 0.0f;
			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name			// 애니메이션의 이름(string)
			, graphcis::Texture* spriteSheet	// 애니메이션을 만들어 줄 이미지(texture)
			, Vector2 leftTop					// 애니메이션 이미지에서의 시작 위치
			, Vector2 size						// 애니메이션 이미지 사이즈
			, Vector2 offset					// 애니메이션의 중심점이나 캐릭터의 중점 위치 보정용
			, UINT spriteLength					// 애니메이션 프레임 길이
			, float duration);					// 애니메이션의 재생 길이

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }

	private:
		class Animator* mAnimator;
		graphcis::Texture* mTexture;

		// 전체 이미지를 AnimationSheet
		std::vector<Sprite> mAnimationSheet;

		int mIndex;
		float mTime;
		bool mbComplete;
	};
}
