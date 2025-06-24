// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Factories/Factory.h"
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"
#include "IBLPreset.h"
#include "IBLPresetFactory.generated.h"

#define LOCTEXT_NAMESPACE "IBL"

/**
 *
 */
UCLASS()
class IBL_API UIBLPresetFactory : public UFactory
{
	GENERATED_BODY()

protected:

	virtual bool IsMacroFactory() const { return false; }

public:

	UIBLPresetFactory();

public:

	virtual bool ShouldShowInNewMenu() const override { return true; }
	virtual FText GetDisplayName() const override;
	virtual FText GetToolTip() const override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

public:

	static void Register();
};

/**
 *
 */
class FATA_UIBLPreset : public FAssetTypeActions_Base
{

public:

	virtual FText GetName() const override { return LOCTEXT("IBLPreset", "IBL Preset"); }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Type::Textures; }
	virtual FColor GetTypeColor() const override { return FColor(127, 100, 255); }
	virtual UClass* GetSupportedClass() const override { return UIBLPreset::StaticClass(); }
};

#undef LOCTEXT_NAMESPACE
