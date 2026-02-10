#pragma once
#include "copyComponent.h"
#include "copyAnimation.h"

namespace copy
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation( const std::wstring& name			// 애니메이션의 이름(string)
							, graphcis::Texture* spriteSheet	// 애니메이션을 만들어 줄 이미지(texture)
						    , Vector2 leftTop					// 애니메이션 이미지에서의 시작 위치
							, Vector2 size						// 애니메이션 이미지 사이즈
							, Vector2 offset					// 애니메이션의 중심점이나 캐릭터의 중점 위치 보정용
							, UINT spriteLength					// 애니메이션 프레임 길이
							, float duration);					// 애니메이션의 재생 길이

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
	};
}

