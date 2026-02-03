#pragma once
#include "copyEntity.h"

namespace copy
{
	class Resource abstract : public Entity	// 추상클래스. 순수가상함수가 한개라도 들어있는 클래스
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// 순수가상함수. 실제메모리에 할당이 불가능해지는 문법

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		std::wstring mPath;
		enums::eResourceType mType;
	};
}

// 게임에서 사용되는 데이터들의 종류

// 이미지, 사운드, 플레이데이터, ...

// 순수가상함수
// c++ 에서 메소드 뒤에 =0 이라고 붙이게 되면 이 함수는 선언만 있고 구현이 없다는 문법
// 클래스에서 순수가상함수가 하나라도 포함되면 이 클래스가 추상 클래스가 됨
// 추상 클래스는 직접적으로 객체를 만들 수 없으며 부모의 순수 가상 함수를 모두 구현하여야 함
// 만약, 구현하지 않으면 자식 클래스도 추상 클래스가 됨.

// c++에서는 추상 클래스의 소멸자에는 반드시 virtual 키워드를 붙여야 함