# Tutorat de Programmation Avancée (IMA3 - 2016/2017)

Ce dépôt `GIT` contient le sujet et les données utiles pour la réalisation du _petit_ projet du module de Programmation Avancée.

> __Attention__: ce fichier risque d'évoluer au cours de l'avancée des projets. N'hésitez pas à le consulter régulièrement.

## Résumé

L'objectif de ce projet est de vérifier que vous maîtrisez les principes vus en cours de programmation avancée : structures de données complexes, lecture / écriture de fichiers, compilation séparée et automatique, utilisation de gestionnaire de version...

Pour cela, le travail demandé est de réaliser une application qui permet d'analyser la liste des œuvres de la collection _tate_. Cette liste est stockée dans un fichier qui contient à l'heure actuelle près de 70 000 œuvres. Votre travail est de charger ce fichier pour effectuer un certain nombre de requêtes (liste des oeuvres, recherche d'un artiste...)

## Contexte

De plus en plus d'institutions mettent à disposition leurs données pour les usagers (on parle d'_open data_). C'est le cas de _tate_, institution britannique, qui met à disposition toutes les œuvres stockées dans ses 4 musées. Ces données sont accessibles entre autres via leur page [tate gallery github](https://github.com/tategallery/collection). Pour ce projet nous avons récupéré le fichier datant de février 2017. 

Les données sont stockées dans un fichier `CSV` (_comma-separated values_) qui est un format texte permettant de stocker des tableaux. Chaque ligne du fichier correspond à une ligne du tableau et les différents éléments d'une ligne sont séparés par un élément particulier (en général une virgule `,` mais d'autres sont possibles `\t`, `;`...). La première ligne sert à décrire le nom des différents champs. Par exemple sur le fichier qui nous intéresse :

~~~
id,accession_number,artist,artistRole,artistId,title,dateText,medium,creditLine,year,acquisitionYear,dimensions,width,height,depth,units,inscription,thumbnailCopyright,thumbnailUrl,url
1035,A00001,"Blake, Robert",artist,38,A Figure Bowing before a Seated Old Man with his Arm Outstretched in Benediction. Verso: Indecipherable Sketch,date not known,"Watercolour, ink, chalk and graphite on paper. Verso: graphite on paper",Presented by Mrs John Richmond 1922,,1922,support: 394 x 419 mm,394,419,,mm,,,http://www.tate.org.uk/art/images/work/A/A00/A00001_8.jpg,http://www.tate.org.uk/art/artworks/blake-a-figure-bowing-before-a-seated-old-man-with-his-arm-outstretched-in-benediction-a00001
[...]
~~~

Le premier champ de la première œuvre correspond à l'identifiant (`1035`), le quatrième à l'artiste (`Blake, Robert`)...  Cet exemple vous permet déjà de constater qu'une entrée peut contenir des virgules qui ne sont pas considérées comme des séparateurs si l'entrée contient des guillemets (`"`). Il vous faudra être vigilant sur le traitement du fichier `CSV`.

## Cahier des charges

Il vous est demandé de réaliser un programme qui charge les fichiers de données `CSV` (des exemples sont disponibles dans le répertoire `data`) et qui permet d'interroger facilement ce fichier. Il doit être possible de :

- Lister toutes les oeuvres du fichier
- Vérifier l'existence d'un artiste (en spécifiant son `id`)
- Lister toutes les oeuvres d'un artiste donné (en spécifiant son `id`)
- Compter le nombre d'oeuvres d'un artiste donné (en spécifiant son `id`)
- Afficher le nombre d'oeuvres par artiste (sous la forme `id | artist | number`)
- Afficher l'oeuvre la plus vieille acquise par la collection _tate_ (champ `year` dans le fichier `CSV`)

Le volume de données est relativement important, par conséquent un soin particulier devra être apporté aux structures de données utilisées et à la rapidité d'exécution de votre programme. Les choix algorithmiques devront obligatoirement être expliqués et justifiés dans votre rapport.

Pour permettre d'évaluer automatiquement la performance de votre programme et permettre une utilisation automatique par redirection, votre programme devra fonctionner de la manière suivante :

1. charger le fichier de données
2. attendre une commande
3. traiter la commande
4. afficher le résultat de cette commande
5. revenir à l'étape 2

Les commandes seront les suivantes:

- `1` : liste de toutes les oeuvres
- `2 id`: recherche d'un artiste identifié par `id`
- `3 id`: liste de toutes les oeuvres d'un artiste donné par son `id`
- `4 id`: compte le nombre d'oeuvres pour un artiste donné par son `id`
- `5`: afficher le nombre d'oeuvres par artiste
- `6`: affiche l'oeuvre la plus vieille
- `7`: quitter

Ainsi si votre exécutable s'appelle `projet_pa` il doit être possible de l'utiliser de la manière suivante: 

~~~
$ ./projet_pa < data/requetes.txt
~~~

avec le fichier `requetes.txt` qui contient par exemple:

~~~
1
2 300 
3 558
2 558 
5
2 39
3 16646
6
2 16646
4 558
2 4584
7
~~~


## Déliverables

> La date de fin de projet est le dimanche 4 juin 2017 23:59 CEST. Tout retard entraînera des pénalités.

Vous n'avez rien à imprimer, ni des documents à envoyer par e-mail. Il faudra donner l'accès du dépôt à votre correcteur et celui-ci corrigera à partir de la dernière version du dépôt ou de la branche `release` (si elle existe) avant la date limite. Les `push` qui suivraient la date limite ne seront pas considérés.

Sur votre dépôt devront figurer :

- le code source correctement commenté et indenté
- un `Makefile` pour la compilation automatique
- un `README.md` décrivant l'utilisation de votre programme
- un rapport au format PDF ou un fichier `Rapport.md` (les autres formats ne sont pas acceptés) de 10 pages maximum qui explique vos choix de structures de données, vos choix de conception algorithmique et les principales étapes du déroulement de votre programme.

## Annexes

### Pour démarrer

Pour commencer à travailler, vous pouvez faire un fork du dépôt qui contient le fichier `README.md` que vous êtes en train de lire. Ne pas oublier d'ajouter votre correcteur dans la liste des personnes ayant accès à votre dépôt (menu `Settings` à droite puis Menu `Members` puis bouton `New Projet Member`).

On rappelle brièvement les commandes `GIT` que vous serez amené à utiliser :

- `git help cmd` : pour avoir de l'aide sur la commande `cmd`
- `git add fichier` : pour ajouter au dépôt un nouveau fichier ou un fichier modifié
- `git commit -m "message qui explique les modifications"` : pour sauvegarder les modifications dans le dépôt local
- `git push` : pour mettre à jour le serveur avec votre version du dépôt
- `git pull` : pour récupérer la dernière version du serveur
- `git status`: pour voir l'état de votre dépôt local par rapport au serveur
- `git log --pretty=format:"%h - %an, %ar : %s"`: afficher le log des commits

N'hésitez pas à vous référer au polycopié de programmation avancée pour les détails de chacune des commandes.

### Quelques indications

Comme vous l'aurez remarqué, ce projet repose beaucoup sur la manipulation de chaînes de caractères. Vous pouvez utiliser toutes les fonctions de `string.h`, en particulier :

~~~
#include <string.h>

size_t  strlen(const char *s); // la taille
char*   strcpy(char *restrict dst, const char *restrict src); // copie
int     strcmp(const char *s1, const char *s2); // comparaison
char*   strcat(char *restrict s1, const char *restrict s2); // concaténation
char*   strpbrk(const char *s1, const char *s2); // détecter des caractères
char*   strtok(char *restrict str, const char *restrict sep); // couper une chaîne suivant des séparateurs
~~~

Pour chacune de ces fonctions, n'hésitez pas à consulter l'aide dans le terminal via la commande `man nom_de_la_fonction`.

Enfin on rappelle les caractères spéciaux que vous êtes susceptibles de rencontrer:

- `'\0'`: caractère de fin de chaîne de caractères
- `'\t'`: tabulation horizontale
- `'\n'`: retour à la ligne

### Grille d'évaluation

#### Dépôt GIT

| Critère \ Maîtrise      | D             | C     | B   |   A |
| -------------           |------------- | ----- | --- | --- |
| Travail réparti         | Un seul membre du binôme a travaillé (malus pour l'autre membre du binôme) |  |     |  Les deux binômes ont travaillé ensemble sur le projet   |
| Travail régulier        | Pas de commits      |   Un seul commit en fin de projet | Moins de 5 commits    |  Commits réguliers pendant et hors séances de projet   |
| Qualité du dépôt        | Pas de structuration, fichiers temporaires, produits de compilation, fichiers identiques multipliés, ni branches / ni tags      |    Structuré mais fichiers parasites et 0 tags / branches  | Structuré sans fichiers parasites, pas de tags    | Structuré, sans fichiers parasites, avec tags et/ou branches |

__BONUS__: un bonus supplémentaire sera attribué si le binôme propose une correction / modification / suggestion sur le sujet via un `merge request`

#### Makefile

| Critère \ Maîtrise      | D             | C     | B   |   A |
| -------------           |------------- | ----- | --- | --- |
| Présence / Utilité          | Pas de Makefile ou script bash | Makefile incomplet (manque de cibles, d'options) | Makefile presque complet mais mal / peu commenté   |  Makefile complet et commenté  |
| Structuration          | Pas de structuration / pas d'options |  À peu près structuré mais pas d'options | Structuré mais pas d'option de compilation, factorisation perfectible   |  Bien structuré et factorisé, choix de compilation (debug vs release)  |
| Variables          | Pas de variables |  Quelques Variables externes | Quelques variables internes et variables externes |  Utilisation de variables internes et externes  |


#### Compilation / Exécution

| Critère \ Maîtrise      | D             | C     | B   |   A |
| -------------           |------------- | ----- | --- | --- |
| Compilation          | Ne compile pas (erreurs) | Compile avec warnings | Compile avec warnings (en `-Wall` uniquement)   |  Compile sans Warning avec `Wall` activé  |
| Exécution          | Ne s'exécute pas |  S'exécute avec un `segfault` à la fin | S'exécute partiellement   |  S'exécute correctement  |
| `README.MD`          | Pas présent sur le dépôt |  Présent mais au mauvais format (txt...) | Présent, au bon format mais pas clair |  Présent et explique clairement l'utilisation du programme  |

__REMARQUE__: 3 points seront assignés suivant la vitesse d’exécution du programme, ils seront attribués comme suit

| Vitesse d'exécution | Valorisation |
| ------------------- | ------------ |
| plus rapide que la correction | 3 points + bonus |
| parmi les 10% plus rapides | 3 points |
| parmi les 50% plus rapides | 2 points |
| parmi les 75% plus rapides | 1 point  |
| parmi les 25% les plus lents | 0      |

#### Code : remarques générales

| Critère \ Maîtrise      | D             | C     | B   |   A |
| -------------           |------------- | ----- | --- | --- |
| Lisibilité         | Code non indenté, _magic numbers_, noms pas explicites, pas de commentaires | Code partiellement indenté, peu de commentaires | Code indenté avec commentaires, variables / fonctions peu explicites et _magic numbers_    |  Code bien indenté, lisible, pas de _magic numbers_, variables / fonctions explicites / commentaires   |
| Structuration       | un seul fichier, structuration partielle en fonctions      |   plusieurs fichiers, structuration partielle en fonction | plusieurs fichiers, structuration en fonctions, duplication de code    |  Plusieurs fichiers, structurés, code bien factorisé   |
| Localité des variables      | Beaucoup de variables globales, scope trop large      |    Peu de variable globales (et justifiées quand il y en a), scope des variables trop large  | Pas de variables globales, scope des variables locales trop large    | Pas de variables globales (ou alors présence justifiée), scope des variables adapté |
| Initialisation des variables     | Aucune initialisation     |   Quelques pointeurs initialisés   | Tous les pointeurs sont initialisés et quelques variables    | Pointeurs et variables sont correctement initialisés |
| Code de retours des fonctions     | Ne teste aucun code de retours      |   Quelques codes de retours sont testés   | Les codes de retours des fonctions systèmes sont testés (`malloc`, `fopen`,...)    | Toutes les codes de retours de fonctions sont testés |
| Gestion de la mémoire    | Aucun `free` de la mémoire allouée dynamiquement     |   Quelques `free`   | La majorité de la mémoire dynamique est libérée    | Toute la mémoire allouée dynamiquement est libérée |
| Gestion des fichiers   | Les fichiers ne sont pas bien ouverts et pas fermés     |   Les fichiers ne sont pas ouvert dans le bon mode et certains ne sont pas fermés  | Les fichiers sont ouverts dans le bon mode et la majorité sont fermés   | Les fichiers sont ouverts dans le bon mode et bien fermés après utilisation |

#### Code : remarques spécifiques

| Critère \ Maîtrise      | D             | C     | B   |   A |
| -------------           |------------- | ----- | --- | --- |
| Structures de données          | Structures de données inadaptées et mauvaise implémentation | Structures de données inadaptées mais bien implémentées | Structures de données pertinentes mais implémentation perfectible   |  Structures de données pertinentes et bien implementées |
| Lecture de fichier et remplissage de la SD          | Ne fonctionne pas |  Lecture partiellement OK et remplissage très incomplet de la SD | Lecture OK certaines lignes sont mal analysées (caractères spéciaux par exemple)   |  Lecture OK, tous les éléments sont bien analysés  |
| Cahier des Charges - M1 (liste)          | Ne fonctionne pas |  Incomplet | Complet mais algorithmes inutilement complexe (trop de boucles...)   |  OK  |
| Cahier des Charges - M2 (recherche)          | Ne fonctionne pas |  Fonctionne partiellement (résultat faux) | Recherche OK mais non-optimale (SD pas adaptée)   |  Recherche OK et efficace  |
| Cahier des Charges - M3 (recherche multiple)          | Ne fonctionne pas |  Fonctionne partiellement (résultat faux) | Recherche OK mais non-optimale (SD pas adaptée, mauvaise gestion des doublons)   |  Recherche OK et efficace  |
| Cahier des Charges - M4 (comptage)          | Ne fonctionne pas |  Comptage faux | Comptage OK mais algorithmes inutilement complexe (trop de boucles...)   |  Comptage OK  |
| Cahier des Charges - M5 (affichage)          | Ne fonctionne pas |  Fonctionne partiellement (résultat faux) |  OK mais non-optimal (SD pas adaptée, mauvaise gestion des doublons)   |  OK et efficace  |
| Cahier des Charges - M6 (oeuvre + vieille)          | Non traitée |  Resultat faux  | Resultat OK mais algorithmes inutilement complexes |  Resultat OK et efficace  |

### Rapport

| Critère \ Maîtrise      | D             | C     | B   |   A |
| -------------           |------------- | ----- | --- | --- |
| Format et taille         | Autre que PDF |   |  PDF mais non respect de la limite de pages  |  PDF et respect du nombre de pages |
| Structuration en partie          | Pas de structure | Structure mais pas de plan au début | Plan OK mais structuration non pertinente (résolution avant explication de la SD par exemple)   |  Structuré et découpage cohérent |
| Intro / Conclusion          | Aucun des deux | L'un ou l'autre |   |  Intro et Conclusion |
| Précisions du CdC          | Pas mentionnées | Adaptations contraires au CdC | Adaptations OK avec le CdC mais non justifiées   |  Mentionnées et justifiées |
| Justifications          | SD et algos ne sont pas justifiés | SD justifiées mais pas algos | SD justifiées et partiellement pour les algos   |  SD et algos clairement justifiés |
| Limitations          | Limitations existantes ne sont pas mentionnées | Certaines limitations sont mentionnées | Limitations évoquées   |  Limitations évoquées et pistes de résolutions proposées |

### Pour comparer votre programme

Pour comparer votre programme à une solution possible, vous pouvez utiliser le binaire disponible sur le compte unix de `jdequidt` (il faut vous placer dans le répertoire `cd ~jdequidt/ima3_projet_test`)

1. Utilisation simple

~~~ 
$  ./tate_art data/tate_artwork.csv
~~~

2. Utilisation avec requêtes prédéfinies

~~~
$ ./tate_art data/tate_artwork.csv < requetes/5000_req.txt 
~~~


3. Utilisation avec mesure du temps

~~~
$ time ./tate_art data/tate_artwork.csv < requetes/5000_req.txt > /dev/null
~~~

> la redirection de la sortie standard vers `/dev/null` permet de ne pas afficher les printf et de polluer l'affichage
