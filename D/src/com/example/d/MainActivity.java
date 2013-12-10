package com.example.d;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class MainActivity extends Activity {

	@SuppressLint("SetJavaScriptEnabled")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		WebView web=(WebView) findViewById(R.id.webView1);
		web.setWebViewClient(new WebViewClient());//用以保证链接跳转保持在当前view。
		String url1=("http://t.asmld.com");
		String url2=("http://harxd3.sinaapp.com");
		web.loadUrl(url1);
		WebSettings websettings=web.getSettings();
		websettings.setJavaScriptEnabled(true);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
