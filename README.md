# Projet Armadeus 

Authors : Groupe 3 : Neau Guillaume, Boenning Hannah, Tomezach Julien, Soulié Camille, Cotten Guillaume

:email: [Prénom].[Nom]@ensta-bretagne.org

-----
## Généralités

L'ensemble du projet est disponible sur le dépôt
github https://github.com/Neaugu/embedsys.

Si vous voulez cloner entièrement le dépôt :

$ git clone https://github.com/Neaugu/embedsys
-----

-----
## Objectifs du Projet

Dans le cadre de ce projet nous devions mettre en place une communication entre une carte Armadeus APF28 et un ordinateur. Pour cela nous avons codé un serveur sur la carte et un client sur le poste utilisateur. L'utilisateur transmet un message à la carte. Ce message est crypté par l'utilisateur et transmis à la carte, qui le décrypte et le transmet en morse via un signal lumineux.

utilisateur    == [message clair] ==>    client   == [message crypté] ==>    serveur    == [message décrypté en morse] ==>    LED

-----
## Compilation

Tous les fichiers nécessaires à la compilation se trouvent dans le répertoire "transmission"

Dans le Makefile il faut remplacer "gcc" de la ligne: 

gcc -o server server.c led_api.c CESAR.c traducteur.c projet.h -W

par le chemin du gcc de votre carte cible, comme ceci par exemple: 

/home/u/Documents/armadeus/buildroot/output/host/usr/bin/arm-buildroot-linux-uclibcgnueabi-gcc -o server server.c led_api.c CESAR.c traducteur.c projet.h -W

Puis lancer la commande make (du répertoire transmission) dans un terminal.

-----
## Installation

Suite à la compilation vous obtenez deux exécutable: remote et server.

Les fichiers à envoyer à la carte sont le server et les scripts se trouvant dans codeCard.

Si vous n'aviez pas le gcc de votre carte, vous trouverez une version fonctionnelle de server dans codeCard nommée serverARMNew.

Pour installer les programmes sur la carte il suffit:


De mettre les fichiers blink_long.sh et server (ou serverARMNew) dans /root/.

Puis S99app dans /etc/init.d/ en vérifiant qu'il a le droit d'être exécuté, sinon faire:

chmod a+x /etc/init.d/S99app

Enfin rebootez la carte pour finaliser l'installation.

-----
## Exécution
1. Allumer la carte. Le serveur se lance automatiquement au démarrage.
2. Lancer le client dans un terminal sur le poste utilisateur : ./remote [adresse IP du serveur] [message]
3. Observer la LED


