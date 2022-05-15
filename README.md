# Short Tale
 
 Authors: [Joseph Hu](https://github.com/DooDooBard), [Kevin Pham](https://github.com/Kuvinn), [Kelley Zhou](https://github.com/kzhou034), and [Eric Hoang](https://github.com/Exeno2395)

## Project Description
 Short Tale is a text-based RPG featuring a narrative and combat, interactable through keyboard inputs. The player is able to select from a small assortment of classes, which will offer different stats. During battles, stats for the player and enemy's health points will be displayed, and the choice to attack, heal, or run will be given. We're planning on a turn-based game, where different settings will be described with text and the story will be to go through levels and save a princess. We plan to implement a level system and skills to go along with different classes. This is a working project so we will most likely add more features as we complete the project.
 
 This project will be created in C++, developed inside Hammer/Visual Studio Code.
 
 As a group who shares common interest in video games, understanding and developing a basic game is a great experience to have, especially in the world of programming. By choosing this project we can express that interest, and learn from it.

## Class Diagram
Both "Player" and "Enemy" classes inherit from the "Character" class. The "Knight,""Mage," and "Rogue" classes inherit from the "Player" class, and are among the classes the player cane choose from when they start the game. 

The "Enemy" class will be used to create the enemies that will appear on the different levels of the game. They will be created before the game starts.

The "Player" class will be used to create the player character at the start of the game. Depending on which class the player chooses, they will have different stats. Knights have balanced stats; they deal physical damage and are limited by their stamina. Mages attack with magic, but their attacks are limited by how much mana they have. They have higher magic resistance but lower physical defense. Rogues have low defense and resistance stats. They deal physical damage, but less than a knight. They trade less damage in favor of higher speed, which allows them to attack first or run away during battle. They later unlock the ability to pick locks on doors. 

![Updated_UML _Composite_Character drawio (1)](https://user-images.githubusercontent.com/77300057/168492580-58d385f3-576f-42be-8b36-c0c1ebb527e9.png)
 
Here, we used a composite design pattern to help implement the Enemy class. The Enemy class differs from the other three because the "Enemy" role is not a role that the player can choose when creating their character. There will be a vector that stores the enemies as Character objects, and a different enemy will be used for each level. The design pattern helps to write better code because it allows us to separate the different classes and see how they are different or similar. It also allows us to direct our focus on certain aspects of each class, such as skills or differences in character statistics.
 
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
 
