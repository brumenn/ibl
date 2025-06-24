// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#include "IBLPreset.h"

#if WITH_EDITOR
void UIBLPreset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property != nullptr)
	{
		OnChanged.Broadcast();
	}
}
#endif
