// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBLActorNativeFactory.h"
#include "IBLActorNative.h"
#include "AssetToolsModule.h"
#include "EditorUtilityBlueprint.h"
#include "Kismet2/KismetEditorUtilities.h"

#define LOCTEXT_NAMESPACE "IBL"

UIBLActorNativeFactory::UIBLActorNativeFactory()
	: Super()
{
	SupportedClass = UEditorUtilityBlueprint::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

FText UIBLActorNativeFactory::GetDisplayName() const
{
	return LOCTEXT("IBLActorNative", "IBL Actor Native");
}

FText UIBLActorNativeFactory::GetToolTip() const
{
	return LOCTEXT("IBLActorNative_Tooltip", "Native class used by IBL actor.");
}

UObject* UIBLActorNativeFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UEditorUtilityBlueprint::StaticClass()));
	ParentClass = AIBLActorNative::StaticClass();
	return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UEditorUtilityBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass());
}

#undef LOCTEXT_NAMESPACE
