// Copyright LAKOU LAKAY.
// Gestionnaire de dialogue multilingue.
// Charge un fichier JSON par langue (créole = source ; fr / en / es = sous-titres).
// Les lignes de dialogue sont identifiées par une CLÉ commune à toutes les langues,
// qui sert aussi à référencer le doublage audio (VO créole).
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueManager.generated.h"

// Langues supportées.
UENUM(BlueprintType)
enum class ELangue : uint8
{
    HT UMETA(DisplayName = "Kreyòl (source)"),
    FR UMETA(DisplayName = "Français"),
    EN UMETA(DisplayName = "English"),
    ES UMETA(DisplayName = "Español")
};

// Une réplique : texte affiché (langue courante) + clé audio (VO créole).
USTRUCT(BlueprintType)
struct FLigneDialogue
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly) FString Cle;         // ex: "grann.bienvenue.01"
    UPROPERTY(BlueprintReadOnly) FString Locuteur;    // ex: "Grann Ilména"
    UPROPERTY(BlueprintReadOnly) FString Texte;       // texte dans la langue active
    UPROPERTY(BlueprintReadOnly) FString CleAudio;    // ex: "VO_grann_bienvenue_01"
};

UCLASS()
class LAKOULAKAY_API UDialogueManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    // Change la langue active et (re)charge le fichier correspondant.
    UFUNCTION(BlueprintCallable, Category = "Dialogue")
    bool ChargerLangue(ELangue Langue);

    // Récupère une réplique par sa clé, dans la langue active.
    UFUNCTION(BlueprintCallable, Category = "Dialogue")
    bool ObtenirLigne(const FString& Cle, FLigneDialogue& OutLigne) const;

    UFUNCTION(BlueprintPure, Category = "Dialogue")
    ELangue GetLangueActive() const { return LangueActive; }

protected:
    ELangue LangueActive = ELangue::FR;

    // Table en mémoire : Cle -> réplique.
    TMap<FString, FLigneDialogue> Lignes;

    static FString CheminFichierPourLangue(ELangue Langue);
};
