// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PSMTestProceduralSkeletalMeshActor.generated.h"
class UPSMTestProceduralSkeletalMeshComponent;


UCLASS(ClassGroup=FishyProceduralSkeletalMeshTests)
class FISHYPROCEDURALSKELETALMESH_API APSMTestProceduralSkeletalMeshActor : public AActor
{
	GENERATED_BODY()


	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPSMTestProceduralSkeletalMeshComponent> TestProceduralSkeletalMeshComponent;

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
public:
	APSMTestProceduralSkeletalMeshActor();


	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
};
