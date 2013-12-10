package com.example.cs3_neonlamp;

import java.util.Timer;
import java.util.TimerTask;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Menu;
import android.widget.TextView;

//练习3，霓虹灯
//目标：FrameLayout帧布局的应用，能够重叠的布局。
//1，布局添加六个TextView，叠加摆放。
//2，主UI线程下设置一个时间进程，触发事件
//3，Activity下创建一个Handler来接收事件，并改变TextView的背景色。
public class MainActivity extends Activity {
	
	private int currentColor=0;
	final int[] colors=new int[]{
			R.color.color1,
			R.color.color2,
			R.color.color3,
			R.color.color4,
			R.color.color5,
			R.color.color6
	};
	final int[] names=new int[]{
			R.id.textView1,
			R.id.textview2,
			R.id.textview3,
			R.id.textview4,
			R.id.textview5,
			R.id.textview6
	};
	TextView[] views=new TextView[names.length];
	@SuppressLint("HandlerLeak")
	Handler handler=new Handler(){
		@Override
		public void handleMessage(Message msg){
			if(msg.what==0x123){
				for(int i=0;i<names.length;i++){
					views[i].setBackgroundResource(colors[(i+currentColor)%names.length]);
				}currentColor++;
			}
			super.handleMessage(msg);
		}
	};	

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		for(int i=0;i<names.length;i++){
			views[i]=(TextView) findViewById(names[i]);
		}
		new Timer().schedule(new TimerTask(){
			@Override
			public void run(){
				handler.sendEmptyMessage(0x123);
			}
		},0,200);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
