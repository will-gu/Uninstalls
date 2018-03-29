package com.willgu.test.uninstall;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        UninstallCpp cpp = new UninstallCpp();
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(cpp.stringFromJNI());

        String packageDir = getApplicationContext().getFilesDir().getPath();
        int sdkVersion = android.os.Build.VERSION.SDK_INT;
        String webUrl = "http://m.2345.com/?ksysdba";

        cpp.uninstall(packageDir,webUrl,sdkVersion);
    }
}
