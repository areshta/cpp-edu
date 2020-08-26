#!/bin/sh

dest=../sdbus-gen

sdbus-c++-xml2cpp --proxy=$dest/CanProxyGlue.h com.daimler.oagw.test.can.xml
sdbus-c++-xml2cpp --adapter=$dest/CanAdapterGlue.h com.daimler.oagw.test.can.xml

