# SETUP — Mettre en route LAKOU LAKAY dans Unreal Engine 5

> Guide pas-à-pas pour ouvrir le projet, compiler le code C++ fourni et lancer un test coop 2 joueurs.
> Pensé pour un·e débutant·e. Prends ton temps, étape par étape.

---

## 1. Prérequis (à installer une fois)

1. **Epic Games Launcher** → installe **Unreal Engine 5.4** (la version indiquée dans `LakouLakay.uproject`, champ `EngineAssociation`).
   - Si tu utilises une autre version d'UE5, ouvre `LakouLakay.uproject` et change `"EngineAssociation": "5.4"` par ta version (ex. `"5.5"`).
2. **Visual Studio 2022** (Windows) avec la charge de travail **« Développement de jeux avec C++ »**.
   - (Mac : installe **Xcode**.)
3. **Git** + **Git LFS** : après installation, lance une fois `git lfs install`.

---

## 2. Récupérer le projet

```bash
git clone https://github.com/exceptionel7/LAKOU-LAKAY.git
cd LAKOU-LAKAY
git lfs install
```

Structure attendue à la racine :
```
LakouLakay.uproject
Config/            (DefaultEngine.ini, DefaultGame.ini, DefaultInput.ini)
Source/            (code C++ + fichiers .Target.cs)
Data/Dialogues/    (dialogues créole + FR/EN/ES)
docs/              (GDD, plan, etc.)
```

---

## 3. Générer les fichiers de projet et compiler

1. **Clic droit** sur `LakouLakay.uproject` → **« Generate Visual Studio project files »**.
   - (Si l'option n'apparaît pas : ouvre d'abord l'uproject, UE proposera de reconstruire les modules — accepte.)
2. Ouvre le `.sln` généré dans Visual Studio, choisis la configuration **Development Editor** + **Win64**, puis **Build**.
3. Double-clique sur `LakouLakay.uproject` pour ouvrir l'éditeur Unreal.
   - Au premier lancement, si UE demande à recompiler les modules → **Oui**.

> ⚠️ **Piège classique :** ne PAS ouvrir l'uproject en double-cliquant AVANT d'avoir Visual Studio + la charge C++ installés, sinon la compilation échoue. Installe les prérequis d'abord.

---

## 4. Activer les plugins (déjà déclarés, à vérifier)

Le fichier `.uproject` active déjà : **Enhanced Input**, **OnlineSubsystemUtils**, **OnlineSubsystemEOS**.
Dans l'éditeur : `Edit > Plugins` → vérifie qu'ils sont cochés. Redémarre si demandé.

---

## 5. Créer les assets d'entrée (Enhanced Input)

Le script `ALakouCharacter` attend un Mapping Context et des Input Actions. Crée-les dans l'éditeur :

1. Content Browser → dossier `Content/Input/`.
2. Clic droit → **Input > Input Action**, crée :
   - `IA_Move` (Value Type : **Axis2D / Vector2D**)
   - `IA_Look` (Value Type : **Axis2D / Vector2D**)
   - `IA_Jump` (Value Type : **Digital / bool**)
   - `IA_Sprint` (Digital)
   - `IA_Crouch` (Digital)
3. Clic droit → **Input > Input Mapping Context**, crée `IMC_Default`.
   - Ajoute chaque Input Action et assigne les touches (ex. `IA_Move` → W/A/S/D avec modificateurs, `IA_Look` → Mouse XY, `IA_Jump` → Espace…).

---

## 6. Créer le Blueprint du personnage

1. Content Browser → clic droit → **Blueprint Class** → cherche `LakouCharacter` comme parent → nomme-le `BP_Danel`.
2. Ouvre `BP_Danel`, panneau **Details** → catégorie **Input** :
   - `Default Mapping Context` = `IMC_Default`
   - `Move Action` = `IA_Move`, `Look Action` = `IA_Look`, etc.
3. Assigne un **Skeletal Mesh** (ex. le mannequin UE5 pour tester, ou un MetaHuman plus tard) et un **Anim Blueprint**.
4. (Optionnel) Duplique en `BP_Franko` pour le second personnage.

---

## 7. Configurer le GameMode et une map de test

1. Crée un niveau : `Content/Maps/L_Lakou_Hub` (File > New Level > Basic).
2. Crée un Blueprint dérivé de `LakouGameMode` → `BP_LakouGameMode`.
   - Dans ses Details : **Default Pawn Class** = `BP_Danel`.
   - (GameState et PlayerController sont déjà réglés en C++.)
3. World Settings du niveau → **GameMode Override** = `BP_LakouGameMode`.
4. Ajoute un **Player Start** dans le niveau.

> Les maps par défaut sont déjà pointées dans `Config/DefaultEngine.ini` (`L_MainMenu`, `L_Lakou_Hub`). Crée-les avec ces noms exacts, ou ajuste le .ini.

---

## 8. Tester en coopératif 2 joueurs (en local d'abord)

1. Barre d'outils → flèche à côté de **Play** → **Number of Players = 2**.
2. **Net Mode = Play As Listen Server**.
3. Clique **Play** : deux fenêtres/vues apparaissent, chacune contrôle son personnage.
4. Vérifie que la progression partagée fonctionne (le compteur d'otages du `LakouGameState` est répliqué).

> C'est la façon la plus rapide de tester le réseau **sans configurer EOS**. La vraie coop en ligne (amis via internet) viendra avec EOS/Steam (étape 10).

---

## 9. Brancher les dialogues multilingues

- Le `UDialogueManager` (GameInstanceSubsystem) charge `Data/Dialogues/dialogues.<langue>.json`.
- Depuis un Blueprint : appelle **Charger Langue** (ex. `FR`) puis **Obtenir Ligne** avec une clé (ex. `grann.byenveni.01`) pour récupérer texte + locuteur.
- Crée un Widget UI (`WBP_Dialogue`) pour afficher `Locuteur` + `Texte` en sous-titres.

---

## 10. (Plus tard) Coop en ligne réelle via EOS

1. Crée un produit sur le **Epic Games Dev Portal** (dev.epicgames.com/portal) → récupère `ProductId`, `SandboxId`, `DeploymentId`, `ClientId`, `ClientSecret`.
2. Renseigne-les dans `Config/DefaultEngine.ini` (section `[/Script/OnlineSubsystemEOS.EOSSettings]`, déjà préparée en commentaire).
3. Utilise le `ULakouSessionSubsystem` : `HebergerPartie()` (hôte) et `RejoindreParRecherche()` (invité).
   - À terme : remplacer la recherche automatique par une **invitation d'ami** ou un **code de session**.

---

## Pièges fréquents (débutant)
- **Nom de fichier ≠ nom de classe** → erreur de compilation. Respecte la correspondance (ex. `LakouCharacter.h` ↔ `ALakouCharacter`).
- **Modifier l'état du jeu côté client** → ne marche pas en réseau. Passe par un **Server RPC** (voir `LakouPlayerController`).
- **Oublier `git lfs install`** → les futurs assets binaires seront corrompus.
- **Mauvaise version d'UE** → ajuste `EngineAssociation` dans le `.uproject`.
- **Vouloir le rendu réaliste tout de suite** → teste d'abord en « greybox » (voir `docs/plan-developpement.md`).

---

Pour la vision complète, le gameplay et le plan : voir le dossier [`docs/`](docs/).
