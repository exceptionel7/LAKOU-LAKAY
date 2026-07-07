# LAKOU LAKAY

Jeu vidéo **coopératif en ligne (2 joueurs)** développé sous **Unreal Engine 5**.

Deux ami·e·s, **Danel & Franko**, connecté·e·s en ligne, mènent des opérations tactiques
coordonnées pour **libérer des otages** et reprendre, quartier par quartier, le contrôle
d'une ville haïtienne **fictive** tombée sous la coupe de bandes armées.

Le jeu valorise la **résilience**, la **solidarité** et la **culture haïtienne**
(musique compas/rasin, langue créole, vie de quartier), sans glorifier la violence
ni stigmatiser le peuple haïtien.

> ⚠️ **Fiction.** Les lieux, personnages et antagonistes sont **inventés**. Aucune
> personne réelle n'est représentée. Un *sensitivity reading* avec des personnes
> haïtiennes est recommandé avant la production.

---

## 📚 Documentation

| Document | Description |
|---|---|
| [docs/GDD.md](docs/GDD.md) | Game Design Document (concept, univers, personnages, mécaniques) |
| [docs/architecture-projet.md](docs/architecture-projet.md) | Arborescence du projet Unreal Engine 5 |
| [docs/assets.md](docs/assets.md) | Liste d'assets graphiques/sonores + droits d'auteur |
| [docs/plan-developpement.md](docs/plan-developpement.md) | Plan par étapes (prototype → alpha → bêta) |
| [docs/parcours-apprentissage-unreal.md](docs/parcours-apprentissage-unreal.md) | Parcours d'apprentissage débutant UE5 + config PC |

## 🗂️ Structure du dépôt

```
LakouLakay/
├── docs/                  # Documentation de conception
├── Source/LakouLakay/     # Code C++ (personnage, réseau, dialogue, sessions)
│   ├── Characters/        # Personnage jouable (mouvement, Enhanced Input)
│   ├── Core/              # GameState répliqué, PlayerController (RPC)
│   ├── Online/            # Sessions coop 2 joueurs (héberger / rejoindre)
│   └── Dialogue/          # Gestionnaire de dialogue multilingue
├── Data/Dialogues/        # Dialogues créole (source) + FR / EN / ES
└── README.md
```

## 🌍 Langues

- **Dialogues :** créole haïtien (source), sous-titres **FR / EN / ES**.
- Système de dialogue modulaire piloté par des fichiers JSON (`Data/Dialogues/`).

## 🎮 Aperçu technique

- **Moteur :** Unreal Engine 5 (Lumen, Nanite, Quixel Megascans).
- **Réseau :** modèle serveur autoritaire d'Unreal (replication + RPC), sessions via EOS/Steam.
- **Entrées :** Enhanced Input (clavier/manette).

## 🚧 Statut

Projet en phase de **conception**. Le code fourni est un **squelette de départ**
destiné à être complété dans l'éditeur Unreal (voir le plan de développement).

## 📄 Licence & crédits

- Vérifier la licence de chaque asset tiers et tenir un fichier `CREDITS.md`
  (voir [docs/assets.md](docs/assets.md)).
- Ne représenter aucune marque déposée ni personne réelle.
