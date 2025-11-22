#include <jni.h>
#include <android/log.h>
#include <string>
#include <iostream>
#include <algorithm> // Для примера обработки

#define LOG_TAG "MyNativeApp"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_zipper_MainActivity_processTextNative(
        JNIEnv* env,
        jobject /* this */,
        jstring inputString) {

    const char *nativeString = env->GetStringUTFChars(inputString, 0);
    std::string text(nativeString);
    // Освобождаем память, выделенную под char*
    env->ReleaseStringUTFChars(inputString, nativeString);

    // --- ПРИМЕР ОБРАБОТКИ: Добавляем суффикс ---
    std::string processedText = "C++ обработал: " + text;
    LOGD("This is debug information");
    // 3. Возвращаем результат обратно в Java/Kotlin
    return env->NewStringUTF(processedText.c_str());
}