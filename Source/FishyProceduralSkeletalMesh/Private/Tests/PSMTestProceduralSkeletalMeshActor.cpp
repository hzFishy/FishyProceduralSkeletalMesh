// By hzFishy - 2025 - Do whatever you want with it.


#include "Tests/PSMTestProceduralSkeletalMeshActor.h"
#include "Tests/PSMTestProceduralSkeletalMeshComponent.h"

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
APSMTestProceduralSkeletalMeshActor::APSMTestProceduralSkeletalMeshActor()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	
	TestProceduralSkeletalMeshComponent = CreateDefaultSubobject<UPSMTestProceduralSkeletalMeshComponent>("TestProceduralSkeletalMeshComponent");
	TestProceduralSkeletalMeshComponent->SetupAttachment(RootComponent.Get());

}

	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
