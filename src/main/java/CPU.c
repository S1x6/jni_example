// Save as "HelloJNI.c"
#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include <string.h>
#include <malloc.h>
#include "Main.h"   // Generated

JNIEXPORT jstring JNICALL Java_Main_getCpuInfo(JNIEnv *env, jobject obj) {
   FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
      char *arg = 0;
      size_t size = 0;
      while(getdelim(&arg, &size, 0, cpuinfo) != -1)
      {
         puts(arg);
      }

   char *buf = (char*)malloc(100000);
   strcpy(buf, arg); // with the null terminator the string adds up to 10 bytes
   jstring jstrBuf = (*env)->NewStringUTF(env, buf);
   free(arg);
   free(buf);
   fclose(cpuinfo);
   return jstrBuf;
}