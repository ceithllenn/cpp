#!/bin/bash

# Vérifie que le nombre d'arguments est correct
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <nombre d'entiers>"
  exit 1
fi

# Récupère le nombre d'entiers à générer
N=$1

# Vérifie que l'entrée est un entier positif
if ! [[ "$N" =~ ^[0-9]+$ ]] || [ "$N" -le 0 ]; then
  echo "Erreur : veuillez fournir un entier positif comme argument."
  exit 1
fi

# Génère une liste de N entiers aléatoires
random_list=$(shuf -i 1-100000 -n "$N" | tr '\n' ' ')

# Exécute le programme ./PmergeMe avec cette liste
if [ -x "./PmergeMe" ]; then
  ./PmergeMe $random_list
else
  echo "Erreur : le programme ./PmergeMe n'est pas exécutable ou introuvable."
  exit 1
fi
