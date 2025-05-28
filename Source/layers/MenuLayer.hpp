#pragma once

#include "axmol.h"
#include "axmodify/MenuItemSpriteExtra.hpp"
// #include "SimpleGamePiece.hpp"

using namespace ax;

class MenuLayer : public Layer {
public:
    // SimpleGamePiece* blockR;
    // SimpleGamePiece* blockG;
    // SimpleGamePiece* blockB;
    // SimpleGamePiece* blockY;

    bool init();
    void menuRobtopCallback();
    void menuFeedbackCallback();
    void menuDailyCallback();
    void menuRateCallback();
    void menuMoreGamesCallback();
    static MenuLayer* create();
    static Scene* scene();
    void setupMenuButtons();
    void onPlayClicked();
    void onStoreClicked();
    void onExtrasClicked();
    void onFreeGoldClicked();
};