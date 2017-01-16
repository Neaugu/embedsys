# Projet Armadeus 

Authors : Groupe 3 : Neau Guillaume, Boenning Hannah, Tomezac Julien, Soulié Camille, Cotten Guillaume

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

utilisateur    == message clair ==>    client   == message crypté ==>    serveur    == message décrypté en morse ==>    LED

-----
## Compilation
Lancer dans la commande make dans la console utilisateur.

-----
## Exécution
1. Allumer la carte. Le serveur se lance automatiquement au démarrage.
2. Lancer le client sur le poste : ./remote [adresse IP du serveur] [message]
3. Observer la LED


