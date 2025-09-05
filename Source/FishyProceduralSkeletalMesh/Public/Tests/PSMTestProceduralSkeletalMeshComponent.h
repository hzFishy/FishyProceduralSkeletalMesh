// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "PSMTestProceduralSkeletalMeshComponent.generated.h"
class USkeletalMesh;
class USkeletalMeshComponent;


UCLASS(ClassGroup=(FishyProceduralSkeletalMeshTests), meta=(BlueprintSpawnableComponent))
class FISHYPROCEDURALSKELETALMESH_API UPSMTestProceduralSkeletalMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()


	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
protected:
	UPROPERTY(EditAnywhere, Category="FishyProceduralSkeletalMesh|Setup")
	TSoftObjectPtr<USkeletalMesh> SourceSkeletalMesh;

	UPROPERTY(EditAnywhere, Category="FishyProceduralSkeletalMesh|Setup")
	bool bCreateCollision;

	UPROPERTY(EditAnywhere, Category="FishyProceduralSkeletalMesh|Setup")
	bool bSimulatePhysics;

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
public:
	UPSMTestProceduralSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer);


	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
public:
	UFUNCTION(BlueprintCallable, Category="FishyProceduralSkeletalMesh")
	void CreateProceduralSkeletalMeshFromData(USkeletalMeshComponent* SkeletalMeshComponent, int32 LODIndex);
};
