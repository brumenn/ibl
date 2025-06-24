// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBL.h"
#include "IBLStyle.h"
#include "IBLActorPlacement.h"
#include "IBLPreset.h"
#include "IBLPresetFactory.h"
#include "IBLPresetThumbnailRenderer.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "IBL"

void FIBLModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	const FString ShaderDirectory = IPluginManager::Get().FindPlugin(TEXT("IBL"))->GetBaseDir() + FString("/Shaders");
	AddShaderSourceDirectoryMapping("/IBL", ShaderDirectory);

	FIBLStyle::Initialize();
	FIBLStyle::ReloadTextures();
	FIBLActorPlacement::Register();
	UIBLPresetFactory::Register();
	UIBLPresetThumbnailRenderer::Register();
}

void FIBLModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FIBLStyle::Shutdown();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIBLModule, IBL)
