//
//  cxMain.c
//  cxEngine
//
//  Created by xuhua on 9/25/13.
//  Copyright (c) 2013 xuhua. All rights reserved.
//

#include <core/cxHash.h>
#include <streams/cxAssetsStream.h>
#include <textures/cxTexturePVR.h>
#include <textures/cxTexturePNG.h>
#include <textures/cxTextureFactory.h>
#include "cxMain.h"
#include <core/cxDB.h>


#include <actions/cxMove.h>
#include <actions/cxCurve.h>
#include <core/cxActionXML.h>
#include <views/cxSprite.h>
#include <core/cxViewXML.h>
#include <views/cxButton.h>
#include <jansson.h>
#include <views/cxAtlas.h>
#include <views/cxParticle.h>
#include <views/cxTable.h>
#include <core/cxIconv.h>
#include <core/cxFreeType.h>
#include <views/cxLabelTTF.h>
#include <core/cxDB.h>
#include <core/cxPlayer.h>
#include <socket/cxHttp.h>
#include <streams/cxMp3Stream.h>
#include <views/cxScroll.h>
#include <actions/cxRunner.h>
#include <views/cxLoading.h>
#include <views/cxChipmunk.h>
#include <views/cxLabelBMP.h>
#include <core/cxBMPFont.h>

static cxAny loading(cxAny loading)
{
    cxEngineDataSet("items.xml");
    return cxViewXMLCreate("main.xml");
}

static void finished(cxAny pview)
{
    cxWindowPushView(pview, NULL);
}

static void deleteSprite(cxEvent *event)
{
    cxAny pview = cxViewXMLGet(event->sender, "purple");
    cxChipmunkApplyImpulse(pview, cxVec2fv(0, 2000), cxVec2fv(0, 1));
}

static void cxChipmunkBegin(cxEvent *event)
{
    cxViewXMLRegisteEvent(event->sender, "deleteSprite", deleteSprite);
}

void cxEngineInit(cxEngine engine)
{
    cxEngineRegisteEvent("cxChipmunkBegin", cxChipmunkBegin);
    
    engine->dessize = cxSize2fv(640, 960);
    cxPlayerOpen(0, 0);
    
//    engine->isShowBorder = false;
}

void cxEngineMain(cxEngine engine)
{
    cxAny lv = cxLoadingStart(loading, finished);
    cxLabelTTF txt = cxLabelTTFCreate(UTF8("Loading..."), UTF8("banana.ttf"), 60);
    cxViewSetColor(txt, cxRED);
    cxViewAppend(lv, txt);
}

void cxEngineFree(cxEngine engine)
{
    
}
















