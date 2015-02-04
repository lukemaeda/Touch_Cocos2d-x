//
//  TopTouchScene.cpp
//  Touch
//
//  Created by MAEDAHAJIME on 2015/02/04.
//
//

#include "TopTouchScene.h"
//音をならすためにinclude
#include "SimpleAudioEngine.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

Scene* TopTouchScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = TopTouchScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}


// 「INIT」初期化
bool TopTouchScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    
    // ラベルを生成
    Label* label1 = Label::createWithSystemFont("Cocos2d-x", "Arial", 120);
    
    // ラベルの設置
    label1->setPosition(Point(winSize.width / 2 ,winSize.height / 2));
    
    // ラベルタイトルを追加
    this->addChild(label1,1);
    
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    // 3.x系 タップイベントを取得する
    // シングルタッチモード
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(TopTouchScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TopTouchScene::onTouchMoved, this);
    listener->onTouchCancelled = CC_CALLBACK_2(TopTouchScene::onTouchCancelled, this);
    listener->onTouchEnded = CC_CALLBACK_2(TopTouchScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

//タッチ開始イベント
bool TopTouchScene::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップ開始！");
    
    return true;
}

//タッチ移動イベント
void TopTouchScene::onTouchMoved(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップ中");
}

//タッチキャンセルイベント
void TopTouchScene::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップキャンセル");
}

//タッチ終了イベント
void TopTouchScene::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    CCLOG("タップ終了！");
}


