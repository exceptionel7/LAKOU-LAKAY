# Liste d'assets — LAKOU LAKAY

> Assets graphiques et sonores à créer ou à sourcer, avec un rappel des licences.
> ⚠️ **Règle d'or droits d'auteur :** ne jamais utiliser d'assets sans licence claire. Vérifier la licence de CHAQUE asset et conserver une trace (fichier `CREDITS.md`). En cas de doute → créer soi-même ou commander à un·e artiste.

---

## 1. Assets graphiques (3D)

### 1.1 Environnement (à sourcer puis adapter)
| Asset | Piste de source gratuite | À créer/adapter soi-même |
|---|---|---|
| Sols, murs béton, gravats, surfaces | **Quixel Megascans** (gratuit avec Unreal, licence Epic) | Peintures murales, enseignes en créole |
| Végétation tropicale (palmiers, bananiers, herbes) | Megascans, **Unreal Marketplace** (assets gratuits du mois) | Espèces spécifiques haïtiennes |
| Rochers, montagnes en arrière-plan | Megascans | Silhouette des mornes locaux |
| Mobilier urbain générique | Marketplace / Sketchfab (filtre licence) | Étals de marché, kiosques |

### 1.2 Éléments spécifiquement haïtiens (à MODÉLISER — signature visuelle)
- **Tap-tap** peint (véhicule emblématique, décors colorés).
- **Maisons** en béton + tôle ondulée, couleurs vives, cours (lakou).
- **Marché en plein air** : étals, paniers, produits locaux, parasols.
- **Église / chapelle** de quartier.
- **Enseignes peintes à la main** (barbershop, boutik, loterie) — attention à inventer les noms.
- **Accessoires** : bidons d'eau, brouettes, générateurs, linge étendu.

### 1.3 Personnages
- **Danel & Franko** : meshes, morphologies crédibles et variées, vêtements du quotidien.
- **PNJ habitants** (Grann Ilména, Fresnel, Nadège, Ti-Woulou, Doc Estève, Sò Manzè) + foule variée (âges, morphologies, tenues).
- **Antagonistes fictifs** (Grif Fè, Zèklè, Lonbraj, Bèt Nwa + boss final) — designs inventés, non basés sur des personnes réelles.
- **Otages** : PNJ civils variés.
- Pistes gratuites de départ : **MetaHuman** (Epic, gratuit — visages réalistes personnalisables), animations **Mixamo** (Adobe, gratuit).

### 1.4 Armes & objets tactiques
- Armes à feu **génériques/fictives** (pas de reproduction de marques réelles → risque de marque déposée), couteau, gadgets (fumigène, leurre, kit de soin, brouilleur).

### 1.5 UI / VFX
- HUD, menus, icônes, police lisible multilingue (supportant les accents créole/français/espagnol).
- VFX : fumée, impacts, lumières, effet de "repérage".

---

## 2. Assets sonores

### 2.1 Musique
- **Compas & rasin** originaux — idéalement **composés/commandés** à des musicien·ne·s haïtien·ne·s (authenticité + droits clairs). C'est un poste à budgéter en priorité.
- À défaut au prototype : musique libre de droits (voir §3) en attendant l'originale.

### 2.2 Ambiances & SFX
- Sons de rue (marché, foule, tap-taps, animaux, générateurs), pas, portes, nature tropicale, pluie.
- SFX gameplay : armes, crochetage, fumigène, alertes.

### 2.3 Voix (doublage créole)
- **VO en créole haïtien par des acteur·rice·s natif·ve·s** (fortement recommandé pour l'authenticité).
- Chaque réplique porte une **clé** (voir `Data/Dialogues/`) partagée avec le texte → facilite l'enregistrement et l'intégration.
- Alternative de départ : synthèse vocale pour "placeholder", à remplacer par de vraies voix.

---

## 3. Sources gratuites et leurs licences (à vérifier au cas par cas)

| Source | Type | Note licence |
|---|---|---|
| **Quixel Megascans** | 3D/textures | Gratuit pour une utilisation dans Unreal Engine (licence Epic). |
| **Unreal Marketplace / Fab** | 3D, audio, plugins | Beaucoup de gratuits ; lire la licence de chaque pack. |
| **MetaHuman** | Personnages | Gratuit, destiné aux projets Unreal (voir conditions Epic). |
| **Mixamo** | Animations | Gratuit (Adobe), utilisable en projet. |
| **Freesound** | SFX | Licences variables (CC0, CC-BY…). **Vérifier chaque son**, créditer si CC-BY. |
| **OpenGameArt / Kenney** | 2D/3D/audio | Souvent CC0. Vérifier. |
| **Free Music Archive / ccMixter** | Musique | Licences Creative Commons variables. |

> ⚠️ **Creative Commons ≠ "gratuit sans conditions"** : CC-BY exige l'attribution, CC-NC interdit l'usage commercial, CC-SA impose le partage à l'identique. Si tu comptes vendre le jeu, privilégie **CC0** ou des assets sous licence commerciale explicite, ou du contenu original.

---

## 4. Bonnes pratiques droits d'auteur
1. Tenir un fichier **`CREDITS.md`** : pour chaque asset → nom, auteur, source (URL), licence, date.
2. Éviter toute **marque déposée** (logos, marques d'armes, marques de véhicules réels).
3. Ne représenter **aucune personne réelle** (visage, nom, voix).
4. Pour la musique/voix haïtiennes : privilégier des **contrats clairs** avec les artistes (cession de droits pour le jeu).
5. Sensitivity reading + collaboration avec des créateur·rice·s haïtien·ne·s : bon pour l'authenticité *et* pour le respect.
