// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Juego : ModuleRules
{
	public Juego(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "EditorExtension", "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });


       /* CircularlyReferencedDependentModules.AddRange(
            new string[] {
                    "EditorExtension",
                }
        );*/

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
