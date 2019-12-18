# Battle-City
(*Both my childhood memories and the beginning of my career*)
## 1.Configuration
1. Download and extract the files.  
2. Go to the official website of EasyX and download (Click ***下载 EasyX***) the EasyX plugin. ( EasyX Website : ***https://easyx.cn/*** )  
3. Open the plug-in and select the Visual Studio compiler you need to install. ( ***Visual Studio 2019*** is recommended )  
4. Then you can open this file to check  
## 2.Game guide
1. You can check the ***User Guide*** in the file to understand the game operation.  
2. The initial health value of the game is 5; the initial number of enemies is 10; 10 points are scored for each enemy killed; 
5 points are increased for each level increase; a health value is obtained for every 500 points; 
a super weapon will appear in the third level to obtain Can be used later.  
3. All the above can be changed in ***Setting.CPP***.
4. I set the refresh rate of the game to refresh every 30 milliseconds, and you can see it in line ***352*** of the ***main.CPP*** file. 
If you feel too fast, you can increase the value in ***Sleep ()*** appropriately.  
5. Other files are marked with comments, you can click on other header files or source files to view.  
## 3.Design idea
This game is the end of the course in ***Practice Design***. The teacher did not specify any content, 
as long as we use C ++ to implement a complete interactive system, 
which can be a console program or an APP with a graphical interface.
Because of the love of the game, I thought of implementing a Battle City that was designed using other graphical interfaces.
A graphical interface such as ***EasyX*** was found midway, which was more convenient to use. The game referenced some tutorials, 
and encountered a lot of trouble midway through, but it was finally resolved, 
and the super weapon has the feel of a ***Striker 1945*** in the way of moving props.
I really realized the power of C ++ object-oriented programming in this project. 
In my process of writing games using ***EasyX***, the concept seemed similar to using a game engine.
The model of the tank and the model of the bullet are all drawn using the ***EasyX*** graphics library, 
and their related attributes are stored separately. In the ***Untiy*** engine, similar concepts are everywhere. 
Any model has a basic attribute, which is ***Position***, 
and the designer can add any attribute such as ***Rigidbody*** to him according to the content of the game.
This separate management is convenient for modifying the code. When we make a mistake in one place, 
we don't need to change all the code, we just need to modify the error location.
This kind of programming thinking is the best thing I got in this project.
So a game engine is software that integrates everything and presents it graphically. 
Different types of games or different game design goals require different engine components. 
Therefore, large studios will design their own engines to make targeted games. 
Game engines such as ***Unity*** and ***Unreal*** integrate most of the game design content, 
which can meet the design and development of almost any type of game, but the focus is different, 
or the targeting and efficiency are not so high. So in this game, 
I will design the components I need, and call the designed components directly when needed. 
Even if there is a problem in the middle, we only need to find the problem point without redesigning the entire content.

At last, hope you enjoy this project and have fun.
