#pragma once
#include "copyResource.h"

namespace copy
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{	// iterator : 해당 데이터에 접근할 수 있는 포인터 변수를 담고있는 클래스
			// std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			// auto : 대입하는 값에 맞춰서 자동으로 자료형을 정해주는 키워드
			auto iter = mResources.find(key);

			// end : 실제 데이터가 없으면 end()를 반환
			if (iter == mResources.end())
				return nullptr;
			
			// first : key(string값), second : value(Resource 포인터)
			// dynamic_cast : 부모-자식간 형변환
			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{	
			T* resource = Resources::Find<T>(key);

			// 이미 로딩된 리소스라면 해당 리소스 반환 
			if (resource != nullptr)
				return resource;

			// 없다면 로드 후 관리를 위한 트리에 추가하여 리턴
			resource = new T();
			if (FAILED(resource->Load(path)))
			{	// 만약 path가 잘못되었거나 없어서 로드에 실패한 경우
				assert(false);
				return nullptr;
			}

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}

