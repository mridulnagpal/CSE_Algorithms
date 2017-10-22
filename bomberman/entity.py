""" This module contains the creation of all
    entities and their basic movement functions """

import random
from board import *


# Contains the base of all entities and their movements
class Entity():
    def __init__(self, health, location):
        self.health = health
        self.location = location

    # Moves entity left
    def moveLeft(self, board):
        curr = self.location
        b = Board()

        if b.checkBoard(curr[0], curr[1] - 1, board) == 1:
            pass
        else:
            self.location[1] = curr[1] - 1

    # Moves entity right
    def moveRight(self, board):
        curr = self.location
        b = Board()
        if b.checkBoard(curr[0], curr[1] + 1, board) == 1:
            pass
        else:
            self.location[1] = curr[1] + 1

    # Moves entity down
    def moveDown(self, board):
        curr = self.location
        b = Board()
        if b.checkBoard(curr[0] + 1, curr[1], board) == 1:
            pass
        else:
            self.location[0] = curr[0] + 1

    # Moves entity up
    def moveUp(self, board):
        curr = self.location
        b = Board()
        if b.checkBoard(curr[0] - 1, curr[1], board) == 1:
            pass
        else:
            self.location[0] = curr[0] - 1


# Contains the creation of a bomber
class Bomber(Entity):
    def __init__(self, health, location):
        Entity.__init__(self, health, location)


# Contains the creation and movement of enemies
class Enemy(Entity):
    def __init__(self, health, location):
        Entity.__init__(self, health, location)

    # Moves enemy automatically in any possible direction
    def autoMove(self, board):
        pMoves = []
        curr = self.location
        b = Board()
        if b.checkBoard(curr[0], curr[1] - 1, board) != 1:
            pMoves.append(1)
        if b.checkBoard(curr[0], curr[1] + 1, board) != 1:
            pMoves.append(3)
        if b.checkBoard(curr[0] - 1, curr[1], board) != 1:
            pMoves.append(0)
        if b.checkBoard(curr[0] + 1, curr[1], board) != 1:
            pMoves.append(2)

        if len(pMoves) > 0:
            direction = random.randint(0, len(pMoves) - 1)
            board[self.location[0]][self.location[1]] = 0

            if pMoves[direction] == 0:
                self.moveUp(board)
            elif pMoves[direction] == 1:
                self.moveLeft(board)
            elif pMoves[direction] == 2:
                self.moveDown(board)
            elif pMoves[direction] == 3:
                self.moveRight(board)
            board[self.location[0]][self.location[1]] = 3

# Contains bomb creation and its explosion function


class Bomb(Entity):
    def __init__(self, health, location):
        Entity.__init__(self, health, location)

    # Stores in bombLocations all the points where the bomb explosion will
    # occur
    def explode(self, bombLocations, board):
        up = 1
        down = 1
        left = 1
        right = 1

        bombLocations.append([self.location[0] - 1, self.location[1]])
        x = bombLocations[len(bombLocations) - 1][0]
        y = bombLocations[len(bombLocations) - 1][1]
        if (x > len(board) - 4 or x < 0 or y < 0 or
                y > len(board) - 4 or (y % 2 == 1 and x % 2 == 1)):
            left = 0

        bombLocations.append([self.location[0] + 1, self.location[1]])
        x = bombLocations[len(bombLocations) - 1][0]
        y = bombLocations[len(bombLocations) - 1][1]
        if (x > len(board) - 4 or x < 0 or y < 0 or
                y > len(board) - 4 or (y % 2 == 1 and x % 2 == 1)):
            right = 0

        bombLocations.append([self.location[0], self.location[1] - 1])
        x = bombLocations[len(bombLocations) - 1][0]
        y = bombLocations[len(bombLocations) - 1][1]
        if (x > len(board) - 4 or x < 0 or y < 0 or
                y > len(board) - 4 or (y % 2 == 1 and x % 2 == 1)):
            up = 0

        bombLocations.append([self.location[0], self.location[1] + 1])
        x = bombLocations[len(bombLocations) - 1][0]
        y = bombLocations[len(bombLocations) - 1][1]
        if (x > len(board) - 4 or x < 0 or y < 0 or
                y > len(board) - 4 or (y % 2 == 1 and x % 2 == 1)):
            down = 0

        if left:
            bombLocations.append([self.location[0] - 2, self.location[1]])

        if right:
            bombLocations.append([self.location[0] + 2, self.location[1]])

        if up:
            bombLocations.append([self.location[0], self.location[1] - 2])

        if down:
            bombLocations.append([self.location[0], self.location[1] + 2])
