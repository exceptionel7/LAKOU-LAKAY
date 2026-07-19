// Copyright LAKOU LAKAY.
#include "LakouGameState.h"
#include "Net/UnrealNetwork.h"

ALakouGameState::ALakouGameState()
{
    // Le GameState est répliqué par défaut.
}

void ALakouGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ALakouGameState, QuartierReputation);
    DOREPLIFETIME(ALakouGameState, OtagesSauves);
}

void ALakouGameState::AjouterReputation(int32 Delta)
{
    // Sécurité : ne s'exécute que sur l'autorité (serveur/hôte).
    if (!HasAuthority()) return;

    QuartierReputation = FMath::Clamp(QuartierReputation + Delta, 0, 100);
    // Sur le serveur, OnRep_ n'est pas appelé automatiquement -> on notifie manuellement.
    OnReputationChanged.Broadcast(QuartierReputation);
}

void ALakouGameState::EnregistrerOtageSauve()
{
    if (!HasAuthority()) return;
    OtagesSauves++;
    AjouterReputation(10); // sauver un otage augmente la réputation du quartier
}

void ALakouGameState::OnRep_Reputation()
{
    // Appelé sur les CLIENTS quand la valeur répliquée change.
    OnReputationChanged.Broadcast(QuartierReputation);
}

void ALakouGameState::OnRep_OtagesSauves()
{
    // Hook pour l'UI côté client (compteur d'otages sauvés).
}
