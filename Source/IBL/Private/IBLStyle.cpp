// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBLStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateStyleMacros.h"
#include "Interfaces/IPluginManager.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr< FSlateStyleSet > FIBLStyle::StyleInstance = NULL;

void FIBLStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FIBLStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FIBLStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("IBLStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FIBLStyle::Create()
{
	TSharedRef<FSlateStyleSet> Style = MakeShareable(new FSlateStyleSet("IBLStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("IBL")->GetBaseDir() / TEXT("Resources"));

	// Asset Creation Thumbnail
	Style->Set("IBLActorNative.ModesThumbnail", new IMAGE_BRUSH_SVG(TEXT("IBL_64"), FVector2D(40.0f, 40.0f)));
	Style->Set("IBLPreset.ModesThumbnail", new IMAGE_BRUSH_SVG(TEXT("IBL_64"), FVector2D(40.0f, 40.0f)));

	// Asset Creation Icon
	Style->Set("IBLActorNative.ModesIcon", new IMAGE_BRUSH_SVG(TEXT("IBL_16"), FVector2D(16.0f, 16.0f)));
	Style->Set("IBLPreset.ModesIcon", new IMAGE_BRUSH_SVG(TEXT("IBL_16"), FVector2D(16.0f, 16.0f)));
	
	// Content Browser Thumbnail
	Style->Set("ClassThumbnail.IBLActorNative", new IMAGE_BRUSH_SVG(TEXT("IBL_64"), FVector2D(128.f, 128.f)));
	Style->Set("ClassThumbnail.IBLPreset", new IMAGE_BRUSH_SVG(TEXT("IBL_64"), FVector2D(128.f, 128.f)));

	// World Outliner Icon
	Style->Set("ClassIcon.IBLActorNative", new IMAGE_BRUSH_SVG(TEXT("IBL_16"), FVector2D(16.0f, 16.0f)));
	Style->Set("ClassIcon.IBLPreset", new IMAGE_BRUSH_SVG(TEXT("IBL_16"), FVector2D(16.0f, 16.0f)));

	return Style;
}

void FIBLStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FIBLStyle::Get()
{
	return *StyleInstance;
}
