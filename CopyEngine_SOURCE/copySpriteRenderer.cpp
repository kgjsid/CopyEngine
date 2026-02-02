#include "copySpriteRenderer.h"
#include "copyGameObject.h"
#include "copyTransform.h"
#include "copyTexture.h"

namespace copy
{
	SpriteRenderer::SpriteRenderer()
		: Component()
	{
		mTexture = nullptr;
		mSize = Vector2::One;
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		
		if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));	// 리소스 이미지에서 제외할 색상(마젠타 색 제거)
		}
		else if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth(), mTexture->GetHeight()));
		}
	}
}