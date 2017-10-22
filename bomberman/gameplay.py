""" This module contains the entire display class and
    all checks for proper functioning of the Gameplay """

import os
from random import randint
from entity import *


# Contains all colors along with their ANSI codes
class bcolors:
    BLUE = "\033[1;36m"
    BROWN = "\033[0;33m"
    GREEN = "\033[92m"
    ORANGE = "\033[1;31m"
    PURPLE = "\033[1;35m"
    FAIL = "\033[91m"
    ENDC = "\033[0m"
    BOLD = "\033[1m"
    UNDERLINE = "\033[4m"
    RED = "\033[31m"
    YELLOW = "\033[1;33m"
    GRAY = "\033[1;30m"
    CYAN = "\033[0;34m"


# Handles all the printing of the board, bomberman and the enemies
class Display():
    def printWall(self, board, blocks, bomber, enemies, bomb):
        for k in range(2):
            for i in range(20):
                if (i == 19):
                    print("")
                else:
                    print(bcolors.CYAN + "####" + bcolors.ENDC, end="")
        bmLocation = bomber.location
        eLocations = []
        for enemy in enemies:
            eLocations.append(enemy.location)
        bombLocations = [[bomb.location[0], bomb.location[1]]]
        if bomb.health == 0:
            bomb.explode(bombLocations, board)

        for i in range(34):
            print(bcolors.CYAN + "####" + bcolors.ENDC, end="")
            for j in range(17):
                if (i % 4 == 2 or i % 4 == 3) and j % 2 == 1:
                    print(bcolors.CYAN + "####" + bcolors.ENDC, end="")

                elif [int(i / 2), j] in bombLocations:
                    self.printBomb(bomb, i)

                elif [int(i / 2), j] in eLocations:
                    for enemy in enemies:
                        if enemy.location == [int(i / 2), j]:
                            self.printEnemy(enemy, i)
                            break

                elif i == bmLocation[0] * 2 and j == bmLocation[1]:
                    self.printBomber("upper")

                elif i == bmLocation[0] * 2 + 1 and j == bmLocation[1]:
                    self.printBomber("lower")

                elif (board[int(i / 2)][j] == 0 and
                      ([int(i / 2), j] not in blocks)):
                    print("    ", end="")

                elif [int(i / 2), j] in blocks:
                    print(bcolors.GREEN + "%%%%" + bcolors.ENDC, end="")

            print(bcolors.CYAN + "####" + bcolors.ENDC)

        for k in range(2):
            for i in range(20):
                if (i == 19):
                    print("")
                else:
                    print(bcolors.CYAN + "####" + bcolors.ENDC, end="")

    # Prints Bomber
    def printBomber(self, half):
        if half == "upper":
            print(bcolors.PURPLE + "[" + bcolors.ENDC + bcolors.BLUE + "^^"
                  + bcolors.ENDC + bcolors.PURPLE + "]" + bcolors.ENDC, end="")
        else:
            print(bcolors.PURPLE + " ][ " + bcolors.ENDC, end="")

    # Prints Enemy based on health
    def printEnemy(self, enemy, x):
        if x % 2:
            print(bcolors.PURPLE + bcolors.BOLD + " ][ "
                  + bcolors.ENDC, end="")
        elif enemy.health == 1:
            print(bcolors.RED + "EEEE" + bcolors.ENDC, end="")
        elif enemy.health == 2:
            print(bcolors.YELLOW + "EEEE" + bcolors.ENDC, end="")
        else:
            print(bcolors.BOLD + "EEEE" + bcolors.ENDC, end="")

    # Prints bomb and its explosion given the coordinates
    def printBomb(self, bomb, x):
        if bomb.health == 0 and x % 2:
            print(bcolors.YELLOW + "^^^^" + bcolors.ENDC, end="")
        elif bomb.health == 0 and x % 2 == 0:
            print(bcolors.ORANGE + "^^^^" + bcolors.ENDC, end="")
        elif bomb.health == 1:
            print(bcolors.GRAY + "[11]" + bcolors.ENDC, end="")
        elif bomb.health == 2:
            print(bcolors.GRAY + "[22]" + bcolors.ENDC, end="")
        elif bomb.health == 3:
            print(bcolors.GRAY + "[33]" + bcolors.ENDC, end="")

    # The driver function which prints everything
    def printBoard(self, board, blocks, score, bomber, enemies, bomb, lives):
        os.system("clear")
        print("Lives:", lives, "  Score: ", score)
        print("Health: ", bomber.health)
        self.printWall(board, blocks, bomber, enemies, bomb)


# Checks whether different entities are affected
class gamePlay():
    # Checks whether bomber is hit by an explosion or an enemy
    def checkBomber(self, board, bomber):
        if board[bomber.location[0]][bomber.location[1]] > 1:
            return 1

    # Checks whether the enemy is hit by an explosion
    def checkEnemy(self, board, enemies):
        count = 0
        for enemy in enemies:
            if board[enemy.location[0]][enemy.location[1]] == 2:
                enemy.health -= 1
            if enemy.health == 0:
                enemies.remove(enemy)
                count += 5
        return count

    # Checks whether the blocks are hit by explosions
    def checkBlocks(self, board, blocks):
        count = 0
        for block in blocks:
            if board[block[0]][block[1]] == 2:
                blocks.remove(block)
                count += 1
        return count
