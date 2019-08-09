# Group-Chat-Message-Analyzer

A program that analyzes a group chat to calculate chat participation and unique word counts per user.

Program accepts a .txt/.csv as file input. The first field of each line will be a phone number up to the delimiter "|".
Each group chat participant is represented with a class object that stores the words typed by that user into a BST.
Words may then be searched to show how many occurances of the word have been said be each user.
