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