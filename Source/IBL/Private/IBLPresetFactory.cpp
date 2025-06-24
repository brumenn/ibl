// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBLPresetFactory.h"
#include "IBLPreset.h"
#include "AssetToolsModule.h"

#define LOCTEXT_NAMESPACE "IBL"

UIBLPresetFactory::UIBLPresetFactory()
	: Super()
{
	SupportedClass = UIBLPreset::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

FText UIBLPresetFactory::GetDisplayName() const
{
	return LOCTEXT("IBLPreset", "IBL Preset");
}

FText UIBLPresetFactory::GetToolTip() const
{
	return LOCTEXT("IBLPreset_Tooltip", "IBL preset is an asset that stores HDRI data to allow quick reuse with IBL actor.");
}

UObject* UIBLPresetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UIBLPreset::StaticClass()));
	return NewObject<UIBLPreset>(InParent, Class, Name, Flags | RF_Transactional, Context);
}

void UIBLPresetFactory::Register()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FATA_UIBLPreset));
}

#undef LOCTEXT_NAMESPACE
