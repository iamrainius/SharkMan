#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    initBackground(scene);
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->initSharkMan();
    this->initPerspectiveCamera();
    
    input = new PlayerInput(sharkMan);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    schedule(schedule_selector(MainScene::upDateScene));
    
    return true;
}

void MainScene::upDateScene(float dt)
{

}

bool MainScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    input->handleTouchBegan(touch->getLocation());
    return true;
}

void MainScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    input->handleTouchEnded(touch->getLocation());
}

void MainScene::initSharkMan()
{
    sharkMan = new SharkMan();
    auto sharkManSprite = sharkMan->getSprite3D();
    addChild(sharkManSprite, 10);
    sharkManSprite->setPosition3D(Vec3(0, 0, -40));
}

void MainScene::initPerspectiveCamera()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto camera = Camera::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 200);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0, 15, -15));
    camera->lookAt(Vec3(0, 0, -60),Vec3(0, 1, 0));
    this->addChild(camera);
    this->setCameraMask((unsigned short )CameraFlag::USER1);
}

void MainScene::initBackground(Scene* scene)
{
    auto winSize = Director::getInstance()->getWinSize();
    
    // 添加背景，使用正交摄像机
    auto orthoCamera = Camera::createOrthographic(winSize.width, winSize.height, 0, 1000);
    orthoCamera->setCameraFlag(CameraFlag::USER2);
    scene->addChild(orthoCamera);
    auto bgLayer = Layer::create();
    scene->addChild(bgLayer, -100, "main_scene_bg");
    auto bg= Sprite::create("model/back_ground.jpg");
    
    // Fit bg to screen
    auto bgSize = bg->getContentSize();
    bg->setScale(winSize.width / bgSize.height, winSize.height / bgSize.height);
    
    bg->setPosition(winSize.width / 2, winSize.height / 2);
    bgLayer->addChild(bg);
    bgLayer->setCameraMask(4);
    bgLayer->setColor(Color3B(255, 0, 0));
    
    
    // add layer as a child to scene
    auto layer = MainScene::create();
    scene->addChild(layer, 100, "main_scene_layer");
}


void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
