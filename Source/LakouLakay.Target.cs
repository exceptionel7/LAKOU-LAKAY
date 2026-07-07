// Copyright LAKOU LAKAY. Cible de build du jeu (packaged / standalone).
using UnrealBuildTool;
using System.Collections.Generic;

public class LakouLakayTarget : TargetRules
{
    public LakouLakayTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("LakouLakay");
    }
}
