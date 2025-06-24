// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Factories/Factory.h"
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"
#include "IBLActorNativeFactory.generated.h"

#define LOCTEXT_NAMESPACE "IBL"

/**
 *
 */
UCLASS()
class IBL_API UIBLActorNativeFactory : public UFactory
{
	GENERATED_BODY()

protected:

	virtual bool IsMacroFactory() const { return false; }

public:

	UIBLActorNativeFactory();

	// The parent class of the created blueprint
	UPROPERTY(EditAnywhere, Category = BlueprintFactory, meta = (AllowAbstract = "", BlueprintBaseOnly = ""))
	TSubclassOf<class UObject> ParentClass;

public:

	virtual bool ShouldShowInNewMenu() const override { return true; }
	virtual FText GetDisplayName() const override;
	virtual FText GetToolTip() const override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

};

#undef LOCTEXT_NAMESPACE
