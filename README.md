 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Sploosh Kaboom
 
 > [Jerry Xu](https://github.com/jerryxu158), [Kevin Gao](https://github.com/kevincakey), [Roz Teves](https://github.com/rozteves)
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Strategy, Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
       > * We wanted to recreate Sploosh Kaboom from the Legend of Zelda game in our own way for fun and to try out the video game development process.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [toolname](link) - Short description
           > * Language: C++ Tools: Hammer/Putty, Some sort of visualization GUI
 > * What will be the input/output of your project?
          > * Mouse click/arrow keys from the user, Output: some sort of visual indication/increase in point system/reward screen for the user when winning
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
> * Factory method: 3 separate tile states: untouched, hit, miss. Using the factory method we could generate different types of tiles as indicators of how the user has       interacted with the tiles, as well as implementing a mechanic that causes the user to change their game-play strategy based on effects they get from different tiles. This method could also be included in making different types of enemies to hit that influence the game in different ways, but have a general commanlity such as an amount of health, armor, size, etc. We picked this pattern because with what we intend to use it for, the creation of entities within our game will be more efficient and the code will be more organized.
> * Strategy: We picked strategy because we wanted a design pattern that could help us alter the game's experience. With this design pattern, we could manipulate the   size of tiles, size of enemies, number of enemies, number of user shots, or we could include/remove obstacles and events that could hinder/boost user advantage. We could implement a change in board size, for example, with a 2-dimensional array or a double Linked-list.
> * Iterator: We picked iterator as our third design pattern. The iterator design pattern will detect and alert the user if a tile was a miss or a hit. Value of hit or miss will change or assign the targeted tile's status of untouched to another value. Example: untouched=0, hit=1, miss=2.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 Strategy pattern
 
 ![strategy classes](https://i.imgur.com/h6jMNGa.png)
 
 ![factory method](https://i.imgur.com/NwzZUcT.png)
 
 iterator
 
![visitor](https://i.imgur.com/9hXLTEk.png)
 
 > ## Phase III
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
![start of game](https://i.imgur.com/hF7MWP8.png)
![example of a defeat](https://i.imgur.com/8ziji8B.png)
 ## Installation/Usage
download and run the main.cpp file within the src file.
 ## Testing
Due to the game's natured of being a randomly generated location, we had to test through a developer mode showing the locations and ensuring that hits were registered properly. Each person's code was tested indepedently to ensure that it was working as intended. We then combined the code through a common interface and tested that to ensure that it worked properly.  
 
