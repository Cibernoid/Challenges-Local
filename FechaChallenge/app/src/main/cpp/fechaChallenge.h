//
// Created by JorgeNokia on 15/12/2017.
//


#ifndef FECHACHALLENGE_FECHACHALLENGE_H
#define FECHACHALLENGE_FECHACHALLENGE_H

#include <jni.h>
#include <iostream>       // std::cout, std::ios
#include <sstream>        // std::istringstream
#include <stdint.h>
#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdlib.h>
#include <ctime>          // std::tm
#include <locale>         // std::locale, std::time_get, std::use_facet
#include "rapidxml.hpp"
#include <string>
#include <sstream>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

/*template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}*/


typedef unsigned char UCHAR;
typedef char CHAR;
typedef UCHAR* PUCHAR;
typedef CHAR* PCHAR;


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jorgenokia_fechachallenge_MainActivity_stringFromJNI(JNIEnv *env,
                                                                      jobject /* this */);

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_jorgenokia_fechachallenge_MainActivity_executeParam(JNIEnv *env,
                                                                     jobject /* this */,
                                                                     jobject assetManager);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jorgenokia_fechachallenge_MainActivity_execute(JNIEnv *env,
                                                                jobject /* this */,
                                                                jobject assetManager,
                                                                PUCHAR* parametrosXml);


PUCHAR* getChallengeProtectParams(AAssetManager *mgr, JNIEnv *env);
PUCHAR* getChallengeUnProtectParams(AAssetManager *mgr, JNIEnv *env);
tm AddMonths_OracleStyle(const tm &d, int months);
int GetDaysInMonth(int year, int month);
bool IsLeapYear(int year);
time_t AddMonths_OracleStyle(const time_t &date, int months);

#endif //FECHACHALLENGE_FECHACHALLENGE_H



