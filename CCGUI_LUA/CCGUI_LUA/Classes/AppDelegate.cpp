#include "cocos2d.h"
#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
#include "CCGUIToLua.h"
#include "CCGUI.h"
USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
    // fixed me
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
}

AppDelegate::~AppDelegate()
{
    // end simple audio engine here, or it may crashed on win32
    SimpleAudioEngine::sharedEngine()->end();
    //CCScriptEngineManager::purgeSharedManager();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // register lua engine
    /*CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
    tolua_CCGUI_open(pEngine->getLuaState());
    
    std::string path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("lua/hello.lua");
    pEngine->addSearchPath(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("lua"));
    pEngine->executeScriptFile(path.c_str());
     */
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCScene * scene = CCScene::create();
    CCGUI::Widget * root = CCGUI::WidgetManager::sharedMgr()->init(scene, 0);
    CCGUI::ListBox * list = CCGUI::ListBox::create("list");
    for(int i=0; i<100; ++i){
        list->addItem("hello");
    }
    
    list->setItemHeight(30);
    list->setContentSize(CCSizeMake(300,300));
    list->setPosition(CCPointMake(size.width/2, size.height/2));
    //
    CCGUI::TextBox * text = CCGUI::TextBox::create("hello world");
    text->setPosition(CCPointMake(size.width/2+400, size.height/2));
    //
    CCGUI::MultiListBox * multiList = CCGUI::MultiListBox::create("multilist", 2, 2);
    multiList->setPosition(CCPointMake(size.width/2-300, size.height/2));
    
    multiList->setItem("hifsd", 0, 0);
    root->addWidget(multiList);
    root->addWidget(text);
    root->addWidget(list);
    
    multiList->addColumn("head", 150);
    multiList->addRow();
    
    CCDirector::sharedDirector()->runWithScene(scene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
