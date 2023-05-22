# Qt Match Game
**Emre Kılıç, Kristina Trajkovski**

## Introduction
Qt Match Game is a programming project written in Qt Framework of C++ by Emre Kılıç and Kristina Trajkovski in May 2023. It is designed as a desktop application which users can run on their system and see a graphical user interface (GUI).
Qt Match Game is played by clicking the buttons. The aim is finding 15 different button pairs and matching them. There is a limited number of moves and the user is expected to memorize the content of the buttons for matching.
We have designed the UI part in the QtCreator application and implemented the code part in C++ language.
## How To Play
* An executable is made by typing “make” into the terminal while in the appropriate folder.
* The executable is run by clicking it in file explorer or running the appropriate name in terminal (./pairs etc.). It is expected that an application window will appear.
* There are thirty blank buttons and an additional new game button. When you click on a blank button, its content will appear. You can click exactly 2 buttons in one move.
* The aim is finding all button pairs. You need to click the 2 matching buttons in the same move to gain a score. Then, these two buttons will disappear.
* The game will end when you match all pairs or run out of moves. You can see your score and leftover number of moves in the top left side of the window.
* There is a special reaction in the game. Play carefully to find it for more scores.
   
## Implementation
The implementation was done in QT Creator IDE. The IDE provides a user-friendly environment which makes the layout design very easy. All of the design parts are made in the QT Creator design tab. There are 31 buttons in total. One is for initiating a new game while the other 30 buttons are for the gameplay. In addition, there are three labels showing the current score, the number of moves remaining, and the ending status (“congratulations” or “game over”).
In the code part, two cpp source files are used in this project.
* `main.cpp` \
This is the starting point of the whole program. It instantiates the QApplication and
Mainwindow objects. After that, it executes the application.

* `mainwindow.cpp`\
This is where the whole program runs the game. This script has some global variables and Mainwindow class. Also there is a string array to hold the content of the buttons. The Mainwindow class has a custom constructor and 2 slot functions.
The new game button is connected to the slot function `onNewGameClicked` in the UI part of the implementation. In the code part, initially, the constructor of the Mainwindow class is run. It sets up the ui part and adds all game buttons into a buttongroup. Then, it connects the signal of when the button is clicked with the slot function `onButtonsClicked`. \
These two slot functions control the flow of the game. They use 4 integer and 1 boolean global variables to control the gameplay. The integer variables are state, score, counter and remainingMoves. The boolean variable is isActive. The functionality of these variables will be described in the slot functions.
    - `onButtonsClicked` \
This function is called when one of the 30 game buttons is clicked. It shows the content of the relevant button and disables it for blocking further clicks to the same button. It uses `isActive` boolean to check if the program is supposed to interpret this signal or not. If it is false then returns. If two cards are open, it decrements the `remainingMoves` by 1 and continues. \
It also uses the state variable to check whether another button is already opened or not. If the state is 0, that means no other button is opened before in that move. It sets the state to 1 and saves the button into a pointer for later comparisons. If the state is 1, there is already an open button and it is saved into a pointer. It sets `isActive` to false since we should not consider later clicks onto buttons for 0.7 seconds. After setting `isActive` to false, it calls `QTimer::singleshot` function to wait 0.7 seconds for the user to see the content of the second button.\
 While waiting 0.7 seconds, it compares the content of the last clicked button with the button which was saved into a pointer before. When there is no match, it closes the buttons and checks if `remainingMoves` is 0 or not. If it is 0, the game will be over and "_**Game Over**_" message is displayed. When there is a match, it hides the matched buttons and increments the counter variable by 1. Then, it checks if the counter is 15 or not. If it is 15, that means that all 15 pairs were found and the user has won the game. "_**Congratulations!**_" message is displayed.

    - `onNewGameClicked` :
This function is called when the new game button is clicked. It basically resets the game. It sets all integer variables to 0 except the `remainingMoves`. `remainingMoves` is set to 50. It uses a default random function to shuffle the array that holds the content of the buttons. After that, it unhides all buttons and the game is simply reset.
## Difficulties Encountered and Improvements
The first difficulty encountered was related to the grid layout. In class, we were given a hint that we could use a grid to evenly distribute the buttons. However, since we wanted the buttons to disappear after finding a pair (since most games online function like that and it just looks nicer) after a column or a row disappeared the grid would rearrange the cards. Of course, from the nature of the game, this bug makes it very hard to play. It is a default behavior and a solution for that was either giving up on disappearing cards or the grid. We decided on giving up on the grid in order to keep the game more user friendly, and all buttons are actually placed individually.\

One of the major bugs in the game was related to the timer. After two different cards are open, we are supposed to show them to the user for some amount of time for him/her to have a chance to memorize and close them up again. The cards are going to freeze for 0.7 seconds (the length is determined by trial and error, it just seemed as the best fit) and close back up. However, within those 0.7 seconds any additional click would cause random behavior - the number of moves would decrease no matter the cards open. We fixed that by adding a flag which would discard any click within the 0.7 seconds. All the buttons seem enabled, but the game stops and the clicks will have no effect at all.\

Something that needs improvement is the button layout and their inclusion in the user interface. As mentioned above, right now we have 30 individual buttons as cards. They are a part of a single group used later in the implementation, but they were added to the group one by one. They could have been stored as an array, which would definitely make their usage in code easier, but that would make the design of the page more difficult. At this moment, it was easier to use the IDE just like any other design we did before (paint, PowerPoint etc.) and include the buttons in code, even if that makes the code longer.

## Conclusion
This was the first project that we did in our department where the input was not a text file nor a textual user input from the terminal, but clicks and buttons. It introduced us to a graphical user interface which is very useful in today’s coding market. The design and implementation were left for us to decide, so we even had fun with choosing the design, the text written in cards, and we even included an easter egg which is always exciting when playing a game.

