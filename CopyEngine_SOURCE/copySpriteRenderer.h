#pragma once
#include "copyEntity.h"
#include "copyComponent.h"
#include "copyTexture.h"

namespace copy
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphcis::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphcis::Texture* mTexture;
		math::Vector2 mSize;
	};
}