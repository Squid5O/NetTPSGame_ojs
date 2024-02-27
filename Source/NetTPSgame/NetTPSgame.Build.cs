// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetTPSgame : ModuleRules
{
	public NetTPSgame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
