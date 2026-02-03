#include "copyTexture.h"
#include "copyApplication.h"

// extern 키워드
// 해당 변수가 다른 파일 어딘가에 이미 있음을 컴파일러에게 알려주는 선언
// 정의 : 실제로 메모리 공간을 할당하고 변수를 만드는 것
// 선언 : 이런 이름의 변수가 존재한다고 이름만 알려주는 것
// -> extern 키워드는 정의는 다른 파일(main.cpp)에서 했으니 실제 여기에서 해당 변수가 있어서 사용하겠다는 의미(선언)

// 해당 전역변수가 존재함을 알려주는 키워드
extern copy::Application application;

namespace copy::graphcis
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
	{
	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		// 확장자만 추출(. 뒤의 글자만)
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		
		// bmp
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);
			
			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			// mainDC를 가져와서
			HDC mainDC = application.GetHdc();
			// 새로 DC를 만들고
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}

		// png
		if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (mImage == nullptr)
				return S_FALSE;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}
		
		return S_OK;
	}
}