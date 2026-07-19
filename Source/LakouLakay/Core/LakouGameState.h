// Copyright LAKOU LAKAY.
// GameState répliqué : progression PARTAGÉE entre les 2 joueurs (réputation de quartier,
// otages sauvés). Le serveur (hôte) fait autorité, les valeurs sont répliquées aux clients.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LakouGameState.generated.h"

// Délégué pour prévenir l'UI (HUD) quand la réputation change (sur serveur ET client).
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReputationChanged, int32, NewReputation);

UCLASS()
class LAKOULAKAY_API ALakouGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    ALakouGameState();

    // Réputation du quartier courant (0-100), répliquée à tous les clients.
    UPROPERTY(ReplicatedUsing = OnRep_Reputation, BlueprintReadOnly, Category = "Progression")
    int32 QuartierReputation = 0;

    UPROPERTY(ReplicatedUsing = OnRep_OtagesSauves, BlueprintReadOnly, Category = "Progression")
    int32 OtagesSauves = 0;

    UPROPERTY(BlueprintAssignable, Category = "Progression")
    FOnReputationChanged OnReputationChanged;

    // À appeler côté serveur uniquement (gameplay autoritaire).
    void AjouterReputation(int32 Delta);
    void EnregistrerOtageSauve();

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_Reputation();

    UFUNCTION()
    void OnRep_OtagesSauves();
};
