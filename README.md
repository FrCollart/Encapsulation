# Ligma
---

## Requirements

Ce projet nécessite une version de C++ égale ou supérieure à 17.0 pour fonctionner.

Ce projet dépend de 2 librairies externes C++ :
- SDL 2.0 : [Site de SDL](https://www.libsdl.org/)
- Raylib : [Site de raylib](https://www.raylib.com/)

Vous n'avez pas besoin de les télécharger, elles sont intégrées au projet. 

---

Ce depot contient une Release (v1.0), mais si vous tenez quand même à en build une vous même, suivez ces différentes étapes:

1. **Lancer le fichier Ligma.sln**
2. **Mettez vous en mode Release ou Debug et générez la solution (Ctrl + B)**
3. **Rendez vous ensuite dans le dossier source et copiez les fichiez suivants: raylib.dll, SDL2.dll, SDL2_image.dll et SDL_ttf.dll ainsi que les dossiers Textures/ et Fonts/**
4. **Rendez vous dans le dossier de build précédemment créé (./x64/Debug ou ./x64/Release ou ./x86/Debug ou ./x86/Release) et collez les fichiers et les dossiers**
5. **Lancez l'application**

---

## Contrôles

Une fois l'application lancée, Entrez 1 dans la console pour rendre avec SDL, appuyez sur 2 pour rendre avec raylib. Il n'y a pas de possibilité de changer cela à la compilation mais mettre un fichier d'input est tout à fait envisageable. Nous avons pris la décision de pouvoir changer à volonté de librairie de rendu au runtime.
Pour changer de librairie de rendu, fermez simplement la fenêtre (pas la console) et entrez à nouveau 1 ou 2.

Une fois l'application lancée, maintenez clic gauche pour apercevoir l'angle dans lequel votre boule va partir. Plus vous vous éloignez avec votre souris, plus l'impact sera fort et plus la boule partira vite.

Amusez-vous bien.

---
