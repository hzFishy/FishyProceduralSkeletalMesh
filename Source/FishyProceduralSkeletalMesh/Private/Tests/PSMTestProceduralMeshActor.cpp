// Copyright PushThemAll Dev Team. All Rights Reserved.


#include "Tests/PSMTestProceduralMeshActor.h"
#include "Tests/PSMTestProceduralMeshComponent.h"


	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
APSMTestProceduralMeshActor::APSMTestProceduralMeshActor()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	
	ProceduralMeshComponent = CreateDefaultSubobject<UPSMTestProceduralMeshComponent>("ProceduralMeshComponent");
	ProceduralMeshComponent->SetupAttachment(RootComponent.Get());
}


	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/

