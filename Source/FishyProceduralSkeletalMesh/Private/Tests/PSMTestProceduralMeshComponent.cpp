// By hzFishy - 2025 - Do whatever you want with it.


#include "Tests/PSMTestProceduralMeshComponent.h"



	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
UPSMTestProceduralMeshComponent::UPSMTestProceduralMeshComponent(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
void UPSMTestProceduralMeshComponent::CreateMeshFromData()
{
	ClearAllMeshSections();

	// Assign the geometry data to the mesh component
	for (int i = 0; i < SectionsData.Num(); ++i)
	{
		auto& CurrentSection = SectionsData[i];

		CreateMeshSection_LinearColor(
			0,
			CurrentSection.Vertices,
			CurrentSection.Triangles,
			CurrentSection.Normals,
			CurrentSection.UVs,
			CurrentSection.VertexColors,
			TArray<FProcMeshTangent>(),
			CurrentSection.bCreateCollision
		);
		SetMaterial(i, CurrentSection.Material);
	}
}
