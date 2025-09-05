// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "PSMTestSharedTypes.generated.h"

USTRUCT()
struct FPSMTestSectionData
{
	GENERATED_BODY()
	
	FPSMTestSectionData();
	
	UPROPERTY(EditAnywhere)
	bool bCreateCollision;
	
	UPROPERTY(EditAnywhere)
	TArray<FVector> Vertices;
	
	UPROPERTY(EditAnywhere)
	TArray<int32> Triangles;
	
	UPROPERTY(EditAnywhere)
	TArray<FVector> Normals;
	
	UPROPERTY(EditAnywhere)
	TArray<FVector2D> UVs;

	UPROPERTY(EditAnywhere)
	TArray<FLinearColor> VertexColors;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UMaterialInterface> Material;	
};


namespace PSM::Rendering
{
	
}