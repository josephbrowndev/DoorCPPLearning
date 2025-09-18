// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ali_CPP_Tut : ModuleRules
{
	public Ali_CPP_Tut(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Ali_CPP_Tut",
			"Ali_CPP_Tut/Variant_Platforming",
			"Ali_CPP_Tut/Variant_Platforming/Animation",
			"Ali_CPP_Tut/Variant_Combat",
			"Ali_CPP_Tut/Variant_Combat/AI",
			"Ali_CPP_Tut/Variant_Combat/Animation",
			"Ali_CPP_Tut/Variant_Combat/Gameplay",
			"Ali_CPP_Tut/Variant_Combat/Interfaces",
			"Ali_CPP_Tut/Variant_Combat/UI",
			"Ali_CPP_Tut/Variant_SideScrolling",
			"Ali_CPP_Tut/Variant_SideScrolling/AI",
			"Ali_CPP_Tut/Variant_SideScrolling/Gameplay",
			"Ali_CPP_Tut/Variant_SideScrolling/Interfaces",
			"Ali_CPP_Tut/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
