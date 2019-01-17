#include "deviceNameChallenge.h"



jobjectArray JNICALL Java_com_example_jorgenokia_fechachallenge_MainActivity_executeParam(JNIEnv *env,
                                                                                          jobject /* this */,
                                                                                          jobject assetManager) {

    PUCHAR* protectParams = getChallengeProtectParams(NULL, env);

    PCHAR challengeReturn = (PCHAR)protectParams[0];

    char* firstPartXml = "<Challenge name=\"deviceNameChallenge\">\
		<Params nparams=\"0\">";
    char* finalPartXml = "</Params>\
		</Challenge>";

    PCHAR xmlReturn;
    xmlReturn = (PCHAR)malloc(strlen(firstPartXml) + strlen(finalPartXml));

    strcpy(xmlReturn, firstPartXml); /* copy name into the new var */
    strcat(xmlReturn, finalPartXml); /* add the extension */


    jobjectArray returnArray;
    returnArray = (jobjectArray)env->NewObjectArray(2,env->FindClass("java/lang/String"),env->NewStringUTF(""));
    jstring result_jstring = env->NewStringUTF(challengeReturn);
    jstring xml_jstring = env->NewStringUTF(xmlReturn);
    env->SetObjectArrayElement(returnArray, 0, result_jstring);
    env->SetObjectArrayElement(returnArray, 1, xml_jstring);

    return returnArray;
}

jstring JNICALL Java_com_example_jorgenokia_fechachallenge_MainActivity_execute(JNIEnv *env,
                                                                                          jobject /* this */,
                                                                                          jobject assetManager,
                                                                                jstring parametrosXml) {

    PUCHAR* protectParams = getChallengeUnProtectParams(NULL, env);

    PCHAR challengeReturn = (PCHAR)protectParams[0];


    jstring result_jstring = env->NewStringUTF(challengeReturn);

    return result_jstring;
}

PUCHAR* getChallengeProtectParams(AAssetManager *mgr, JNIEnv *env) {

    // Fetch the device model as name for now
    jclass build_class = env->FindClass("android/os/Build");
    jfieldID model_id = env->GetStaticFieldID(build_class, "MODEL", "Ljava/lang/String;");
    jstring model_obj  = (jstring)env->GetStaticObjectField(build_class, model_id);
    const char *deviceName = env->GetStringUTFChars(model_obj, 0);

    PUCHAR* envParams = new UCHAR *[1];
    envParams[0] = (PUCHAR)deviceName;
    return envParams;
}

PUCHAR* getChallengeUnProtectParams(AAssetManager *mgr, JNIEnv *env) {

    // Fetch the device model as name for now
    jclass build_class = env->FindClass("android/os/Build");
    jfieldID model_id = env->GetStaticFieldID(build_class, "MODEL", "Ljava/lang/String;");
    jstring model_obj  = (jstring)env->GetStaticObjectField(build_class, model_id);
    const char *deviceName = env->GetStringUTFChars(model_obj, 0);

    PUCHAR* envParams = new UCHAR *[1];
    envParams[0] = (PUCHAR)deviceName;
    return envParams;
}

