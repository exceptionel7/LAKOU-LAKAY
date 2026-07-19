// Copyright LAKOU LAKAY.
#include "LakouPlayerController.h"
#include "LakouGameState.h"
#include "GameFramework/GameStateBase.h"

void ALakouPlayerController::DemanderLibererOtage(AActor* Otage)
{
    // Côté client : on envoie la requête au serveur (autoritaire).
    Server_LibererOtage(Otage);
}

bool ALakouPlayerController::Server_LibererOtage_Validate(AActor* Otage)
{
    // Validation minimale (à enrichir : distance, ligne de vue, état de l'otage…).
    return Otage != nullptr;
}

void ALakouPlayerController::Server_LibererOtage_Implementation(AActor* Otage)
{
    // Ici : vérifier que le joueur est assez proche, que l'otage est "ligoté", etc.
    // Puis mettre à jour l'état partagé.
    if (ALakouGameState* GS = GetWorld() ? GetWorld()->GetGameState<ALakouGameState>() : nullptr)
    {
        GS->EnregistrerOtageSauve();
    }
    // TODO : changer l'état de l'otage (ligoté -> libéré) et le répliquer.
}
