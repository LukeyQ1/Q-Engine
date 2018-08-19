//
//  MainGame.cpp
//  Q-Test
//
//  Created by Luke Quinlan on 14/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "MainGame.hpp"

MainGame::MainGame(std::string screenName, int screenWidth, int screenHeight, float maxFps){
    SCREEN_WIDTH = screenWidth;
    SCREEN_HEIGHT = screenHeight;
    maxFPS = maxFps;

    init();
    window.init("Physics Playground", SCREEN_WIDTH, SCREEN_HEIGHT);
    renderer.init(window);
    AM.init();
    CAM.init(SCREEN_WIDTH, SCREEN_HEIGHT);
}
MainGame::~MainGame(){
    RM.quit();
    window.quit();
    renderer.quit();
    quit();
}

void MainGame::run(){
    if(!loadAssets()){
        printf( "Failed to load assets!\n" ); return;
    }
    setup();

    FPS.init(maxFPS);
        while( !EM.checkQuit() ){
            FPS.start();
            // Process Inputs
            EM.updateState();

            // Process Updates
            float totalTime = FPS.getDeltaTime();
            float maxStep = FPS.getMaxDeltaTime();
            while(totalTime > 0.0){
                float deltaTime = std::min(totalTime,maxStep);

                update(deltaTime);

                totalTime -= deltaTime;
            }
            update();

            // Render
            renderer.clear();
            renderer.setColor(0xFF, 0xFF, 0xFF, 0xFF );

            draw();

            renderer.update();

            IM.update();
            FPS.update();
        }
    onQuit();
}
