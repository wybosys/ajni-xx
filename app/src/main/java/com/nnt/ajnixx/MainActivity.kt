package com.nnt.ajnixx

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.getkeepsafe.relinker.ReLinker
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity() : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // 加载so
        ReLinker.loadLibrary(this, "tester")

        // 启动独立tick，如果位于cocos中，则不需要这一步（采用cocos大循环中调用JNI的tick替代）
        MainThread.StandaloneTick()

        // 绑定主UI，使得JNI回调都位于主线程中，避免崩溃
        Activity.Bind(this)

        // 测试
        sample_text.text = Test.Test()
    }
}
