#include "axmol.h"

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
};