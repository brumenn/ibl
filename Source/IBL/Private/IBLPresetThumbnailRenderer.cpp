// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBLPresetThumbnailRenderer.h"
#include "IBLPreset.h"
#include "Engine/TextureCube.h"
#include "ThumbnailRendering/ThumbnailManager.h"

void UIBLPresetThumbnailRenderer::GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const
{
	UIBLPreset* IBLPreset = Cast<UIBLPreset>(Object);

	if (IBLPreset)
	{
		if (UTextureCube* CubeMap = GetTextureFromGeneratedClass(IBLPreset))
		{
			OutWidth = 0;
			OutHeight = 0;

			if (CubeMap != nullptr)
			{
				Super::GetThumbnailSize(CubeMap, Zoom, OutWidth, OutHeight);
			}
		}
	}
}

void UIBLPresetThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	UIBLPreset* IBLPreset = Cast<UIBLPreset>(Object);
	if (IBLPreset)
	{
		if (UTextureCube* CubeMap = GetTextureFromGeneratedClass(IBLPreset))
		{
			Super::Draw(CubeMap, X, Y, Width, Height, nullptr, Canvas, bAdditionalViewFamily);
		}
	}
}

bool UIBLPresetThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UIBLPreset* IBLPreset = Cast<UIBLPreset>(Object);

	if (IBLPreset && GetTextureFromGeneratedClass(IBLPreset) != nullptr)
	{
		return true;
	}
	return Super::CanVisualizeAsset(Object);
}

UTextureCube* UIBLPresetThumbnailRenderer::GetTextureFromGeneratedClass(UIBLPreset* Class) const
{
	if (Class)
	{
		UTextureCube* texture = Class->Cubemap;

		return texture;
	}
	return nullptr;
}

void UIBLPresetThumbnailRenderer::Register()
{
	UThumbnailManager::Get().RegisterCustomRenderer(UIBLPreset::StaticClass(), UIBLPresetThumbnailRenderer::StaticClass());
}
