# Compte rendu TP noté "Plan local d'urbanisme (PLU)"
***Aurélien Gente - Philippe Ocloo - Thomas Verron - Quentin Balloy***

**SEC 2027 - POO**

## Conception

### Diagramme de classe
Le diagramme de classe est disponible à "https://drive.google.com/file/d/1OJo8Y6LeEljcen-Q6vUjvC9bAaSEwzgJ/view?usp=sharing".

### Spécifications
Les spécifications des méthodes et classes sont directement mentionnées dans les commentaires Doxygen. 

## Choix techniques réalisés

### Classe "Parcelle"
- setType() n'est plus virtual (consigne de l'énoncé). En effet, il est utilisé dans le constructeur de ZU, ZAU, ZN, ZA.
- `surface` est un float, sans partie décimale, conformément à l'exemple de l'énoncé.

## Tests

### Lancer des tests
- Les tests sont présents à tp4-not-verron_ocloo_balloy_gente/tests
- Les tests sont à compiler avec la commande `make test`
- Les tests sont exécutables avec la commande ./tp4-not-verron_ocloo_balloy_gente/[Nom du test]
- Les tests réalisés sont sur les classes suivantes : 
    1. Point2D - nom du test : test_Point2D
    2. Polygone - nom du test : test_Polygone
    3. Parcelle - nom du test : test_Parcelle
    4. Carte - nom du test : test_Carte
*Exemple de commande : `make test && ./tp4-not-verron_ocloo_balloy_gente/test_Point2D`*