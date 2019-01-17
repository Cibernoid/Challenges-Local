//
// Created by JorgeNokia on 10/01/2018.
//

#ifndef DEVICENAMECHALLENGE_DEVICENAMECHALLENGE_H
#define DEVICENAMECHALLENGE_DEVICENAMECHALLENGE_H

#include <string>
#include <string.h>
#include <jni.h>
#include <stdint.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

typedef unsigned char UCHAR;
typedef char CHAR;
typedef UCHAR* PUCHAR;
typedef CHAR* PCHAR;


extern "C"
jobjectArray JNICALL Java_com_example_jorgenokia_fechachallenge_MainActivity_executeParam(JNIEnv *env,
jobject /* this */,
jobject assetManager);

extern "C"
jstring JNICALL Java_com_example_jorgenokia_fechachallenge_MainActivity_execute(JNIEnv *env,
jobject /* this */,
jobject assetManager,
jstring parametrosXml);

PUCHAR* getChallengeProtectParams(AAssetManager *mgr, JNIEnv *env);
PUCHAR* getChallengeUnProtectParams(AAssetManager *mgr, JNIEnv *env);

#endif //DEVICENAMECHALLENGE_DEVICENAMECHALLENGE_H
