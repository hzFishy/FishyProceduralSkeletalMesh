// Copyright PushThemAll Dev Team. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PSMTestProceduralMeshActor.generated.h"
class UPSMTestProceduralMeshComponent;


UCLASS()
class FISHYPROCEDURALSKELETALMESH_API APSMTestProceduralMeshActor : public AActor
{
	GENERATED_BODY()

	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPSMTestProceduralMeshComponent> ProceduralMeshComponent;

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
public:
	APSMTestProceduralMeshActor();


	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/

};
