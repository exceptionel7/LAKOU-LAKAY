// Copyright LAKOU LAKAY.
// GameMode par défaut : relie le pion joueur, le GameState (progression partagée)
// et le PlayerController (RPC). Utilisé par les maps de jeu (hub + quartiers).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LakouGameMode.generated.h"

UCLASS()
class LAKOULAKAY_API ALakouGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ALakouGameMode();
};
