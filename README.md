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

![UML_Diagram_Milestone2](https://user-images.githubusercontent.com/77300057/166176810-64571e86-c6ec-4864-bb83-5ddf4875bb00.png)
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 
