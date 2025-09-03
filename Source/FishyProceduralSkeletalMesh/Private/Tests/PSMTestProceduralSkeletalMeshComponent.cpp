// Copyright PushThemAll Dev Team. All Rights Reserved.


#include "Tests/PSMTestProceduralSkeletalMeshComponent.h"
#include "Rendering/SkeletalMeshRenderData.h"

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
UPSMTestProceduralSkeletalMeshComponent::UPSMTestProceduralSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer),
	bCreateCollision(true),
	bSimulatePhysics(false)
{
	PrimaryComponentTick.bCanEverTick = false;
}

	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
void UPSMTestProceduralSkeletalMeshComponent::CreateProceduralSkeletalMeshFromData(USkeletalMeshComponent* SkeletalMeshComponent, int32 LODIndex)
{
	if (!IsValid(SkeletalMeshComponent)) { return; }
	
	FSkeletalMeshRenderData* SKMRenderData = SkeletalMeshComponent->GetSkeletalMeshRenderData();
	const FSkeletalMeshLODRenderData& DataArray = SKMRenderData->LODRenderData[LODIndex];
	FSkinWeightVertexBuffer& SkinWeights = *SkeletalMeshComponent->GetSkinWeightBuffer(LODIndex);

	TArray<FVector> VerticesArray;
	TArray<FVector> Normals;
	TArray<FVector2D> UV;
	TArray<FColor> Colors;
	TArray<FProcMeshTangent> Tangents;
	TArray<UMaterialInterface*> Materials;
	
	for (int32 ReaderSectionIndex = 0; ReaderSectionIndex < DataArray.RenderSections.Num(); ReaderSectionIndex++)
	{
		const auto& SectionData = DataArray.RenderSections[ReaderSectionIndex];
		
		// get num vertices and offset 
		const int32 NumSourceVertices = SectionData.NumVertices;
		const int32 BaseVertexIndex = SectionData.BaseVertexIndex;

		Materials.Emplace(SkeletalMeshComponent->GetMaterial(SectionData.MaterialIndex));
		
		for (int32 i = 0; i < NumSourceVertices; i++)
		{
			const int32 VertexIndex = i + BaseVertexIndex;

			// get skinned vector positions
			const FVector3f SkinnedVectorPos = USkeletalMeshComponent::GetSkinnedVertexPosition(
				SkeletalMeshComponent, VertexIndex, DataArray, SkinWeights);
			VerticesArray.Emplace(SkinnedVectorPos.X, SkinnedVectorPos.Y, SkinnedVectorPos.Z);

			// Calc normals and tangents from the static version instead of the skeletal one
			const FVector3f ZTangentStatic = DataArray.StaticVertexBuffers.StaticMeshVertexBuffer.VertexTangentZ(
				VertexIndex);
			const FVector3f XTangentStatic = DataArray.StaticVertexBuffers.StaticMeshVertexBuffer.VertexTangentX(
				VertexIndex);

			// add normals from the static mesh version instead because using the skeletal one doesnt work right.
			Normals.Emplace(ZTangentStatic.X, ZTangentStatic.Y, ZTangentStatic.Z);

			// add tangents
			Tangents.Add(FProcMeshTangent(FVector(XTangentStatic.X, XTangentStatic.Y, XTangentStatic.Z), false));

			// get UVs
			const FVector2f SourceUVs = DataArray.StaticVertexBuffers.StaticMeshVertexBuffer.GetVertexUV(VertexIndex, 0);
			UV.Emplace(SourceUVs);

			// dummy vertex colors
			Colors.Add(FColor::Red);
		}
	}

	// get index buffer
	FMultiSizeIndexContainerData IndicesData;
	DataArray.MultiSizeIndexContainer.GetIndexBuffer(IndicesData.Indices);


	for (int32 RenderSectionIndex = 0; RenderSectionIndex < DataArray.RenderSections.Num(); RenderSectionIndex++)
	{
		const auto& SectionData = DataArray.RenderSections[RenderSectionIndex];
		TArray<int32> Tris;

		// get number triangles and offset
		const int32 SectionNumTriangles = SectionData.NumTriangles;
		const int32 SectionBaseIndex = SectionData.BaseIndex;
		
		// iterate over num indices and add traingles
		for (int32 i = 0; i < SectionNumTriangles; i++)
		{
			int32 TriVertexIndex = i*3 + SectionBaseIndex;
			Tris.Add(IndicesData.Indices[TriVertexIndex]);
			Tris.Add(IndicesData.Indices[TriVertexIndex + 1]);
			Tris.Add(IndicesData.Indices[TriVertexIndex + 2]);
		}

		// Create the procedural mesh section
		CreateMeshSection(RenderSectionIndex, VerticesArray, Tris, Normals, UV, Colors, Tangents, bCreateCollision);
		SetMaterial(RenderSectionIndex, Materials[RenderSectionIndex]);
	}

	if (bSimulatePhysics)
	{
		SetSimulatePhysics(true);
	}
}
