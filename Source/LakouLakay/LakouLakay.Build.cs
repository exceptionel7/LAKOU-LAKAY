// Copyright LAKOU LAKAY. Fichier de configuration de build du module principal.
using UnrealBuildTool;

public class LakouLakay : ModuleRules
{
    public LakouLakay(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;PublicIncludePaths.Add(ModuleDirectory);


        // Modules publics dont dépend le jeu.
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",          // Système d'entrées moderne d'UE5
            "AIModule",               // IA des gardes (Behavior Tree, perception)
            "GameplayTasks",
            "Json",                   // Lecture des dialogues JSON multilingues
            "JsonUtilities"
        });

        // Modules privés (réseau / sessions en ligne).
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "OnlineSubsystem",
            "OnlineSubsystemUtils"
            // Ajouter "OnlineSubsystemEOS" ou "OnlineSubsystemSteam" selon la plateforme de coop.
        });
    }
}
