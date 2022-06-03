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

The "Battle Items" class will be used to select from two select items in the battle item inventory.

The "Healing Items" class will be used similarly to "Battle Items" (see above).

The "Smoke Bomb" class will be used to guarantee running away from enemies.

The "Strength Potion" class will be used to empower the player's attacks.

The "Mana Potion" class will be used to recover mana for mages.

The "Health Potion" class will be used to recover health for all classes.

![UML DIAGRAM_ INVENTORY COMPOSITE](https://user-images.githubusercontent.com/101243368/171780075-7f11245f-b7fb-40fc-bfb1-63f878096317.png)

Here, we used a composite design pattern to implement the entire inventory. The Inventory is interacted with by the player and will contain all of the other aspects, which are "contained" within the Inventory. The Inventory can exist without any of the following classes, by having an "empty" Inventory, but we have categorized items to exist within the Inventory and to be sorted by the type of items that they are are under the composite classes. In this way, we are able to better sort the inventory and allow item buying and selection to be a lot more manageable. This design pattern allows us to write better code because it gives us a better understanding of how the inventory to work and we can work around this pattern in consideration of how the Inventory should look like when it is fully developed.
 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
