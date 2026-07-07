# Plan de développement — LAKOU LAKAY

> Plan par étapes (prototype → alpha → bêta → sortie), pensé pour un·e débutant·e sur Unreal Engine 5.
> ⚠️ Réalisme : un jeu 3D coop réaliste est un **gros** projet. L'objectif de ce plan est d'avancer par petits jalons **jouables**, en commençant TRÈS petit. Ne pas viser tout le contenu d'un coup.

---

## Phase 0 — Préparation (1 à 2 semaines)
- Installer Unreal Engine 5, Visual Studio (Windows) ou Rider, Git + Git LFS.
- Suivre le **parcours d'apprentissage** (voir `parcours-apprentissage-unreal.md`) jusqu'à savoir naviguer dans l'éditeur et faire bouger un personnage.
- Mettre en place le dépôt Git (LFS) et l'arborescence (`architecture-projet.md`).
- **Jalon :** un projet vide versionné + un perso qui marche dans un niveau test.

---

## Phase 1 — PROTOTYPE (env. 1 à 3 mois)
Objectif : **prouver le "fun" de la boucle coop**, sans réalisme ni contenu final.

### 1a. Prototype solo (gris)
- Un personnage jouable (capsule + mesh basique) qui marche, court, s'accroupit.
- Un petit niveau "boîte grise" (greybox) : une rue, un bâtiment, quelques couvertures.
- 1 garde IA simple (patrouille + détection basique).
- 1 otage à libérer + 1 point d'extraction.
- **Jalon :** je peux infiltrer, libérer l'otage, l'amener à l'extraction (en solo).

### 1b. Passage en coop 2 joueurs
- Intégrer la **replication** (voir scripts `Core/`), sessions (`Online/`).
- Tester en "listen server" : hôte + 1 ami, chacun contrôle son perso.
- Progression partagée minimale (compteur d'otages répliqué).
- **Jalon :** deux joueurs en ligne réussissent une infiltration ensemble.

> À la fin de la Phase 1, on doit répondre OUI à : "est-ce que jouer cette boucle à deux est amusant, même moche ?"

---

## Phase 2 — VERTICAL SLICE (env. 2 à 4 mois)
Objectif : **une** mission complète, belle et représentative du jeu final.
- Choisir **un seul quartier** (ex. Kafou) et le construire proprement (Megascans + assets haïtiens clés : tap-tap, maisons, marché).
- Éclairage Lumen, cycle jour/nuit basique.
- IA de garde plus complète (états suspicion/recherche/alerte, ouïe/vue).
- Système d'otages complet (ligoté/libéré/blessé/en sécurité).
- 1 boss fictif (Grif Fè) avec confrontation coordonnée.
- Dialogues créole + sous-titres FR/EN/ES branchés (voir `DialogueManager`).
- Audio : ambiance + musique placeholder.
- **Jalon :** une mission "montrable" du début à la fin, à deux, avec le bon ton.

---

## Phase 3 — ALPHA (env. 4 à 8 mois)
Objectif : **tout le jeu jouable de bout en bout**, contenu non finalisé.
- Construire les autres quartiers (Ba Delma, Laplenn, Kwadebouke, Vilaj de Dye).
- Tous les bosses + boss final.
- Hub (Lakou) fonctionnel : briefing, améliorations d'équipement, PNJ.
- Progression complète (réputation, confiance, déblocages).
- Toutes les mécaniques présentes (gadgets, soin, brouilleur…).
- **Jalon "feature complete" :** on peut finir la campagne en coop, même avec des assets/placeholder à polir.

---

## Phase 4 — BÊTA (env. 3 à 6 mois)
Objectif : **stabiliser et finaliser**.
- Remplacer les placeholders par les assets finaux (musique compas/rasin originale, VO créole).
- Équilibrage difficulté, IA, économie de progression.
- Optimisation perf (Nanite/Lumen réglés, LODs, budget mémoire).
- Correction de bugs, tests réseau intensifs (latence, reconnexion, hôte qui quitte).
- **Sensitivity reading** final avec des personnes haïtiennes ; ajustements culturels/langue.
- Accessibilité (options, sous-titres, marquage assisté).
- **Jalon :** version complète, stable, testée par des joueurs externes (playtests).

---

## Phase 5 — SORTIE & POST-LANCEMENT
- Build de distribution, page de store, tests de conformité.
- Patchs post-lancement, retours communautaires.
- (Optionnel) contenu additionnel : nouveaux quartiers, missions.

---

## Conseils de pilotage
- **Toujours garder une build jouable.** Chaque semaine, quelque chose doit tourner.
- **Scope réaliste :** si le temps manque, réduis le NOMBRE de quartiers avant de sacrifier la qualité d'un seul.
- **Coop tôt :** intègre le réseau dès la Phase 1 — le rajouter tard est douloureux.
- **Verticale avant horizontale :** une mission parfaite avant cinq missions moyennes.
- **Sauvegardes / versions :** commits fréquents, branches par fonctionnalité.

## Ordre de priorité si tu es seul·e / petite équipe
1. Boucle coop fun (Phase 1) — non négociable.
2. Un quartier magnifique (Phase 2) — c'est ta démo.
3. Le reste du contenu (Phase 3+) — seulement une fois 1 et 2 solides.
