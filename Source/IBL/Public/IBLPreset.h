// Copyright (c) 2022 Nicolas Castelli. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IBLPreset.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChanged);

/**
 *
 */
USTRUCT(BlueprintType, Blueprintable)
struct IBL_API FDirectionalLights
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Intensity_ = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color_ = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation_;
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Category = "Miscellaneous")
class IBL_API UIBLPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

#endif

	UPROPERTY(BlueprintAssignable)
	FOnChanged OnChanged;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IBL", AssetRegistrySearchable)
	UTextureCube* Cubemap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IBL")
	double Intensity = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IBL", DisplayName = "Exposure Value (EV)", meta = (UIMin = "-6.0", UIMax = "21.0"))
	double ExposureValue = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IBL")
	TArray<FDirectionalLights> DirectionalLights;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Backdrop")
	double Offset = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Backdrop", DisplayName = "Size (m)", meta = (Units = "Meters", AllowPreserveRatio))
	FVector Size = FVector(500, 500, 500);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Backdrop")
	FVector ProjectionCenter = FVector(0, 0, 170);
};
