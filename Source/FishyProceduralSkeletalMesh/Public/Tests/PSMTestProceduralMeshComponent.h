// Copyright PushThemAll Dev Team. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "PSMTestSharedTypes.h"
#include "PSMTestProceduralMeshComponent.generated.h"




UCLASS(ClassGroup=(FishyProceduralSkeletalMeshTests), Blueprintable, meta=(BlueprintSpawnableComponent))
class FISHYPROCEDURALSKELETALMESH_API UPSMTestProceduralMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()


	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
public:
	UPROPERTY(EditAnywhere, Category="FishyProceduralSkeletalMesh|Setup")
	TArray<FPSMTestSectionData> SectionsData;

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
public:
	UPSMTestProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);


	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
public:
	UFUNCTION(BlueprintCallable, Category="FishyProceduralSkeletalMesh")
	void CreateMeshFromData();
};
