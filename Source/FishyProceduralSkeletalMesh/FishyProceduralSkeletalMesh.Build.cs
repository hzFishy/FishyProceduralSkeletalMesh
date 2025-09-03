// By hzFishy - 2025 - Do whatever you want with it.

using UnrealBuildTool;

public class FishyProceduralSkeletalMesh : ModuleRules
{
	public FishyProceduralSkeletalMesh(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"ProceduralMeshComponent",
				"FishyUtils"
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject", "Engine",
				"Slate", "SlateCore",			
			}
		);
		
	}
}
