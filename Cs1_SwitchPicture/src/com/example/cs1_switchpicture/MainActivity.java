package com.example.cs1_switchpicture;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.LinearLayout;

//练习一：简单图片浏览器
//目的：布局文件和代码混合控制UI界面
//1，设置main.xml布局为线形（垂直）
//2， 添加图片资源
//3，增加MainActivity代码。声明变量，获取root布局，
//   创建图像，添加到布局，更改参数实现图片的更换。
public class MainActivity extends Activity {
	
	int[] images =new int[]{
		R.drawable.pic1,
		R.drawable.pic2,
		R.drawable.pic3,
		R.drawable.pic4,
	};
	int currentImg=0;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		
		LinearLayout main=(LinearLayout) findViewById(R.id.root);
		
		final ImageView image =new ImageView(this);
		main.addView(image);
		image.setImageResource(images[0]);
		image.setOnClickListener(new OnClickListener(){
			@Override
			public void onClick(View v){
				image.setImageResource(images[++currentImg%images.length]);
			}
		});
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
