# Q-Engine

## Introduction

Q-Engine is a simple 2D Game Engine built during my spare time. It's written in C++ and makes use of the SDL2 library.  

The essentials for the engine were built over the first 3 weeks. After that I have tried to push small weekly update.


## Example Games
I created several small games during development to help which also help test parts of the engine. They also helped me decide what to work on next. Coming Soon - Pics + Repo

### Space Game

### Topdown Shooter

### Physics Playground


## Using the Engine

### Core

#### Managers
- AudioManager - Load, store and play sound effects and music
- EventManager - Automatically updates key and mouse states and handles window events
- InputManager - Access to key states and mouse information
- ResourceManager - Load, store and manage Textures
- FontManager - Load, store and manage Fonts

#### Core classes
After Initialization these files are never used directly, only via other classes.
- Window - Creates a Window
- Renderer - Creates a renderer for texture and primitives
- Texture - Creates a Texture
- IOManager - Functions to load various file types


#### Miscellaneous
- Camera - Convert to and from world and screen coordinates and set render scale. Perform camera culling to reduce textures rendered.
- Timer - FPS Counter and functions for timestep. Also includes multiple purpose timer class
- MainGame - Virtual class provides structure for a game. Game inherits and overrides virtual functions, can be run simply with `run()`


### Data
Contains basic structs including `keyCodes` used to identify keyboard and mouse inputs.


### Render
Contains higher level classes for rendering textures including sprite and font rendering. Also contains functions to render primitives (lines and rectangles).

**Fonts:** Multiple fonts and different sizes can be loaded into the `FontManager`. Text can be rendered on screen using the selected font and color.

**Sprites:** Individual Sprites can be loaded from parts of textures. Sprites can be grouped together in a `SpriteGroup` which allows multiple variants or animations to be added to objects.


## Physics

### Body
A Body has a position, velocity and mass and contains functions to have a force applied and also friction. (Future Update: Improved acceleration calculations and more built in physics eqauations)  
Bodies can contain multiple AABB (Axis-Aligned minimum Bounding Box) or circle colliders for collision dectection. This allows the body collisions to more closely follow the body/sprites shape.

### Hitscan
This is a class designed for hitscan projectiles, it contains functions for Line collisions. 

### Collisions
Collisions can be detected between:
- AABB AABB
- AABB Circle
- Circle Circle
- Line AABB
- Line Circle
(Future Update: Line Line)

Depending on the type, collision data can be retrived for a successful collision including point of the collision, depth and direction. This could be used in further calculations for deflections etc.


