#include "cocos2d_specifics.hpp"
#include "cocos2d.h"
#include "MOGOAd.h"

bool jsb_show_banner(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==0){
		bool ret=MOGOAd::showBanner();
		jsval jsret=JSVAL_NULL;
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx,vp,jsret);
		return true;
	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,0);
	return false;	
}
bool jsb_hide_banner(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==0){
		bool ret=MOGOAd::hideBanner();
		jsval jsret=JSVAL_NULL;
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx,vp,jsret);
		return true;
	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,0);
	return false;	
}
bool jsb_init_interstitial(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==0){
		bool ret=MOGOAd::initInterstitial();
		jsval jsret=JSVAL_NULL;
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx,vp,jsret);
		return true;
	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,0);
	return false;	
}
bool jsb_show_interstitial(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==0){
		bool ret=MOGOAd::showInterstitial();
		jsval jsret=JSVAL_NULL;
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx,vp,jsret);
		return true;
	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,0);
	return false;	
}
bool jsb_feedback(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==0){
		bool ret=MOGOAd::feedback();
		jsval jsret=JSVAL_NULL;		
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx,vp,jsret);
		return true;
	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,0);
	return false;
}
bool jsb_open_share(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==2){
		jsval *argv=JS_ARGV(cx,vp);
		bool ok=true;
		std::string arg0,arg1;
		ok&=jsval_to_std_string(cx,argv[0],&arg0);
		ok&=jsval_to_std_string(cx,argv[1],&arg1);
		JSB_PRECONDITION2(ok, cx, false, "jsb_open_share : Error processing arguments");

		bool ret=MOGOAd::openShare(arg0.c_str(),arg1.c_str());
		jsval jsret=JSVAL_NULL;
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;

	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,2);
	return false;
}
bool jsb_show_toast(JSContext *cx,uint32_t argc,JS::Value *vp){
	if(argc==1){
		jsval *argv=JS_ARGV(cx,vp);
		bool ok=true;
		std::string arg0;
		ok&=jsval_to_std_string(cx,argv[0],&arg0);
		JSB_PRECONDITION2(ok, cx, false, "jsb_show_toast : Error processing arguments");

		bool ret=MOGOAd::showToast(arg0.c_str());
		jsval jsret=JSVAL_NULL;
		jsret=BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;		
	}
	JS_ReportError(cx,"wrong number of arguments: %d ,was expecting %d ",argc,1);
	return false;
}

void register_mogo_ads(JSContext* cx,JSObject* obj){

    //绑定方法到全局
    //参数为（上下文，全局对象，js访问名称，c++本地名称，传入参数个数，js中的方程属性）
    // JS_DefineFunction(cx, obj, "openShare", jsb_umeng_social, 1, 0);
    // JS_DefineFunction(cx, obj, "exitGame" , jsb_exit_game, 0, 0);
    // JS_DefineFunction(cx, obj, "showOrHideBanner" , jsb_hide_banner, 0, 0);
    // JS_DefineFunction(cx, obj, "initInterstitial" , jsb_init_interstitial, 0, 0);
    // JS_DefineFunction(cx, obj, "showInterstitial" , jsb_show_interstitial, 0, 0);

    static JSFunctionSpec myjs_global_functions[]={
    	JS_FN("startBanner" , jsb_show_banner, 0, 0),
    	JS_FN("showOrHideBanner" , jsb_hide_banner, 0, 0),
    	JS_FN("initInterstitial" , jsb_init_interstitial, 0, 0),
    	JS_FN("showInterstitial" , jsb_show_interstitial, 0, 0),
    	JS_FN("feedback",jsb_feedback,0,0),
    	JS_FN("openShare",jsb_open_share,2,0),
    	JS_FN("showToast",jsb_show_toast,1,0),
       	JS_FS_END
    };

    if(!JS_DefineFunctions(cx,obj,myjs_global_functions)){
    	JS_ReportError(cx,"定义失败");
    }


}
