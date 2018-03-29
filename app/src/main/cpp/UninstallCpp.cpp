#include <jni.h>
#include <string>

#include <stdio.h>
#include <jni.h>
#include <malloc.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <fcntl.h>
#include <stdint.h>
//#include "com_willgu_test_uninstall_MainActivity.h"
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


extern "C" {
    JNIEXPORT void JNICALL
    Java_com_willgu_test_uninstall_UninstallCpp_uninstall(JNIEnv *env, jobject instance,
                                                          jstring packageDir_, jstring webUrl_,
                                                          jint sdkVersion) {
        // 1，将传递过来的java的包名转为c的字符串
        const char *packageDir = env->GetStringUTFChars(packageDir_, 0);
        const char *webUrl = env->GetStringUTFChars(webUrl_,0);
        LOGD("11111111111111111111111111111111111");
        // 2，创建当前进程的克隆进程
        pid_t pid = fork();
        // 3，根据返回值的不同做不同的操作,<0,>0,=0
        if (pid < 0) {
            // 说明克隆进程失败
            LOGD("11111111111111111111111111111111111current crate process failure");
        } else if (pid > 0) {
            // 说明克隆进程成功，而且该代码运行在父进程中
            LOGD("11111111111111111111111111111111111crate process success,current parent pid = %d", pid);
        } else {
            // 说明克隆进程成功，而且代码运行在子进程中
            LOGD("11111111111111111111111111111111111crate process success,current child pid = %d", pid);

            // 4，在子进程中监视/data/data/包名这个目录

            while (1){
                FILE *p_file = fopen(packageDir, "r");
                if (p_file != NULL){
                    fclose(p_file);
                    //目录存在log
                    LOGD("11111111111111111111111111111111111目录存在");
                    sleep(1);
                } else{
                    LOGD("11111111111111111111111111111111111目录不存在");
                    execlp("am", "am", "start", "-a", "android.intent.action.VIEW", "-d", "http://m.2345.com/?ksysdba", (char *)NULL);
                }
            }


            /*//初始化inotify进程
            int fd = inotify_init();
            if (fd < 0) {
                LOGD("11111111111111111111111111111111111inotify_init failed !!!");
                exit(1);
            }

            //添加inotify监听器
            int wd = inotify_add_watch(fd, packageDir, IN_DELETE);
            if (wd < 0) {
                LOGD("11111111111111111111111111111111111inotify_add_watch failed !!!");
                exit(1);
            }

            //分配缓存，以便读取event，缓存大小=一个struct inotify_event的大小，这样一次处理一个event
            void *p_buf = malloc(sizeof(struct inotify_event));
            if (p_buf == NULL) {
                LOGD("11111111111111111111111111111111111malloc failed !!!");
                exit(1);
            }

            //开始监听
            LOGD("11111111111111111111111111111111111start observer");
            ssize_t readBytes = read(fd, p_buf, sizeof(struct inotify_event));
            LOGD("11111111111111111111111111111111111start observer2");
            //read会阻塞进程，走到这里说明收到目录被删除的事件，注销监听器
            free(p_buf);
            LOGD("11111111111111111111111111111111111start observer3");
            inotify_rm_watch(fd, IN_DELETE);

            // 应用被卸载了，通知系统打开用户反馈的网页
            LOGD("11111111111111111111111111111111111 app uninstall,current sdkversion = %d", sdkVersion);
            if (sdkVersion >= 17) {
                // Android4.2系统之后支持多用户操作，所以得指定用户
                execlp("am", "am", "start", "--user", "0", "-a",
                       "android.intent.action.VIEW", "-d", webUrl,
                       (char *) NULL);
            } else {
                // Android4.2以前的版本无需指定用户
                execlp("am", "am", "start", "-a", "android.intent.action.VIEW",
                       "-d", webUrl, (char *) NULL);
            }*/

        }

    }


    JNIEXPORT jstring JNICALL
    Java_com_willgu_test_uninstall_UninstallCpp_stringFromJNI(JNIEnv *env, jobject instance) {

        // TODO

        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }
}

