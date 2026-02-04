#pragma once
#include "copyComponent.h"
#include "copyGameObject.h"

namespace copy
{
	using namespace copy::math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; };
		
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mTarget;	// 만약 오브젝트를 따라간다면, 해당 오브젝트
		
		Vector2 mDistance;		// 카메라와의 거리
		Vector2 mResolution;	// 해상도
		Vector2 mLookPosition;	// 카메라의 위치
	};
}

