#pragma once

#include "axmol.h"

using namespace ax;

class MenuLayer : public Layer {
public:
    bool init();
    void menuRobtopCallback();
    void menuFeedbackCallback();
    void menuDailyCallback();
    void menuRateCallback();
    void menuMoreGamesCallback();
    static MenuLayer* create();
    static Scene* scene();
};