// Copyright LAKOU LAKAY. Cible de build pour l'éditeur.
using UnrealBuildTool;
using System.Collections.Generic;

public class LakouLakayEditorTarget : TargetRules
{
    public LakouLakayEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("LakouLakay");
    }
}
