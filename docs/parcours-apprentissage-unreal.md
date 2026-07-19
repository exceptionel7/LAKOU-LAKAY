# Parcours d'apprentissage — Débuter sur Unreal Engine 5

> Pour toi qui débutes. Objectif : monter en compétence **étape par étape**, avec des ressources gratuites, avant de te lancer dans le projet complet LAKOU LAKAY.
> Les durées sont estimées pour un·e **débutant·e motivé·e** (quelques heures par semaine). Adapte à ton rythme.

---

## Étape 1 — Les bases (2 à 3 semaines)
**But :** installer, se repérer, comprendre Blueprints vs C++, faire un petit niveau.

- Installer **Epic Games Launcher** → **Unreal Engine 5** (dernière version stable).
- Sur Windows : installer **Visual Studio** (avec la charge "Développement de jeux avec C++") pour compiler du C++ plus tard.
- Apprendre : navigation dans l'éditeur (viewport, Outliner, Details, Content Browser), placer des objets, créer un niveau simple.
- **Blueprints vs C++** :
  - *Blueprints* = programmation visuelle par nœuds. **Commence par là**, c'est idéal pour débuter et prototyper vite.
  - *C++* = plus puissant/performant, utile pour les systèmes lourds (réseau, gros gameplay). Tu y viendras plus tard (les scripts fournis dans `Source/` sont en C++, tu pourras les adopter progressivement).

**Ressources gratuites :**
- Documentation officielle Epic ("Unreal Engine Documentation").
- **Unreal Learning** (cours gratuits d'Epic, sur le site Epic Developer Community / anciennement Unreal Online Learning).
- Chaînes YouTube reconnues : chaîne officielle **Unreal Engine**, tutoriels "UE5 beginner" (ex. formats "learn UE5 in X hours").

**Piège débutant :** vouloir tout coder en C++ dès le début. Reste sur Blueprints tant que tu apprends.

---

## Étape 2 — Premier prototype jouable solo (2 à 4 semaines)
**But :** un personnage qui marche dans un petit décor, caméra, contrôles clavier/manette.

- Partir du **template "Third Person"** d'UE5 (fournit déjà un perso qui marche + caméra) → étudie comment il est fait.
- Apprendre le **système Enhanced Input** (Input Mapping Context + Input Actions) — c'est ce qu'utilise le script `LakouCharacter`.
- Construire une petite rue/maison en "boîtes grises" (greybox) avec des BSP/meshes simples.
- Ajouter accroupissement, course.

**Ressources :** template Third Person + tuto "UE5 Enhanced Input" ; doc officielle Enhanced Input.

**Piège débutant :** soigner les graphismes avant que le gameplay marche. **Greybox d'abord.**

---

## Étape 3 — Ajouter le réalisme (3 à 5 semaines)
**But :** un décor crédible avec de la lumière réaliste.

- Découvrir **Quixel Megascans** (gratuit avec UE5) et **Bridge/Fab** pour importer des assets photoréalistes.
- Comprendre **Lumen** (éclairage global dynamique) et **Nanite** (géométrie ultra-détaillée) — souvent activés par défaut en UE5.
- Apprendre : matériaux, Material Instances, cycle jour/nuit (Directional Light + Sky), post-process de base.
- Commencer à modéliser/importer tes éléments haïtiens signature (tap-tap, maisons) — ou blockout en attendant.

**Ressources :** doc Lumen/Nanite d'Epic ; tuto "Megascans in UE5" ; tuto "lighting UE5 beginner".

**Pièges débutant :**
- Trop de lumières dynamiques / effets → chute de perfs. Garde ça simple.
- Importer des assets énormes sans réfléchir à la mémoire.

---

## Étape 4 — Passer en réseau 2 joueurs (4 à 6 semaines)
**But :** transformer le prototype solo en coop en ligne.

- Comprendre le modèle réseau d'Unreal : **serveur autoritaire**, **replication**, **RPC** (Server/Client/Multicast), **listen server** vs dedicated.
- Tester en local : lancer "Play" avec **Number of Players = 2** + **Net Mode = Play As Listen Server** dans l'éditeur → tu joues à deux instantanément.
- Répliquer une variable (ex. le compteur d'otages du `LakouGameState`), déclencher un **Server RPC** (ex. libérer un otage — voir `LakouPlayerController`).
- Mettre en place les **sessions** (héberger/rejoindre) : Online Subsystem. Pour de la coop entre amis gratuite/cross-platform → **EOS (Epic Online Services)** ; pour PC/Steam → **OnlineSubsystemSteam**.

**Ressources :** doc officielle "Networking and Multiplayer" d'Epic ; série de tutoriels "UE5 multiplayer" ; doc EOS.

**Pièges débutant (le réseau est le plus dur) :**
- Oublier que le **serveur fait autorité** → ne jamais modifier l'état du jeu directement sur le client. Passe par un Server RPC.
- Oublier `GetLifetimeReplicatedProps` / `Replicated` sur les variables à synchroniser.
- Confondre "cosmétique" (peut rester local) et "gameplay" (doit être répliqué).
- Tester le réseau trop tard : intègre-le dès le prototype.

---

## Étape 5 — Intégrer le contenu du jeu (en continu)
**But :** brancher dialogues créole, mission, PNJ/IA.

- **Dialogues multilingues** : utiliser le `DialogueManager` (charge `Data/Dialogues/dialogues.<langue>.json`) + un widget UI pour l'affichage des sous-titres. Voir aussi les **String Tables** d'UE pour l'interface.
- **IA des gardes** : apprendre **Behavior Tree + Blackboard** + **AI Perception** (vue/ouïe).
- **Otages / objectifs** : PNJ avec états, point d'extraction, conditions de victoire.
- **Mission complète** : assembler le tout dans le quartier de Kafou (vertical slice, voir `plan-developpement.md`).

**Ressources :** doc "Behavior Trees" et "AI Perception" d'Epic ; tuto "UE5 stealth AI" ; doc "Localization" d'Epic.

**Piège débutant :** vouloir tout le contenu d'un coup. Fais **une** mission propre d'abord.

---

## Matériel / PC recommandé

Unreal Engine 5 avec Lumen/Nanite et rendu réaliste est **exigeant**, surtout côté développement.

### Minimum pour développer confortablement
- **CPU :** 6 cœurs récents (ex. Intel Core i5 récent / AMD Ryzen 5).
- **RAM :** **32 Go** (16 Go = pénible dès que le projet grossit ; 32 Go est le vrai confort).
- **GPU :** carte dédiée avec **8 Go de VRAM** minimum (ex. NVIDIA RTX série 3060 ou équivalent) pour Lumen/Nanite fluides.
- **Stockage :** **SSD NVMe**, prévoir **beaucoup** d'espace (UE + projet + cache = plusieurs centaines de Go). Vise 1 To.
- **OS :** Windows 10/11 64-bit (recommandé pour l'outillage UE le plus complet).

### Recommandé (réalisme sans souffrir)
- CPU 8 cœurs+ (Ryzen 7 / Core i7 récents).
- **64 Go de RAM** si scènes lourdes / beaucoup d'assets.
- GPU **12 Go+ de VRAM** (RTX 4070 ou mieux).
- SSD NVMe 1–2 To.

> Note : la config pour **faire tourner** le jeu fini (côté joueur) peut être plus légère que la config pour **développer**. On définira la config joueur minimale pendant la Phase Bêta (optimisation).

---

## Récapitulatif du chemin
1. Bases éditeur + Blueprints → 2. Perso qui marche (greybox) → 3. Réalisme (Megascans/Lumen) → 4. Coop réseau 2 joueurs → 5. Contenu (dialogues, IA, mission).

**Règle d'or débutant :** un petit truc qui marche **maintenant** vaut mieux qu'un grand truc parfait "plus tard". Avance par jalons jouables.
