// Copyright LAKOU LAKAY.
// Gestion des sessions coop 2 joueurs (héberger / rejoindre).
// S'appuie sur l'Online Subsystem d'Unreal. Pour du cross-platform gratuit,
// configurer EOS (Epic Online Services) ; pour PC/Steam, OnlineSubsystemSteam.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "LakouSessionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateSessionComplete, bool, bSucces);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJoinSessionComplete, bool, bSucces);

UCLASS()
class LAKOULAKAY_API ULakouSessionSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    ULakouSessionSubsystem();

    // Héberger une partie coop (2 places : l'hôte + 1 ami).
    UFUNCTION(BlueprintCallable, Category = "Online")
    void HebergerPartie();

    // Rejoindre la première session trouvée (à remplacer par invitation/code d'ami).
    UFUNCTION(BlueprintCallable, Category = "Online")
    void RejoindreParRecherche();

    UPROPERTY(BlueprintAssignable) FOnCreateSessionComplete OnCreateSessionComplete;
    UPROPERTY(BlueprintAssignable) FOnJoinSessionComplete OnJoinSessionComplete;

protected:
    IOnlineSessionPtr SessionInterface;
    TSharedPtr<class FOnlineSessionSettings> SessionSettings;
    TSharedPtr<class FOnlineSessionSearch> SessionSearch;

    void HandleCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void HandleFindSessionsComplete(bool bWasSuccessful);
    void HandleJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

    FDelegateHandle CreateHandle, FindHandle, JoinHandle;

    static const FName SessionName; // "LakouCoop"
    static const int32 MaxJoueurs = 2;
};
