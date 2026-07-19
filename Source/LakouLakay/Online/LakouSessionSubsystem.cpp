// Copyright LAKOU LAKAY.
#include "LakouSessionSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

const FName ULakouSessionSubsystem::SessionName = FName("LakouCoop");

ULakouSessionSubsystem::ULakouSessionSubsystem()
{
    if (IOnlineSubsystem* OSS = IOnlineSubsystem::Get())
    {
        SessionInterface = OSS->GetSessionInterface();
    }
}

void ULakouSessionSubsystem::HebergerPartie()
{
    if (!SessionInterface.IsValid()) return;

    SessionSettings = MakeShareable(new FOnlineSessionSettings());
    SessionSettings->bIsLANMatch = false;               // partie en ligne
    SessionSettings->NumPublicConnections = MaxJoueurs;  // 2 joueurs
    SessionSettings->bShouldAdvertise = true;            // visible pour matchmaking/invitation
    SessionSettings->bAllowJoinInProgress = true;
    SessionSettings->bUsesPresence = true;               // rejoindre via amis
    SessionSettings->bAllowJoinViaPresence = true;
    SessionSettings->Set(FName("GAMEMODE"), FString("Coop"), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

    CreateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(
        FOnCreateSessionCompleteDelegate::CreateUObject(this, &ULakouSessionSubsystem::HandleCreateSessionComplete));

    const ULocalPlayer* LP = GetGameInstance()->GetFirstGamePlayer();
    SessionInterface->CreateSession(*LP->GetPreferredUniqueNetId(), SessionName, *SessionSettings);
}

void ULakouSessionSubsystem::HandleCreateSessionComplete(FName Name, bool bWasSuccessful)
{
    SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateHandle);
    OnCreateSessionComplete.Broadcast(bWasSuccessful);

    if (bWasSuccessful)
    {
        // Ouvre la map hub en tant que "listen server" (l'hôte joue aussi).
        GetWorld()->ServerTravel(FString("/Game/Maps/L_Lakou_Hub?listen"));
    }
}

void ULakouSessionSubsystem::RejoindreParRecherche()
{
    if (!SessionInterface.IsValid()) return;

    SessionSearch = MakeShareable(new FOnlineSessionSearch());
    SessionSearch->bIsLanQuery = false;
    SessionSearch->MaxSearchResults = 10;
    //SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

    FindHandle = SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(
        FOnFindSessionsCompleteDelegate::CreateUObject(this, &ULakouSessionSubsystem::HandleFindSessionsComplete));

    const ULocalPlayer* LP = GetGameInstance()->GetFirstGamePlayer();
    SessionInterface->FindSessions(*LP->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
}

void ULakouSessionSubsystem::HandleFindSessionsComplete(bool bWasSuccessful)
{
    SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(FindHandle);

    if (bWasSuccessful && SessionSearch->SearchResults.Num() > 0)
    {
        JoinHandle = SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(
            FOnJoinSessionCompleteDelegate::CreateUObject(this, &ULakouSessionSubsystem::HandleJoinSessionComplete));

        const ULocalPlayer* LP = GetGameInstance()->GetFirstGamePlayer();
        SessionInterface->JoinSession(*LP->GetPreferredUniqueNetId(), SessionName, SessionSearch->SearchResults[0]);
    }
    else
    {
        OnJoinSessionComplete.Broadcast(false);
    }
}

void ULakouSessionSubsystem::HandleJoinSessionComplete(FName Name, EOnJoinSessionCompleteResult::Type Result)
{
    SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(JoinHandle);

    const bool bOk = (Result == EOnJoinSessionCompleteResult::Success);
    OnJoinSessionComplete.Broadcast(bOk);

    if (bOk)
    {
        // Récupère l'adresse de connexion et voyage vers l'hôte.
        FString ConnectString;
        if (SessionInterface->GetResolvedConnectString(SessionName, ConnectString))
        {
            if (APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController())
            {
                PC->ClientTravel(ConnectString, ETravelType::TRAVEL_Absolute);
            }
        }
    }
}
