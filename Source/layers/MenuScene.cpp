#include "MenuLayer.hpp"

using namespace ax;

bool MenuLayer::init() {
  uStack_14 = 0x108609;
  cVar7 = Layer::init((Layer *)this);
  if (!Scene::init()) {
    return false;
  }
  Layer::setKeypadEnabled(SUB41(this,0));
  auto gm = GameManager::sharedState();
  (**(code **)(*piVar8 + 0x13c))(piVar8,1);
  auto dir = Director::getInstance();
  auto winSize = dir->getWinSize();
  piVar8 = Sprite::createWithSpriteFrameName("");
  pcVar6 = *(code **)(*piVar8 + 0x4c);
  Point::Point
            ((Point *)aiStack_19c,*(float *)(unaff_EBX + 0x333adb) * local_1a4,
             *(float *)(unaff_EBX + 0x333adb) * local_1a0);
  (*pcVar6)(piVar8,(Point *)aiStack_19c);
  iVar1 = *(int *)(
                  "..."
                  + unaff_EBX + 0x72f) + 8;
  aiStack_19c[0] = iVar1;
  Object::~Object((Object *)aiStack_19c);
  (**(code **)(*(int *)this + 0xf0))(this,piVar8,0);
  pcVar6 = *(code **)(*piVar8 + 0x150);
  iVar9 = Director::getInstance();
  lVar19 = (longdouble)(**(code **)(**(int **)(iVar9 + 0x30) + 0x34))(*(int **)(iVar9 + 0x30));
  iVar9 = Director::getInstance();
  lVar20 = (longdouble)(**(code **)(**(int **)(iVar9 + 0x30) + 0x30))(*(int **)(iVar9 + 0x30));
  (*pcVar6)(piVar8,(float)lVar19 / (float)lVar20);
  piVar8 = (int *)Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x3065b6));
  fVar2 = *(float *)(unaff_EBX + 0x333ae7);
  pcVar6 = *(code **)(*piVar8 + 0x4c);
  Point::Point
            ((Point *)aiStack_17c,*(float *)(unaff_EBX + 0x333adb) * local_1a4,local_1a0 - fVar2);
  (*pcVar6)(piVar8,(Point *)aiStack_17c);
  aiStack_17c[0] = iVar1;
  Object::~Object((Object *)aiStack_17c);
  (**(code **)(*(int *)this + 0xf0))(this,piVar8,2);
  piVar10 = (int *)ParticleSystemQuad::particleWithFile((char *)(unaff_EBX + 0x3065c8));
  (**(code **)(*(int *)this + 0xf0))(this,piVar10,1);
  pcVar6 = *(code **)(*piVar10 + 0x4c);
  uVar11 = (**(code **)(*piVar8 + 0x48))(piVar8);
  (*pcVar6)(piVar10,uVar11);
  setupMenuButtons(this);
  pCVar12 = (Node *)Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x3065dc));
  p_Var22 = *(_func_void_Object_ptr **)
             (
             "..."
             + unaff_EBX + 0x777);
  uVar11 = 0;
  pMVar21 = this;
  pCVar13 = (MenuItem *)
            MenuItemSpriteExtra::create(pCVar12,(Node *)0x0,(Object *)this,p_Var22);
  piVar10 = (int *)Menu::menuWithItems(pCVar13,0,pMVar21,p_Var22,uVar11);
  (**(code **)(*(int *)this + 0xf0))(this,piVar10,2);
  pcVar6 = *(code **)(*piVar10 + 0x4c);
  Point::Point
            ((Point *)aiStack_15c,
             *(float *)(unaff_EBX + 0x333adb) * local_1a4 - *(float *)(unaff_EBX + 0x333aeb),30.0);
  (*pcVar6)(piVar10,(Point *)aiStack_15c);
  aiStack_15c[0] = iVar1;
  Object::~Object((Object *)aiStack_15c);
  pCVar12 = (Node *)Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x3065f1));
  p_Var22 = *(_func_void_Object_ptr **)
             (
             "..."
             + unaff_EBX + 0x77b);
  uVar11 = 0;
  pMVar21 = this;
  pCVar13 = (MenuItem *)
            MenuItemSpriteExtra::create(pCVar12,(Node *)0x0,(Object *)this,p_Var22);
  piVar10 = (int *)Menu::menuWithItems(pCVar13,0,pMVar21,p_Var22,uVar11);
  (**(code **)(*(int *)this + 0xf0))(this,piVar10,2);
  fVar3 = *(float *)(unaff_EBX + 0x333aef);
  pcVar6 = *(code **)(*piVar10 + 0x4c);
  Point::Point
            ((Point *)aiStack_13c,*(float *)(unaff_EBX + 0x333adb) * local_1a4 - fVar3,80.0);
  (*pcVar6)(piVar10,(Point *)aiStack_13c);
  aiStack_13c[0] = iVar1;
  Object::~Object((Object *)aiStack_13c);
  piVar14 = (int *)Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x306605));
  (**(code **)(*(int *)this + 0xf0))(this,piVar14,1);
  pcVar6 = *(code **)(*piVar14 + 0x4c);
  Point::Point
            ((Point *)aiStack_11c,
             *(float *)(unaff_EBX + 0x333adb) * local_1a4 - *(float *)(unaff_EBX + 0x333af3),20.0);
  (*pcVar6)(piVar14,(Point *)aiStack_11c);
  aiStack_11c[0] = iVar1;
  Object::~Object((Object *)aiStack_11c);
  piVar14 = (int *)Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x306613));
  (**(code **)(*(int *)this + 0xf0))(this,piVar14,1);
  pcVar6 = *(code **)(*piVar14 + 0x4c);
  iVar9 = (**(code **)(*piVar10 + 0x48))(piVar10);
  fVar4 = *(float *)(iVar9 + 0x1c);
  fVar5 = *(float *)(unaff_EBX + 0x333af7);
  iVar9 = (**(code **)(*piVar10 + 0x48))(piVar10);
  Point::Point
            ((Point *)aiStack_fc,*(float *)(unaff_EBX + 0x333afb) + *(float *)(iVar9 + 0x18),
             fVar4 - fVar5);
  (*pcVar6)(piVar14,(Point *)aiStack_fc);
  aiStack_fc[0] = iVar1;
  Object::~Object((Object *)aiStack_fc);
  piVar10 = (int *)Menu::create();
  (**(code **)(*(int *)this + 0xf0))(this,piVar10,4);
  pCVar12 = (Node *)Sprite::createWithSpriteFrameName((char *)(unaff_EBX + 0x306624));
  p_Var22 = *(_func_void_Object_ptr **)
             (
             "..."
             + unaff_EBX + 0x77f);
  uVar23 = 0;
  pMVar21 = this;
  uVar11 = MenuItemSpriteExtra::create(pCVar12,(Node *)0x0,(Object *)this,p_Var22);
  (**(code **)(*piVar10 + 0xec))(piVar10,uVar11,pMVar21,p_Var22,uVar23);
  pcVar6 = *(code **)(*piVar10 + 0x4c);
  iVar9 = (**(code **)(*piVar8 + 0x48))(piVar8);
  Point::Point
            ((Point *)aiStack_dc,
             *(float *)(unaff_EBX + 0x333adb) * local_1a4 + *(float *)(unaff_EBX + 0x333aff),
             *(float *)(iVar9 + 0x1c) - fVar2);
  (*pcVar6)(piVar10,(Point *)aiStack_dc);
  aiStack_dc[0] = iVar1;
  Object::~Object((Object *)aiStack_dc);
  pCVar15 = (ActionInterval *)ScaleTo::create(0.5,1.05);
  pCVar16 = (Sequence *)EaseInOut::create(pCVar15,2.0);
  pCVar15 = (ActionInterval *)ScaleTo::create(0.5,0.95);
  pCVar17 = (FiniteTimeAction *)EaseInOut::create(pCVar15,2.0);
  pCVar15 = (ActionInterval *)Sequence::create(pCVar16,pCVar17,0);
  pCVar18 = (Action *)RepeatForever::create(pCVar15);
  Node::runAction(pCVar12,pCVar18);
  pCVar12 = (Node *)Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x306635));
  p_Var22 = *(_func_void_Object_ptr **)
             (
             "..."
             + unaff_EBX + 0x783);
  uVar11 = 0;
  pMVar21 = this;
  pCVar13 = (MenuItem *)
            MenuItemSpriteExtra::create(pCVar12,(Node *)0x0,(Object *)this,p_Var22);
  uVar11 = Menu::menuWithItems(pCVar13,0,pMVar21,p_Var22,uVar11);
  *(undefined4 *)(this + 0x15c) = uVar11;
  (**(code **)(*(int *)this + 0xec))(this,uVar11);
  pcVar6 = *(code **)(**(int **)(this + 0x15c) + 0x4c);
  Point::Point
            ((Point *)aiStack_bc,*(float *)(unaff_EBX + 0x333adb) * local_1a4 + fVar3,30.0);
  (*pcVar6)(*(undefined4 *)(this + 0x15c),(Point *)aiStack_bc);
  aiStack_bc[0] = iVar1;
  Object::~Object((Object *)aiStack_bc);
  uVar11 = Sprite::spriteWithSpriteFrameName((char *)(unaff_EBX + 0x306645));
  *(undefined4 *)(this + 0x158) = uVar11;
  (**(code **)(*(int *)this + 0xec))(this,uVar11);
  pcVar6 = *(code **)(**(int **)(this + 0x158) + 0x4c);
  iVar9 = (**(code **)(**(int **)(this + 0x15c) + 0x48))(*(int **)(this + 0x15c));
  fVar2 = *(float *)(iVar9 + 0x1c);
  iVar9 = (**(code **)(**(int **)(this + 0x15c) + 0x48))(*(int **)(this + 0x15c));
  Point::Point
            ((Point *)aiStack_9c,*(float *)(iVar9 + 0x18) - *(float *)(unaff_EBX + 0x333b03),fVar2
            );
  (*pcVar6)(*(undefined4 *)(this + 0x158),(Point *)aiStack_9c);
  aiStack_9c[0] = iVar1;
  Object::~Object((Object *)aiStack_9c);
  Point::Point((Point *)aiStack_7c,5.0,0.0);
  pCVar15 = (ActionInterval *)MoveBy::actionWithDuration(1.0,(Point *)aiStack_7c);
  aiStack_7c[0] = iVar1;
  Object::~Object((Object *)aiStack_7c);
  pCVar16 = (Sequence *)EaseInOut::actionWithAction(pCVar15,2.0);
  pCVar17 = (FiniteTimeAction *)(**(code **)(*(int *)pCVar16 + 0x34))(pCVar16);
  pCVar15 = (ActionInterval *)Sequence::actions(pCVar16,pCVar17,0);
  pCVar18 = (Action *)RepeatForever::actionWithAction(pCVar15);
  Node::runAction(*(Node **)(this + 0x158),pCVar18);
  piVar8 = (int *)GameManager::sharedState();
  cVar7 = (**(code **)(*piVar8 + 0x280))(piVar8);
  iVar1 = *(int *)(
                  "..."
                  + unaff_EBX + 0x74f);
  if (cVar7 != '\0') {
    piVar8 = (int *)GameManager::sharedState();
    pcVar6 = *(code **)(*piVar8 + 0x224);
    FUN_003e6990(&local_1c4,unaff_EBX + 0x306652,&uStack_1c7);
    (*pcVar6)(piVar8,&local_1c4);
    if (local_1c4 + -0xc != iVar1) {
      LOCK();
      piVar8 = (int *)(local_1c4 + -4);
      iVar9 = *piVar8;
      *piVar8 = *piVar8 + -1;
      UNLOCK();
      if (iVar9 < 1) {
        FUN_003e4a30(local_1c4 + -0xc,auStack_1c6);
      }
    }
    AppDelegate::showLoadError();
  }
  this_00 = (GameManager *)GameManager::sharedState();
  GameManager::showMainMenuAd(this_00);
  pCVar12 = (Node *)Sprite::create((char *)(unaff_EBX + 0x306659));
  p_Var22 = *(_func_void_Object_ptr **)
             (
             "..."
             + unaff_EBX + 0x787);
  uVar11 = 0;
  pMVar21 = this;
  pCVar13 = (MenuItem *)
            MenuItemSpriteExtra::create(pCVar12,(Node *)0x0,(Object *)this,p_Var22);
  piVar8 = (int *)Menu::create(pCVar13,0,pMVar21,p_Var22,uVar11);
  (**(code **)(*(int *)this + 0xf0))(this,piVar8,2);
  pcVar6 = *(code **)(*piVar8 + 0x4c);
  Point::Point
            ((Point *)aiStack_5c,
             *(float *)(unaff_EBX + 0x333adb) * local_1a4 + *(float *)(unaff_EBX + 0x333b07),80.0);
  (*pcVar6)(piVar8,(Point *)aiStack_5c);
  iVar9 = *(int *)(
                  "..."
                  + unaff_EBX + 0x72f);
  aiStack_5c[0] = iVar9 + 8;
  Object::~Object((Object *)aiStack_5c);
  piVar8 = (int *)MoreGamesManager::sharedState();
  cVar7 = (**(code **)(*piVar8 + 0x130))(piVar8);
  if (cVar7 != '\0') {
    piVar8 = (int *)Sprite::createWithSpriteFrameName((char *)(unaff_EBX + 0x30666e));
    (**(code **)(*(int *)pCVar12 + 0xec))(pCVar12,piVar8);
    pcVar6 = *(code **)(*piVar8 + 0x4c);
    Point::Point
              ((Point *)aiStack_3c,*(float *)(unaff_EBX + 0x333adb) * *(float *)(pCVar12 + 0x1b8),
               *(float *)(unaff_EBX + 0x333adb) * (float)piVar8[0x6f] + *(float *)(pCVar12 + 0x1bc))
    ;
    (*pcVar6)(piVar8,(Point *)aiStack_3c);
    aiStack_3c[0] = iVar9 + 8;
    Object::~Object((Object *)aiStack_3c);
  }
  piVar8 = (int *)GameManager::sharedState();
  (**(code **)(*piVar8 + 0x210))(&iStack_1c0,piVar8);
  Log((char *)(unaff_EBX + 0x30667d),local_1c4);
  if (local_1c4 + -0xc != iVar1) {
    LOCK();
    piVar8 = (int *)(local_1c4 + -4);
    iVar1 = *piVar8;
    *piVar8 = *piVar8 + -1;
    UNLOCK();
    if (iVar1 < 1) {
      FUN_003e4a30(local_1c4 + -0xc,auStack_1c9);
    }
  }
  iStack_1c0 = *(int *)(
                       "..."
                       + unaff_EBX + 0x72b) + 8;
  Object::~Object((Object *)&iStack_1c0);
  return 1;
}