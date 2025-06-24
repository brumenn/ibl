// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/TextureThumbnailRenderer.h"
#include "IBLPreset.h"
#include "IBLPresetThumbnailRenderer.generated.h"


/**
 *
 */
UCLASS()
class IBL_API UIBLPresetThumbnailRenderer : public UTextureThumbnailRenderer
{
	GENERATED_BODY()

		UIBLPresetThumbnailRenderer(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{}

	// UThumbnailRenderer implementation
	virtual void GetThumbnailSize(UObject* Object, float Zoom, uint32& OutWidth, uint32& OutHeight) const override;
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget*, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	virtual bool CanVisualizeAsset(UObject* Object) override;

protected:

	UTextureCube* GetTextureFromGeneratedClass(UIBLPreset* Class) const;

public:

	static void Register();
};
