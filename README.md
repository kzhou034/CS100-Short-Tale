# Short Tale
 
Authors: [Joseph Hu](https://github.com/DooDooBard), [Kevin Pham](https://github.com/Kuvinn), [Kelley Zhou](https://github.com/kzhou034), and [Eric Hoang](https://github.com/Exeno2395)

## Project Description
Short Tale is a text-based RPG featuring a narrative and combat, interactable through keyboard inputs. The player is able to select from a small assortment of classes, which will offer different stats. During battles, stats for the player and enemy's health points will be displayed, and the choice to attack, heal, or run will be given. We're planning on a turn-based game, where different settings will be described with text and the story will be to go through levels and save a princess. We plan to implement a level system and skills to go along with different classes. This is a working project so we will most likely add more features as we complete the project.
 
This project will be created in C++, developed inside Hammer/Visual Studio Code.
 
As a group who shares common interest in video games, understanding and developing a basic game is a great experience to have, especially in the world of programming. By choosing this project we can express that interest, and learn from it.

## Class Diagram
The "Knight,""Mage,""Rogue," and "Enemy" classes inherit from the "Character" class. 

The "Enemy" class will be used to create the enemies that will appear on the different levels of the game. They can be different class types, like how the RPG player is able to choose between three class types when creating their player character. They will be created before the game starts. The RPG Player will not be able to create an Enemy as their player character. 

The "Knight,""Mage," and "Rogue" classes will be used to create the player character at the start of the game. Depending on which class the player chooses, they will have different player stats. Knights have balanced stats and they deal physical damage. Mages attack with magic, and their attacks deal magic damage. They have higher magic resistance but lower physical defense. Rogues have low defense and resistance stats. They deal physical damage, but less than a knight. They trade less damage in favor of higher speed, which allows them to attack first. They later unlock the ability to pick locks on chests. 

The "Knight" and "Rogue" classes both deal physical damage, meaning that the amount of damage that a foe would receive depends on the foe's defense stat. Mages deal magic damage, meaning the amount of damage a foe would receive depends on the foe's resistance stat. The same concept is applied when the player receive damage: if the enemy is of class "Knight" or "Rogue," the player receives physical damage, and the amount depends on the player's defense; and if the enemy is of the "Mage" class, the player receives magic damage, and the amount depends on the player's resistance. 

The "Knight,""Mage," and "Rogue" classes also have their own respective skills. For example, Knights can use shields which reduces the amount of damage they take, Mages can recover some of their health during battle (without the use of healing items), and Rogues can lower their opponent's defenses.

![UML_Character_Class drawio](https://user-images.githubusercontent.com/77300057/171787730-ca8b2680-127e-4963-9c0b-c64706faa1fd.png)
 
 ## Class Diagram 2 - Composite Design Pattern

The "Inventory" class will be used to create an inventory system in which players can interact with the interface to use healing items or battle items.

The "ActionItems" class will be used to select from two select items in the battle item inventory.

The "HealingItems" class will be used similarly to "Battle Items" (see above).

The "SmokeBomb" class will be used to guarantee running away from enemies.

The "StrengthPotion" class will be used to empower the player's attacks.

The "HealthPotion" class will be used to recover health for all classes.

![UML DIAGRAM_ INVENTORY COMPOSITE](https://user-images.githubusercontent.com/101243368/171780075-7f11245f-b7fb-40fc-bfb1-63f878096317.png)

Here, we used a composite design pattern to implement the entire inventory. The Inventory is interacted with by the player and will contain all of the other aspects, which are "contained" within the Inventory. The Inventory can exist without any of the following classes, by having an "empty" Inventory, but we have categorized items to exist within the Inventory and to be sorted by the type of items that they are are under the composite classes. In this way, we are able to better sort the inventory and allow item buying and selection to be a lot more manageable. This design pattern allows us to write better code because it gives us a better understanding of how the inventory to work and we can work around this pattern in consideration of how the Inventory should look like when it is fully developed.
 
 ## Screenshots
Character Creation:

<img width="407" alt="ShortTaleStart" src="https://user-images.githubusercontent.com/77300057/171938265-47e77a4c-3983-4265-996d-b011ec7d23a8.PNG">

<img width="411" alt="ShortTaleStart2" src="https://user-images.githubusercontent.com/77300057/171938288-7db74ab6-cb0c-46d1-81e9-9273dc5e3e85.PNG">

Stage 1/First Battle:

<img width="476" alt="ShortTaleStage1Text" src="https://user-images.githubusercontent.com/77300057/171938638-1ac6e480-ae8a-42a6-aed7-fcdf77b70856.PNG">

<img width="127" alt="ShortTaleBattle1" src="https://user-images.githubusercontent.com/77300057/171938650-0a7a4922-d42a-4392-88d9-9935468c978f.PNG">

<img width="136" alt="ShortTaleBattle2" src="https://user-images.githubusercontent.com/77300057/171938661-1116dcc6-f70e-4729-91e4-a55db53f92c1.PNG">

Level Up:

<img width="394" alt="ShortTaleLvlUp" src="https://user-images.githubusercontent.com/77300057/171938678-3eb27425-01b5-48ab-95e0-0f766d5ac3b3.PNG">

 ## Installation/Usage
 
 ### VSCode on Windows:
 Download the files (make sure all files are under the same folder). Then, open an integrated terminal for the folder and run:
 
 ```
 g++ main.cpp gamefunc.cpp
 ```
 
 This will general an executable called ```a.exe```. Run ```./a.exe``` in your terminal.
 
 ### Hammer:
 Clone the repository in hammer using 
 ```
 git clone --recursive https://github.com/cs100/final-project-jhu113_kzhou034_kpham130_ehoan011.git
 ```
 
 Then, run the commands:
 
 ```
 cmake3 .
 make
 ```
 The should generate an executable called ```./main```. Run that in your terminal. 
 
 ## Testing
 The functions were tested with the GoogleTest Framework as well as playing through the game ourselves multiple times to check for critical errors and bugs.
 
