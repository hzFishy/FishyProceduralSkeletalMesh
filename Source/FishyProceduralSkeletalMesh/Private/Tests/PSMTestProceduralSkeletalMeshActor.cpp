// Copyright PushThemAll Dev Team. All Rights Reserved.


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
