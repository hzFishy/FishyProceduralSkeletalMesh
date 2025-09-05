// By hzFishy - 2025 - Do whatever you want with it.


#include "Tests/PSMTestSharedTypes.h"
#include "Rendering/SkeletalMeshRenderData.h"


FPSMTestSectionData::FPSMTestSectionData():
	bCreateCollision(false)
{
	// our 3 vertices, representing the 3 points of our triangle
	Vertices.Emplace(FVector(0, 0, 0));
	Vertices.Emplace(FVector(0, 100, 0));
	Vertices.Emplace(FVector(100, 0, 0));

	// the indexes of the 3 vertices (inside Vertices) that will be used for this triangle
	Triangles.Emplace(0);
	Triangles.Emplace(1);
	Triangles.Emplace(2);

	Normals.Emplace(FVector(0, 0, 1)); 
	Normals.Emplace(FVector(0, 0, 1)); 
	Normals.Emplace(FVector(0, 0, 1)); 
	
	// UVs for this triangle
	UVs.Emplace(FVector2D(0, 0));
	UVs.Emplace(FVector2D(1, 0));
	UVs.Emplace(FVector2D(0, 1));

	// colors for each vertex
	VertexColors.Emplace(FColor::Red);
	VertexColors.Emplace(FColor::Blue);
	VertexColors.Emplace(FColor::Green);
}
