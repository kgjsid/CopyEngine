#pragma once
#include "..\\CopyEngine_SOURCE\\copyResources.h"
#include "..\\CopyEngine_SOURCE\\copyTexture.h"

namespace copy
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"D:\\Win\\CopyEngine\\Resources\\CloudOcean.png");
	}
}
