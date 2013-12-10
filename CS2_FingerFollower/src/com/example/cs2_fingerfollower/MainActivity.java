package com.example.cs2_fingerfollower;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

//练习2：跟随触屏手指移动的小球
//目的:开发自定义的UI组件，View
//1，创建自定义类DrawView继承View
//2，重写方法onDraw，绘制一个红色的球
//3，重写onTouchEvent，事件触发改变小球的横纵坐标
//4，在布局中加入新组件DrawView

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
