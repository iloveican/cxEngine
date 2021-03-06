//
//  cxHttp.h
//  cxEngine
//
//  Created by xuhua on 10/31/13.
//  Copyright (c) 2013 xuhua. All rights reserved.
//

#ifndef cxEngine_cxHttp_h
#define cxEngine_cxHttp_h

#include <evhttp.h>
#include <core/cxBase.h>
#include <core/cxString.h>
#include "cxHttpConn.h"

CX_C_BEGIN

typedef void (*cxHttpFunc)(cxAny http);

CX_OBJECT_DEF(cxHttp, cxObject)
    cxBool isSuccess;
    cxInt64 bodyBytes;
    cxInt64 readBytes;
    cxString data;
    struct evhttp_request *request;
    struct evhttp_uri *uri;
    CX_EVENT_ALLOC(onChunked);
    CX_EVENT_ALLOC(onCompleted);
CX_OBJECT_END(cxHttp)

cxString cxHttpUriEncode(cxString uri);

cxString cxHttpUriDecode(cxString uri);

cxString cxHttpGetData(cxAny http);

cxHttp cxHttpGetRequest(cxConstChars url,cxBool chunked);

cxHttp cxHttpPostRequest(cxConstChars url,cxString data,cxBool chunked);

CX_C_END

#endif
