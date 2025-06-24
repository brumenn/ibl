// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBLActorPlacement.h"
#include "IPlacementModeModule.h"
#include "ActorFactories/ActorFactoryBlueprint.h"

#define LOCTEXT_NAMESPACE "IBL"

void FIBLActorPlacement::Register()
{
	UBlueprint* IBLActor = Cast<UBlueprint>(FSoftObjectPath(TEXT("/IBL/Actors/IBLActor.IBLActor")).TryLoad());
	if (IBLActor == nullptr)
	{
		return;
	}

	IPlacementModeModule& PlacementModeModule = IPlacementModeModule::Get();
	FPlacementCategoryInfo Info = *PlacementModeModule.GetRegisteredPlacementCategory(FBuiltInPlacementCategories::Lights());
	FPlaceableItem* IBLActorPlacement = new FPlaceableItem(
		*UActorFactoryBlueprint::StaticClass(),
		FAssetData(IBLActor, true),
		FName("IBLActorNative.ModesThumbnail"),
		FName("IBLActorNative.ModesIcon"),
		TOptional<FLinearColor>(),
		TOptional<int32>(),
		NSLOCTEXT("PlacementMode", "IBL", "IBL")
	);

	IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(IBLActorPlacement));
}

#undef LOCTEXT_NAMESPACE
