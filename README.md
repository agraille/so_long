# So Long - Jeu du Lapin

**So Long** est un jeu où vous incarnez un lapin courageux qui doit éviter les griffes d’un loup affamé tout en ramassant toutes les carottes dispersées à travers un champ. Le but du jeu est simple : récupérer toutes les carottes pour pouvoir s’échapper avant que le loup ne vous attrape !

## 🎮 Règles du jeu

1. **Incarnez le Lapin** : Vous contrôlez un lapin agile, qui doit se déplacer sur un terrain rempli de carottes et d'un loup dangereux.
2. **Évitez le Loup** : Le loup se déplace aléatoirement sur la carte et cherche à attraper le lapin. Si le lapin est attrapé, le jeu est perdu !
3. **Ramassez les Carottes** : Le lapin doit collecter toutes les carottes présentes sur le terrain pour pouvoir s’échapper. Chaque carotte rapportera des points et rapproche le lapin de la victoire.
4. **Échappez-vous !** : Une fois toutes les carottes ramassées, le lapin peut s’échapper. Si le loup n’a pas attrapé le lapin, vous gagnez !

## ⚙️ Comment jouer

### Contrôles :
- **Flèches directionnelles** (ou **WASD**) pour déplacer le lapin.
- **Évitez** de rentrer en collision avec le loup !

### Objectif :
- Ramasser toutes les carottes et échapper au loup avant d'être capturé.

## 🛠️ Installation

### Prérequis
- C compiler (cc)

### Cloner le projet
- Clonez le dépôt GitHub pour obtenir les fichiers du jeu :

```bash
git clone https://github.com/agraille/so_long.git
```

### Compilation
```bash
cd so-long
make
```

### Lancer le jeu

```bash
./so_long map/"select a map"
```



## 📖 À propos
Ce projet a été créé dans le cadre de l’apprentissage de la programmation en C. Il met en pratique l'utilisation de graphismes ASCII pour créer un environnement de jeu simple et interactif.

Fonctionnalités :
- Déplacement du lapin à l'aide des flèches directionnelles.
- Mouvement aléatoire du loup.
- Collecte de carottes.
- Conditions de victoire et de défaite.

## 🎨 Aperçu du Jeu
Voici à quoi ressemble le jeu en mode texte :

```bash
111111111111111111111111111
100000010000000000111100001
10CE00000000000000000000111
100000000000000000000000001
100C0000000000000C000000001
10P00000000000000K000000001
100000000000000000000000001
111111111111111111111111111
```

en mode graphique :

- ![Texte alternatif](https://github.com/agraille/so_long/raw/main/Image%20collée%20(1).png)
- ![Texte alternatif](https://github.com/agraille/so_long/raw/main/Image%20collée%20(2).png)
- ![Texte alternatif](https://github.com/agraille/so_long/raw/main/Image%20collée%20(3).png)
- ![Texte alternatif](https://github.com/agraille/so_long/raw/main/Image%20collée%20(4).png)


Légende :

- 0 = espace vide
- 1 = mur
- C = carotte
- K = loup
- E = sortie
- P = joueur (représenté par un lapin dans le jeu)

## 💻 Contribuer
Les contributions sont les bienvenues ! Si vous souhaitez améliorer le jeu, ajouter de nouvelles fonctionnalités ou corriger des bugs, n’hésitez pas à faire un fork du projet et proposer une pull request.

Comment contribuer :
- 1 - Forkez le projet.
- 2 - Créez une branche pour vos modifications : git checkout -b feature/amélioration
- 3 - Committez vos changements : git commit -am 'Ajout d’une nouvelle fonctionnalité'
- 4 - Poussez la branche : git push origin feature/amélioration
- 5 - Ouvrez une Pull Request pour proposer vos changements.
