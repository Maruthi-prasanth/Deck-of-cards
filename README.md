# Deck of Cards Simulation and Games

## Table of Contents

- [Overview](#overview)
- [Problem Statement](#problem-statement)
- [Problem Explanation](#problem-explanation)
  - [Project Details](#project-details)
  - [Class Definition](#class-definition)
  - [Shuffle Function](#shuffle-function)
  - [Display Function](#display-function)
- [Algorithm](#algorithm)

## Overview

This project involves the design and analysis of algorithms, specifically focusing on randomized algorithms and simulations using C++. The main objectives include creating a pack of playing cards, simulating the shuffling of the pack, proposing two new card games, and implementing the process using an array of structures.


## Problem Statement

1. Create a pack of playing cards (4 colors, each ranging from 2, 3, ..., 10, Jack, Queen, King, Ace).
2. Display the cards, simulate shuffling of the pack, and display the shuffled cards.
3. Propose two new games with cards and implement the process using the array of structures.

## Problem Explanation

### Project Details

- Deck of cards is created using string functions.
- The `srand()` function is utilized for randomizing or shuffling the deck of cards.
- Shuffled deck of cards is displayed.
- Two card games are proposed to the players (2-4 players).
- Winner is declared after playing the games.

### Class Definition

- Class: Deck
  - Declares required elements.
  - Stores all the deck of cards (52) with their respective color and face in a string function.

### Shuffle Function

- Uses the `srand()` function to randomize or shuffle the deck of cards.
- Picks each random variable in a loop and swaps it with the first element.
- Asks the user to enter the number of players needed to play the proposed game (min: 2).
- Provides each player with cards (13 each) randomly.
- Displays each player's respective cards and the shuffled deck of cards (52).

### Display Function

- Uses a for loop to traverse the index from 1 to 52 cards.
- Displays the cards, ensuring each player receives 13 cards.

## Algorithm

### Shuffle Function

**Input:** Deck of cards [52].
**Output:** Shuffled deck of cards.

1. Start
2. Use a for loop and initialize a variable 'random'.
3. Swap the first element in the array with the randomized element.
4. If the number of players is from 2 to 4, provide each player with 13 cards.
5. Display each player's cards.
6. Stop.

### Display Function

1. Start
2. Use a for loop to traverse the index I to all 52 cards.
3. If 13 cards are provided for all players, display them.
4. Stop.
