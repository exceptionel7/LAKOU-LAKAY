// Copyright LAKOU LAKAY.
#include "DialogueManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

FString UDialogueManager::CheminFichierPourLangue(ELangue Langue)
{
    FString Suffixe;
    switch (Langue)
    {
        case ELangue::HT: Suffixe = TEXT("ht"); break;
        case ELangue::FR: Suffixe = TEXT("fr"); break;
        case ELangue::EN: Suffixe = TEXT("en"); break;
        case ELangue::ES: Suffixe = TEXT("es"); break;
    }
    // Data/Dialogues/dialogues.<langue>.json à la racine du projet.
    return FPaths::ProjectDir() / TEXT("Data/Dialogues") / FString::Printf(TEXT("dialogues.%s.json"), *Suffixe);
}

bool UDialogueManager::ChargerLangue(ELangue Langue)
{
    const FString Chemin = CheminFichierPourLangue(Langue);

    FString Contenu;
    if (!FFileHelper::LoadFileToString(Contenu, *Chemin))
    {
        UE_LOG(LogTemp, Warning, TEXT("[Dialogue] Fichier introuvable: %s"), *Chemin);
        return false;
    }

    TSharedPtr<FJsonObject> Racine;
    const TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Contenu);
    if (!FJsonSerializer::Deserialize(Reader, Racine) || !Racine.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("[Dialogue] JSON invalide: %s"), *Chemin);
        return false;
    }

    Lignes.Empty();
    // Structure attendue : { "lignes": [ { "cle","locuteur","texte","cleAudio" }, ... ] }
    const TArray<TSharedPtr<FJsonValue>>* Tableau = nullptr;
    if (Racine->TryGetArrayField(TEXT("lignes"), Tableau))
    {
        for (const TSharedPtr<FJsonValue>& Val : *Tableau)
        {
            const TSharedPtr<FJsonObject> Obj = Val->AsObject();
            if (!Obj.IsValid()) continue;

            FLigneDialogue L;
            L.Cle      = Obj->GetStringField(TEXT("cle"));
            L.Locuteur = Obj->GetStringField(TEXT("locuteur"));
            L.Texte    = Obj->GetStringField(TEXT("texte"));
            Obj->TryGetStringField(TEXT("cleAudio"), L.CleAudio);
            Lignes.Add(L.Cle, L);
        }
    }

    LangueActive = Langue;
    UE_LOG(LogTemp, Log, TEXT("[Dialogue] %d lignes chargées (%s)"), Lignes.Num(), *Chemin);
    return true;
}

bool UDialogueManager::ObtenirLigne(const FString& Cle, FLigneDialogue& OutLigne) const
{
    if (const FLigneDialogue* Found = Lignes.Find(Cle))
    {
        OutLigne = *Found;
        return true;
    }
    return false;
}
