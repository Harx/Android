
// 文档
http://www.zouyesheng.com/angular.html




// 手机端

#界面
- 使用技术 ionic {简单，和xmuplant网页版相比，js部分不用改，只是修改呈现部分html，css。部署方便。}
- 以ionic sidemenu模板为基础。
- 界面(最初设计)
  - 一共三个一级页面·分类·地图·专题·，或者加一个·更多·，首页默认分类页面。
  - 分类页面: 一个搜索框{} 三个分类{List Item Thumbnails}    // http://ionicframework.com/docs/components/
    - header按钮递归 {Buttons in Headers}
    - 每个分类{List Dividers}
    - 每项{Item Avatars}
    - 详细内容{Card Images}  ？地图图片放在tab？

#PHP
db_con.php              // 数据库连接
r.php                   // 通用的根据tables,items,id读取数据
genus.php               // 返回 指定科的属列表 及 属的种列表
species.php             // 返回指定 species 的 类 科 属

subject.php             // 返回 一个专题的介绍 和 其所包括的种的列表
map.php                 // 返回 !='' 的坐标

// Waste
search.php              // 返回搜索的 species name_cn name_en //只适合点击搜索
division.php            // 已合并到r.php
family.php              // 已合并到r.php
storage.php             // 读取新浪storage数据,已换用qiqiu.com




//tips
*修改species.html页面,添加 类 科 属... ,让 地图 图片 图标更和谐.
***SQL注入???
***使用百度地图极速版（ak: 7E291EBBa951b7c90e08ee80a46c2489），精简的标准版(比如没有滚轮缩放,但支持触摸缩放)，具体看类参考： http://developer.baidu.com/map/reference/index.php
***图片放到qiniu云存储上。如何限定额度??? http://sae.sina.com.cn/doc/php/storage.html#windowsmac
?随机读取一个植物用于手机端首页
?首页： 一个植物介绍和搜索框。
?图片能触摸放大

//errors
!http://xmuplant.qiniudn.com/%E8%82%BE%E8%95%A8%E7%A7%91%20%E8%82%BE%E8%95%A8.jpg


#######################################################################################
#######################################################################################
#######################################################################################

//网页版
//
bootstrap.css
angular.js
http://angular-ui.github.io/bootstrap/


// svn
svn update


///
css模板： http://getbootstrap.com/examples/carousel/
目录结构：
  lib/          bootstrap,angular,kindeditor等库。可以用“前端公共库CDN”节省流量。
  db/           *.php
  templates/    Angular HTML模板
  img/
  app.js
  app.css


//
1. 写出HTML页面模板（分析数据）
2. 数据json (php mysql读取数据)


？//
a. 首页随机轮转图。
b. 快速过滤。

n. reactjs以后再说。


