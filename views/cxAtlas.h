//
//  cxAtlas.h
//  cxEngine
//
//  Created by xuhua on 10/17/13.
//  Copyright (c) 2013 xuhua. All rights reserved.
//

#ifndef cxEngine_cxAtlas_h
#define cxEngine_cxAtlas_h

#include "cxSprite.h"

CX_C_BEGIN

typedef struct {
    cxBool  enable;
    cxBox4f box;
}cxAtlasScale9;

CX_OBJECT_DEF(cxAtlas, cxSprite)
    GLuint vaoid;
    GLuint vboid[2];
    cxInt capacity;
    cxInt number;
    cxBoxPoint *boxes;
    GLushort *indices;
    cxBool isDirty;
    cxBool isInit;
    cxAtlasScale9 scale9;
    cxHash items;
CX_OBJECT_END(cxAtlas)

void cxAtlasDraw(cxAny pview);

void cxAtlasDrawInit(cxAny pview);

void cxAtlasResize(cxEvent *event);

void cxAtlasAppendBoxPoint(cxAny pview,cxVec2f pos,cxSize2f size,cxBoxTex2f tex,cxColor4f color);

cxBoxPoint cxAtlasCreateBoxPoint(cxVec2f pos,cxSize2f size,cxBoxTex2f tex,cxColor4f color);

void cxAtlasSetNumber(cxAny pview,cxInt capacity);

void cxAtlasSetScale9(cxAny pview,cxBox4f box);

void cxAtlasUpdateScale9(cxAny pview);

void cxAtlasClean(cxAny pview);

void cxAtlasAppend(cxAny pview,cxBoxPoint point);

void cxAtlasUpdate(cxAny pview,cxInt index, cxBoxPoint point);

void cxAtlasReadAttr(cxReaderAttrInfo *info);

CX_C_END

#endif
