#pragma once

namespace copy::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End
	};

	enum class eLayerType
	{
		None,
		BackGround,
		//Tree
		//Character
		Player,
		Max = 16
	};

	enum class eResourceType
	{
		Texture,	// 이미지
		AudioClip,	// 오디오
		Animation,
		Prefab,
		End,
	};
}