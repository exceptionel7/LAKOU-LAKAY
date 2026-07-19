# Architecture de projet — LAKOU LAKAY (Unreal Engine 5)

> Arborescence recommandée pour un projet UE5 en C++ avec Blueprints, coop 2 joueurs et localisation multilingue.

## 1. Vue d'ensemble

```
LakouLakay/
├── LakouLakay.uproject          # Fichier projet Unreal
├── Config/                      # Fichiers .ini (Engine, Game, Input, DefaultEngine…)
│   ├── DefaultEngine.ini
│   ├── DefaultGame.ini
│   ├── DefaultInput.ini
│   └── DefaultEditor.ini
├── Source/                      # Code C++
│   └── LakouLakay/
│       ├── LakouLakay.Build.cs
│       ├── LakouLakay.h / .cpp
│       ├── Core/                # GameMode, GameState, PlayerController, GameInstance
│       ├── Characters/          # Personnages jouables (Danel, Franko), classe de base
│       ├── AI/                  # IA gardes (états, perception)
│       ├── Gameplay/            # Otages, objectifs, système de mission, réputation
│       ├── Dialogue/            # Gestionnaire de dialogue multilingue
│       └── Online/              # Sessions, matchmaking (EOS/Steam)
├── Content/                     # Assets Unreal (.uasset) — non versionnés en texte
│   ├── Maps/                    # Niveaux
│   │   ├── L_MainMenu
│   │   ├── L_Lakou_Hub          # QG / hub
│   │   ├── L_Kafou
│   │   ├── L_BaDelma
│   │   ├── L_Laplenn
│   │   ├── L_Kwadebouke
│   │   └── L_VilajDeDye         # bastion final
│   ├── Blueprints/
│   │   ├── Characters/          # BP_Danel, BP_Franko, BP_Otage
│   │   ├── AI/                  # BP_Garde, BT_Garde (Behavior Tree), BB_Garde (Blackboard)
│   │   ├── Gameplay/            # BP_ObjectifMission, BP_PointExtraction…
│   │   ├── UI/                  # Widgets HUD, menus, sous-titres
│   │   └── Core/                # BP dérivés de GameMode/Controller si besoin
│   ├── Characters/              # Meshes, squelettes, animations, matériaux perso
│   ├── Environments/            # Décors (Kafou, marché, maisons, tap-taps…)
│   │   ├── Megascans/           # Assets Quixel importés
│   │   ├── Buildings/
│   │   ├── Props/
│   │   └── Vegetation/
│   ├── Audio/
│   │   ├── Music/               # compas / rasin
│   │   ├── SFX/                 # sons de rue, pas, armes, ambiance
│   │   └── Voice/               # doublage créole (VO) par PNJ
│   ├── UI/                      # Textures d'interface, polices, icônes
│   └── VFX/                     # Effets (fumigène, impacts, lumières)
├── Localization/                # Fichiers de traduction (voir §3)
│   └── Game/
│       ├── ht/ (créole)         # langue source des dialogues
│       ├── fr/
│       ├── en/
│       └── es/
├── Data/                        # Données de jeu externes (JSON/CSV)
│   ├── Dialogues/               # dialogues par langue (voir scripts)
│   │   ├── dialogues.ht.json
│   │   ├── dialogues.fr.json
│   │   ├── dialogues.en.json
│   │   └── dialogues.es.json
│   ├── Missions/                # définitions de missions
│   └── Characters/              # stats PNJ / bosses
├── Docs/                        # Ce dossier de documentation
└── .gitignore / .gitattributes  # Git + Git LFS pour les gros assets binaires
```

## 2. Conventions de nommage (recommandées Unreal)

| Type | Préfixe | Exemple |
|---|---|---|
| Blueprint | `BP_` | `BP_Danel` |
| Niveau (map) | `L_` | `L_Kafou` |
| Behavior Tree | `BT_` | `BT_Garde` |
| Blackboard | `BB_` | `BB_Garde` |
| Widget UI | `WBP_` | `WBP_HUD` |
| Material | `M_` | `M_MurBeton` |
| Material Instance | `MI_` | `MI_MurBeton_Bleu` |
| Texture | `T_` | `T_MurBeton_D` (D=Diffuse/BaseColor) |
| Static Mesh | `SM_` | `SM_TapTap` |
| Skeletal Mesh | `SK_` | `SK_Danel` |
| Sound Cue / Wave | `SC_` / `SW_` | `SC_MarcheAmbiance` |
| Classe C++ | (par module) | `ALakouCharacter`, `UDialogueManager` |

## 3. Localisation (multilingue)

Deux approches, complémentaires :

- **Interface (menus, HUD)** → **String Tables** natives d'Unreal + **Localization Dashboard** (export/import `.po`). C'est la méthode "propre" recommandée à terme.
- **Dialogues de PNJ (volumineux, évolutifs)** → fichiers **JSON par langue** dans `Data/Dialogues/` chargés par le `DialogueManager` (voir les scripts de base). Plus simple à confier à des traducteur·rice·s et à faire évoluer sans rebuild.
- **Langue source = créole (ht)**. Les autres langues sont des traductions. Le doublage audio (VO créole) est référencé par une clé partagée avec le texte.

## 4. Contrôle de version

- **Git + Git LFS obligatoire** pour les binaires (`*.uasset`, `*.umap`, audio, textures).
- Ne PAS versionner : `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`.
- `.gitattributes` : router les extensions binaires vers LFS.

Exemple `.gitignore` minimal :
```
Binaries/
DerivedDataCache/
Intermediate/
Saved/
*.sln
*.suo
*.xcodeproj
*.xcworkspace
```
