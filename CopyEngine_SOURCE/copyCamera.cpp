#include "copyCamera.h"
#include "copyGameObject.h"
#include "copyTransform.h"

namespace copy
{
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
	{
		mDistance = Vector2::Zero;
		mResolution = Vector2(1600.0f, 900.0f);
		mLookPosition = Vector2::Zero;
		
		mTarget = nullptr;
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
	}
	void Camera::Update()
	{
		if (mTarget)
		{	// 타겟이 있다면 해당 타겟을 따라가도록
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		/* 내가 보고 싶은 지점을 화면의 정중앙에 오게 만들기 위함
			mResolution / 2.0f -> 화면의 중심점(ex. 해상도 1000x1000 -> 중심은 500x500)
			mLookPosition -> 카메라가 실제로 위치한 좌표
			mDistance -> 모든 오브젝트를 그릴 때 빼주는 값.
			ex) 
			1. 초기 상태 카메라가 (0, 0)
			mLookPosition : (0, 0) / mDistance : (0 - 500, 0 - 500)
			-> mDistance(-500, -500)인데. 만약 월드에 (0, 0)인 물체가 있다면?
			카메라가 (0, 0)에 있을 땐 물체는 (0 - (-500), 0 - (-500)) -> (500, 500) 딱 정 중앙의 위치.
			  
			2. 여기에서 카메라가 x축으로 500 이동
			mLookPosition : (500, 0) / mDistance : (500 - 500, 0 - 500)
			-> mDistance(0, -500)이고 월드에 동일하게(0, 0)인 물체의 위치는 -> (0 - 0, 0 - (-500))
			카메라가 (500, 0)에 있을 땐 물체는(0, 500)의 위치. 
			-> 즉. 왼쪽 중앙의 위치.(카메라가 오른쪽으로 500만큼 이동해서 물체는 왼쪽으로 간 것처럼 됨)
		*/
		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}