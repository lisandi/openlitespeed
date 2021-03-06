/*****************************************************************************
*    Open LiteSpeed is an open source HTTP server.                           *
*    Copyright (C) 2013  LiteSpeed Technologies, Inc.                        *
*                                                                            *
*    This program is free software: you can redistribute it and/or modify    *
*    it under the terms of the GNU General Public License as published by    *
*    the Free Software Foundation, either version 3 of the License, or       *
*    (at your option) any later version.                                     *
*                                                                            *
*    This program is distributed in the hope that it will be useful,         *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
*    GNU General Public License for more details.                            *
*                                                                            *
*    You should have received a copy of the GNU General Public License       *
*    along with this program. If not, see http://www.gnu.org/licenses/.      *
*****************************************************************************/
#ifdef RUN_TEST

#include <util/httpfetch.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "socket/gsockaddr.h"
#include "test/unittest-cpp/UnitTest++/src/UnitTest++.h"

//TEST(httpfetchTest_Test)
void VOID_TEST()//httpfetchTest_Test)
{
    printf ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf ("THIS TEST CAN ONLY TEST BY DEBUG with breakpoints\n");
    printf ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    
    void *p = NULL;
    HttpFetch *pHttpFetch = new HttpFetch;
    pHttpFetch->setCallBack(NULL, p);
    //pHttpFetch->setTimeout(100);
    
    int nonblock = 0;
    const char * pBody = NULL;
    int bodyLen = 0;
    const char * pSaveFile = "./lswslogo3.png";
    
    
    pHttpFetch->setProxyServerAddr("127.0.0.1:8000");
    int ret = pHttpFetch->startReq( "http://www.litespeedtech.com/templates/litespeed/images/lswslogo3.png",
              nonblock, 1,
              pBody, 
              bodyLen, 
              pSaveFile);
    delete pHttpFetch;
    pHttpFetch = NULL;
    
    pHttpFetch = new HttpFetch;
    ret = pHttpFetch->startReq( "http://www.litespeedtech.com/templates/litespeed/images/lswslogo3.png",
              nonblock, 1,
              pBody, 
              bodyLen, 
              pSaveFile, NULL, "www.litespeedtech.com:80");
    delete pHttpFetch;
    pHttpFetch = NULL;
    
    pHttpFetch = new HttpFetch;
    GSockAddr gsock;
    gsock.setHttpUrl("http://www.litespeedtech.com/", strlen("http://www.litespeedtech.com/"));
    
    GSockAddr gsock1;
    gsock1.setHttpUrl("https://www.litespeedtech.com/", strlen("https://www.litespeedtech.com/"));
    
    GSockAddr gsock2;
    gsock2.setHttpUrl("http://www.litespeedtech.com:888", strlen("http://www.litespeedtech.com:998"));
    
    GSockAddr gsock3;
    gsock3.setHttpUrl("https://www.litespeedtech.com:444", strlen("https://www.litespeedtech.com:998"));
    
    GSockAddr gsock4;
    gsock4.setHttpUrl("http://www.litespeedtech.com/dfgfdgfdgfdg", strlen("http://www.litespeedtech.com/dfgfdgfdgfdg"));
    
    GSockAddr gsock5;
    gsock5.setHttpUrl("http://www.litespeedtech.com:888/dfgfdgfdgfdg", strlen("http://www.litespeedtech.com:888/dfgfdgfdgfdg"));

    GSockAddr gsock6;
    gsock6.setHttpUrl("https://www.litespeedtech.com/dfgfdgfdgfdg", strlen("https://www.litespeedtech.com/dfgfdgfdgfdg"));
    
    GSockAddr gsock7;
    gsock7.setHttpUrl("https://www.litespeedtech.com:444/dfgfdgfdgfdg", strlen("https://www.litespeedtech.com:888/dfgfdgfdgfdg"));

    ret = pHttpFetch->startReq( "http://www.litespeedtech.com/templates/litespeed/images/lswslogo3.png",
              nonblock, 1,
              pBody, 
              bodyLen, 
              pSaveFile, 0, gsock);
    delete pHttpFetch;
    pHttpFetch = NULL;
    
    pHttpFetch = new HttpFetch;    
    pHttpFetch->setProxyServerAddr("127.0.0.1:8000");
    ret = pHttpFetch->startReq( "http://www.litespeedtech.com/templates/litespeed/images/lswslogo3.png",
              nonblock, 1,
              pBody, 
              bodyLen, 
              pSaveFile, 0, gsock);
    delete pHttpFetch;
    pHttpFetch = NULL;
 
    CHECK(ret == 0);
    
}

#endif
