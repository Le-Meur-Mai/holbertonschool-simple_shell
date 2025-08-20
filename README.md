# Projet `simple_shell`

Un interpréteur de commandes écrit en C, inspiré du shell de Ken Thompson.  
Ce projet HOLBERTON met en œuvre des concepts fondamentaux comme la création de processus enfant, la gestion de l’environnement, et l’utilisation d'appel système.

---

## Table des matières

- [Aperçu](#aperçu)
- [Flowchart](#flowchart)
- [Fonctionnalités](#fonctionnalités)
- [Structure du projet](#structure-du-projet)
- [Exigences](#exigences)
- [Page de manuel](#page-de-manuel)
- [Exemples d'utilisation](#exemples-dutilisation)
- [Auteurs](#auteurs)

---

## Aperçu

Le shell est un programme qui lit des commandes entrées par l’utilisateur, recherche leur exécutable dans l'environnement, crée un processus enfant et exécute le programme demandé.  
Il fonctionne aussi bien en **mode interactif** qu’en **mode non-interactif** (via des scripts ou des pipes).

---

## Flowchart

---

## Fonctionnalités

- Affiche un prompt et attend la saisie d’une commande.
- Exécute des commandes avec ou sans arguments.
- Recherche les programmes via la variable d’environnement **PATH**.
- Gestion des erreurs (commande introuvable, exécutable invalide, etc.).
- Support de la combinaison `Ctrl+D` (**EOF**) pour quitter le shell.
- Implémentation des **built-ins** :
  - `exit` : quitter le shell
  - `env` : afficher l’environnement courant

---

## Structure du projet

| Fichier              | Rôle                                                                 |
|----------------------|----------------------------------------------------------------------|
| `shell.c`             | Fonction principale du shell (boucle de lecture, exécution, gestion erreurs) |
| `main.h`             | Header principal : includes, définitions et prototypes                |
| `_getenv.c`          | Recherche et retourne la valeur d’une variable d’environnement        |
| `_which.c`           | Recherche le chemin absolu d’une commande via `$PATH`                 |
| `_wexitstatus.c`     | Extraction du code de sortie d’un processus (équivalent `WEXITSTATUS`) |
| `argv_for_shell.c`   | Transforme une ligne de commande en tableau d’arguments (`_argv[]`)    |
| `verif_built_in.c`    | Vérifie et exécute les commandes internes (`env`, `exit`)             |
| `executing_program.c`| Exécute un programme externe avec `fork` + `execve`                   |
| `free_arguments.c`   | Libère la mémoire des arguments et de la ligne                        |
| `print_env.c`        | Affiche toutes les variables d’environnement                         |


---

## Exigences


Compilation sur Ubuntu 20.04 LTS avec gcc :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c hsh
```

Tous les fichiers doivent :

Se terminer par une nouvelle ligne

Respecter la norme Betty

Contenir maximum 5 fonctions par fichier

Les prototypes sont centralisés dans main.h

Les fichiers d’en-tête sont protégés par des gardes d’inclusion

Le projet ne doit contenir aucune fuite mémoire

---

## Page de manuel

Pour lire la manpage locale du shell :

```bash
man ./man_simple_shell
```

---

## Exemples d'utilisation

Mode interactif

```bash
./hsh
$ /bin/ls
a.out        AUTHORS                 executing_program.c  _getenv.c  man_1_simple_shell  README.md  _wexitstatus.c
arguments.c  command_verification.c  free_arguments.c     main.h     print_env.c         shell.c    _which.c
$ ls -l
total 72
-rwxrwxr-x 1  franck 17320 août  20 12:20 hsh
-rw-rw-r-- 1 franck franck   801 août  20 09:29 argv_for_shell.c
-rw-rw-r-- 1 franck franck   131 août  20 09:36 AUTHORS
-rw-rw-r-- 1 franck franck   615 août  20 09:29 verif_built_in.c
-rw-rw-r-- 1 franck franck   953 août  20 09:29 executing_program.c
-rw-rw-r-- 1 franck franck   292 août  20 09:29 free_arguments.c
-rw-rw-r-- 1 franck franck   585 août  20 09:29 _getenv.c
-rw-rw-r-- 1 franck franck   554 août  20 09:29 main.h
-rw-rw-r-- 1 franck franck    91 août  20 09:29 man_simple_shell
-rw-rw-r-- 1 franck franck   241 août  20 09:29 print_env.c
-rw-rw-r-- 1 franck franck  3811 août  20 12:22 README.md
-rw-rw-r-- 1 franck franck  1150 août  20 09:29 shell.c
-rw-rw-r-- 1 franck franck   465 août  20 09:29 _wexitstatus.c
-rw-rw-r-- 1 franck franck  1219 août  20 09:29 _which.c
$ env
SHELL=/bin/bash
SESSION_MANAGER=local/APPLE-A2780:@/tmp/.ICE-unix/2337,unix/APPLE-A2780:/tmp/.ICE-unix/2337
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
TERM_PROGRAM_VERSION=1.103.0
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
GNOME_SHELL_SESSION_MODE=ubuntu
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
GTK_MODULES=gail:atk-bridge
PWD=/home/franck/GITHUB/holbertonschool-simple_shell
XDG_SESSION_DESKTOP=ubuntu
LOGNAME=franck
XDG_SESSION_TYPE=wayland
SYSTEMD_EXEC_PID=2384
VSCODE_GIT_ASKPASS_NODE=/usr/share/code/code
IM_CONFIG_CHECK_ENV=1
GJS_DEBUG_TOPICS=JS ERROR;JS LOG
HOME=/home/franck
USERNAME=franck
IM_CONFIG_PHASE=1
LANG=fr_FR.UTF-8
XDG_CURRENT_DESKTOP=Unity
WAYLAND_DISPLAY=wayland-0
USER=franck
CLUTTER_DISABLE_MIPMAPPED_TEXT=1
DISPLAY=:0
SHLVL=1
GSM_SKIP_SSH_AGENT_WORKAROUND=true
QT_IM_MODULE=ibus
XDG_RUNTIME_DIR=/run/user/1000
DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
GDK_BACKEND=x11
GDMSESSION=ubuntu
ORIGINAL_XDG_CURRENT_DESKTOP=ubuntu:GNOME
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
GIO_LAUNCHED_DESKTOP_FILE=/usr/share/applications/code.desktop
OLDPWD=/home/franck/GITHUB
_=./a.out
$ exit
```

Mode non-interactif

```bash 
echo "/bin/ls" | ./hsh
hsh        AUTHORS                 executing_program.c  _getenv.c  man_simple_shell  README.md  _wexitstatus.c
argv_for_shell.c  verif_built_in.c  free_arguments.c     main.h     print_env.c         shell.c    _which.c
```

---
## Auteurs

- [@joevinM](https://www.github.com/joevinM)
- [@Le-Meur-Mai](https://www.github.com/Le-Meur-Mai)