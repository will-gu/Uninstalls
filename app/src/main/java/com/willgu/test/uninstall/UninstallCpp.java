package com.willgu.test.uninstall;

/**
 * @author: will.gu
 * @CreteDate: 2018/1/4 11:00
 * @Description: ${tags}
 */

public class UninstallCpp {

    public native String stringFromJNI();

    public native void uninstall(String packageDir,String webUrl, int sdkVersion);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("uninstallCpp");
    }

}
