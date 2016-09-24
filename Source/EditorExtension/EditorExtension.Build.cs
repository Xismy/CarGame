// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class EditorExtension : ModuleRules
{
	public EditorExtension(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Juego", "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "BlueprintGraph", "AnimGraph" });

        CircularlyReferencedDependentModules.AddRange(
            new string[] {
                    "Juego",
                }
        );

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");
        // if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
        // {
        //		if (UEBuildConfiguration.bCompileSteamOSS == true)
        //		{
        //			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        //		}
        // }
    }
}
