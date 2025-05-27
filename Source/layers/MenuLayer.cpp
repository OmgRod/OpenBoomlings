#include "axmol.h"
#include "layers/MenuLayer.hpp"

using namespace ax;

bool MenuLayer::init() {
    Object* in_r0;
    float fVar3;
    float fVar4;
    int* piVar5;
    undefined4 uVar6;
    Node* pCVar7;
    MenuItem* pCVar8;
    int* piVar9;
    ActionInterval* pCVar10;
    FiniteTimeAction* pCVar11;
    code* pcVar12;
    float extraout_s0;
    float extraout_s0_00;
    float extraout_s0_01;
    float extraout_s0_02;
    float extraout_s0_03;
    float extraout_s1;
    float extraout_s1_00;
    undefined8 uVar13;
    float extraout_s1_01;
    undefined1 auStack_204[4];
    undefined1 auStack_200[4];
    undefined4 uStack_1fc;
    code* pcStack_1f8;
    undefined4 uStack_1f4;
    code* pcStack_1f0;
    undefined4 uStack_1ec;
    code* pcStack_1e8;
    undefined4 uStack_1e4;
    code* pcStack_1e0;
    undefined4 uStack_1dc;
    code * pcStack_1d8;
    undefined4 uStack_1d4;
    Size aCStack_1d0[32];
    Point aCStack_1b0[32];
    Point aCStack_190[32];
    Point aCStack_170[32];
    Point aCStack_150[32];
    Point aCStack_130[32];
    Point aCStack_110[32];
    Point aCStack_f0[32];
    Point aCStack_d0[32];
    Point aCStack_b0[32];
    Point aCStack_90[32];
    Point aCStack_70[32];
    Point aCStack_50[32];

    if (Layer::init()) {

        this::setKeypadEnabled(true);

        auto gm = GameManager::sharedState();
        auto dir = Director::getInstance();
        auto winSize = dir->getWinSize();

        piVar2 = (int * ) Sprite::create("images/menuSheet/MainMenuBG_001.png");
        pcVar12 = * (code ** )( * piVar2 + 0x4c);
        Point::Point(aCStack_1b0, extraout_s0, extraout_s1);
        ( * pcVar12)(piVar2, aCStack_1b0);
        Point::~Point(aCStack_1b0);
        ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar2 + 0x150);
        iVar1 = Director::sharedDirector();
        fVar3 = (float)( ** (code ** )( ** (int ** )(iVar1 + 0x30) + 0x34))();
        iVar1 = Director::sharedDirector();
        fVar4 = (float)( ** (code ** )( ** (int ** )(iVar1 + 0x30) + 0x30))();
        ( * pcVar12)(piVar2, fVar3 / fVar4);
        piVar2 = (int * ) Sprite::create("images/menuSheet/boomlingslogo.png");
        pcVar12 = * (code ** )( * piVar2 + 0x4c);
        Point::Point(aCStack_190, extraout_s0_00, extraout_s1_00);
        ( * pcVar12)(piVar2, aCStack_190);
        Point::~Point(aCStack_190);
        ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        piVar5 = (int * ) ParticleSystemQuad::particleWithFile("glitterEffect.plist");
        ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar5 + 0x4c);
        uVar6 = ( ** (code ** )( * piVar2 + 0x48))(piVar2);
        ( * pcVar12)(piVar5, uVar6);
        setupMenuButtons();
        pCVar7 = (Node * ) Sprite::createWithSpriteFrameName("robtoplogo_small.png");
        uStack_1f4 = 0;
        pcStack_1f8 = (code * ) 0x10c3f5;
        pCVar8 = (MenuItem * )
        MenuItemSpriteExtra::create(pCVar7, (Node * ) 0x0, in_r0, (_func_void_Object_ptr * ) 0x10c3f5);
        piVar5 = (int * ) Menu::menuWithItems(pCVar8, 0);
        uVar13 = ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar5 + 0x4c);
        Point::Point(aCStack_170, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar5, aCStack_170);
        Point::~Point(aCStack_170);
        pCVar7 = (Node * ) Sprite::createWithSpriteFrameName("feedbackBtn_001.png");
        uStack_1ec = 0;
        pcStack_1f0 = (code * ) 0x10c3d1;
        pCVar8 = (MenuItem * )
        MenuItemSpriteExtra::create(pCVar7, (Node * ) 0x0, in_r0, (_func_void_Object_ptr * ) 0x10c3d1);
        piVar5 = (int * ) Menu::menuWithItems(pCVar8, 0);
        uVar13 = ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar5 + 0x4c);
        Point::Point(aCStack_150, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar5, aCStack_150);
        Point::~Point(aCStack_150);
        piVar9 = (int * ) Sprite::createWithSpriteFrameName("hello_001.png");
        uVar13 = ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar9 + 0x4c);
        Point::Point(aCStack_130, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar9, aCStack_130);
        Point::~Point(aCStack_130);
        piVar9 = (int * ) Sprite::createWithSpriteFrameName("feedback_001.png");
        ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar9 + 0x4c);
        ( ** (code ** )( * piVar5 + 0x48))(piVar5);
        uVar13 = ( ** (code ** )( * piVar5 + 0x48))(piVar5);
        Point::Point(aCStack_110, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar9, aCStack_110);
        Point::~Point(aCStack_110);
        piVar5 = (int * ) Menu::create();
        ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pCVar7 = (Node * ) Sprite::createWithSpriteFrameName("dailyBtn_001.png");
        uStack_1e4 = 0;
        pcStack_1e8 = (code * ) 0x10c415;
        uVar6 = MenuItemSpriteExtra::create(pCVar7, (Node * ) 0x0, in_r0, (_func_void_Object_ptr * ) 0x10c415);
        ( ** (code ** )( * piVar5 + 0xec))(piVar5, uVar6);
        pcVar12 = * (code ** )( * piVar5 + 0x4c);
        uVar13 = ( ** (code ** )( * piVar2 + 0x48))(piVar2);
        Point::Point(aCStack_f0, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar5, aCStack_f0);
        uVar13 = Point::~Point(aCStack_f0);
        pCVar10 = (ActionInterval * )
        ScaleTo::create((float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        pCVar11 = (FiniteTimeAction * ) EaseInOut::create(pCVar10, extraout_s0_01);
        pCVar10 = (ActionInterval * ) ScaleTo::create(extraout_s0_02, extraout_s1_01);
        uVar6 = EaseInOut::create(pCVar10, extraout_s0_03);
        pCVar10 = (ActionInterval * ) Sequence::create(pCVar11, uVar6, 0);
        RepeatForever::create(pCVar10);
        Node::runAction((Action * ) pCVar7);
        pCVar7 = (Node * ) Sprite::createWithSpriteFrameName("rateBtn_001.png");
        uStack_1dc = 0;
        pcStack_1e0 = (code * ) 0x10c1bf;
        pCVar8 = (MenuItem * )
        MenuItemSpriteExtra::create(pCVar7, (Node * ) 0x0, in_r0, (_func_void_Object_ptr * ) 0x10c1bf);
        uVar6 = Menu::menuWithItems(pCVar8, 0);
        *(undefined4 * )(in_r0 + 0x15c) = uVar6;
        uVar13 = ( ** (code ** )( * (int * ) in_r0 + 0xec))();
        piVar2 = * (int ** )(in_r0 + 0x15c);
        pcVar12 = * (code ** )( * piVar2 + 0x4c);
        Point::Point(aCStack_d0, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar2, aCStack_d0);
        Point::~Point(aCStack_d0);
        uVar6 = Sprite::createWithSpriteFrameName("rate_001.png");
        *(undefined4 * )(in_r0 + 0x158) = uVar6;
        ( ** (code ** )( * (int * ) in_r0 + 0xec))();
        piVar2 = * (int ** )(in_r0 + 0x158);
        pcVar12 = * (code ** )( * piVar2 + 0x4c);
        ( ** (code ** )( ** (int ** )(in_r0 + 0x15c) + 0x48))();
        uVar13 = ( ** (code ** )( ** (int ** )(in_r0 + 0x15c) + 0x48))();
        Point::Point(aCStack_b0, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar2, aCStack_b0);
        uVar13 = Point::~Point(aCStack_b0);
        fVar3 = (float) Point::Point(aCStack_90, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        pCVar10 = (ActionInterval * ) MoveBy::actionWithDuration(fVar3, (Point * ) 0x3f800000);
        fVar3 = (float) Point::~Point(aCStack_90);
        pCVar11 = (FiniteTimeAction * ) EaseInOut::actionWithAction(pCVar10, fVar3);
        uVar6 = ( ** (code ** )( * (int * ) pCVar11 + 0x34))();
        pCVar10 = (ActionInterval * ) Sequence::actions(pCVar11, uVar6, 0);
        RepeatForever::actionWithAction(pCVar10);
        Node::runAction( * (Action ** )(in_r0 + 0x158));
        piVar2 = (int * ) GameManager::sharedState();
        iVar1 = ( ** (code ** )( * piVar2 + 0x280))();
        if (iVar1 != 0) {
            piVar2 = (int * ) GameManager::sharedState();
            pcVar12 = * (code ** )( * piVar2 + 0x224);
            FUN_0029f158(auStack_200, "Player", auStack_204);
            ( * pcVar12)(piVar2, auStack_200);
            FUN_0029d9dc(auStack_200);
            AppDelegate::showLoadError();
        }
        GameManager::sharedState();
        GameManager::showMainMenuAd();
        pCVar7 = (Node * ) Sprite::create("images/moreGamesBtn_001.png");
        uStack_1d4 = 0;
        pcStack_1d8 = (code * ) 0x10c27b;
        pCVar8 = (MenuItem * )
        MenuItemSpriteExtra::create(pCVar7, (Node * ) 0x0, in_r0, (_func_void_Object_ptr * ) 0x10c27b);
        piVar2 = (int * ) Menu::create(pCVar8, 0);
        uVar13 = ( ** (code ** )( * (int * ) in_r0 + 0xf0))();
        pcVar12 = * (code ** )( * piVar2 + 0x4c);
        Point::Point(aCStack_70, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
        ( * pcVar12)(piVar2, aCStack_70);
        Point::~Point(aCStack_70);
        piVar2 = (int * ) MoreGamesManager::sharedState();
        iVar1 = ( ** (code ** )( * piVar2 + 0x130))();
        if (iVar1 != 0) {
            piVar2 = (int * ) Sprite::create("images/BoomUISheet/exMark_001.png");
            uVar13 = ( ** (code ** )( * (int * ) pCVar7 + 0xec))(pCVar7, piVar2);
            pcVar12 = * (code ** )( * piVar2 + 0x4c);
            Point::Point(aCStack_50, (float) uVar13, (float)((ulonglong) uVar13 >> 0x20));
            ( * pcVar12)(piVar2, aCStack_50);
            Point::~Point(aCStack_50);
        }
        ( ** (code ** )( * gm + 0x210))( & uStack_1fc, gm);
        Log("%s", uStack_1fc);
        FUN_0029d9dc( & uStack_1fc);
        Size::~Size(aCStack_1d0);
    }
    return true;
}