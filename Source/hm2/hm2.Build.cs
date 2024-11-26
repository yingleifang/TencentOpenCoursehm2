// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class hm2 : ModuleRules
{
	public hm2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
