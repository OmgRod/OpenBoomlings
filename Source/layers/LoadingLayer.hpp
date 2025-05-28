#pragma once

#include "axmol.h"
#include <cstdlib>
#include <sys/timeb.h>
#include "../AppDelegate.h"
#include "axmol.h"
#include "renderer/backend/Enums.h"
#include "MenuLayer.hpp"
// #include "GameSoundManager.h"
// #include "GameKitManager.h"
// #include "GameStoreManager.h"
// #include "GameSocialManager.h"
// #include "GameStatsManager.h"
// #include "GameManager.h"
// #include "MoreGamesManager.h"
// #include "ObjectManager.h"
// #include "GameSaveManager.h"
// #include "GameAdManager.h"
// #include "GameSocialManager.h"
// #include "GameKitManager.h"
// #include "ContentManager.h"

using namespace ax;

class LoadingLayer : public Layer {
public:
    Sprite* m_sliderBar;
    bool m_showingLoadingString;
    Label* m_loadingLabel;
    float m_sliderBarScale;
    float m_sliderBarMaxWidth;

    bool init();
    const char* getLoadingString();
    static Scene* scene();
    static LoadingLayer* create();
    void updateProgress(int progress = 0);
    void loadAssets();
    void loadingFinished();
};