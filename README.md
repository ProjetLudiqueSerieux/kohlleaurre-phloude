# <p align = "center">COLOR FLOOD</p>

<br>

# Installation et documentation du jeu :

<b>Commande pour accéder à la documentation : </b>
<em>make documentation</em>


<b>Commande pour compiler les fichier :</b>
<em>make colorflood</em>
<br/>
et pour la partie graphique : <em>make mySDL</em>

<br>

# Utilisation du jeu :

<b>Pour lancer le jeu sur terminal, taper la commande :</b> <em>./colorflood</em>

Vous devrez ensuite choisir la taille du plateau de jeu et le nombre de coup limité. Ce nombre devra être un entier supérieur à 1.<br>
Puis, vous devrez choisir à plusieurs reprise des nombres entre 0 et 5 (compris) correspondant à des couleurs. Et ce jusqu'à ce que vous remplissez la grille (et dans ce cas, c'est la victoire) ou lorsque le nombre de coup restant arrive jusqu'à 0 (dans ce cas, vous avez perdu)




<b>Pour lancer le jeu dans une fenêtre graphique, taper la commande : </b><em>./mySDL</em><br>
<b>ATTENTION : Il y a une erreur de segmentation lorsque la tache arrive à la dernière colonne et de manière rare quand on clique sur du rouge.</b><br>
Vous devez appuyer sur 'd' pour lancer le jeu.<br>
Puis, cliquez sur les couleurs pour transformer la tache dans cette couleur. Vous n'avez pas de limite de coup dans la fenêtre graphique.
