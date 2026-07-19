// Copyright LAKOU LAKAY.
// Exemple de RPC serveur : quand un joueur libère un otage, la requête part du client
// vers le serveur qui valide et met à jour l'état partagé (GameState).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LakouPlayerController.generated.h"

UCLASS()
class LAKOULAKAY_API ALakouPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    // Appelé depuis le client quand le joueur déclenche "libérer l'otage".
    UFUNCTION(BlueprintCallable, Category = "Gameplay")
    void DemanderLibererOtage(class AActor* Otage);

protected:
    // RPC exécuté SUR LE SERVEUR. WithValidation = anti-triche basique.
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_LibererOtage(class AActor* Otage);
};
