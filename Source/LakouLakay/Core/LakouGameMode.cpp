// Copyright LAKOU LAKAY.
#include "LakouGameMode.h"
#include "LakouGameState.h"
#include "LakouPlayerController.h"
#include "Characters/LakouCharacter.h"

ALakouGameMode::ALakouGameMode()
{
    // Classes par défaut. Tu peux les remplacer par des Blueprints dérivés
    // (ex. BP_Danel) dans les réglages du GameMode côté éditeur.
    DefaultPawnClass      = ALakouCharacter::StaticClass();
    GameStateClass        = ALakouGameState::StaticClass();
    PlayerControllerClass = ALakouPlayerController::StaticClass();

    // Coop : les deux joueurs partagent la même partie (pas de spectateurs).
    bStartPlayersAsSpectators = false;
}
