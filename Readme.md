# auto generate so

### 软件使用说明
    1. 该脚本软件用于生成.so文件；
    2. 在exe　文件夹中的ａutogenso3,　修改权限chmod +x autogenso3, 然后运行./autogenso3;
    3. 源文件的存放需要符合的格式：
                        ----module　
                                |----src
                                       |
                                       |----xxx.c
                                |----inc
                                       |
                                       |----xxxx.h
    4. 软件运行起来后，如果更改了程序，可以直接再生成so文件，无需关闭软件重新开始; 
    5. 当前软件只针对生成USS的so，如果需要生成其他模块的so文件可能bug, 还需要调试;
    6. 当前的可执行文件在ubuntu16.04下生成，在其他版本的系统上运行会有bug, 需要在其他版本的系统下重新生成可执行文件；
    7. 如果无法运行可执行文件，也可以直接运行源文件　python autogenso3.py


### 开发记录(V0.1)  
### 完成的功能    
    1. 可以选择源文件在的文件夹;    
    2. 可以选择生成的so文件存储的文件夹;    
    3. 点击Generator可以生成so文件;  
    4. 能够显示是否完成的状态,如果完成了finish; 
    5. 生成了可执行文件：在exe　文件夹中的ａutogenso3,　修改权限chmod +x autogenso3, 然后运行./autogenso3;


### 待优化  
    1. 界面美化度待优化;  
    2. 当前源文件需要都放在同一个文件夹中，需要调整为放到src和inc中;  (已解决，20210428,原文件能分开放到src和inc中)
    3. 多次操作的考虑：改动代码后，如果点击继续生成，会生成新的么; (已解决，20210427, 能生成新的so文件)
    4. 能够输入模块名称，实现不同的模块生成不同的libso;(已解决，20210427)
    5. 当前生成的可执行文件只能在ubuntu16.04下运行，在其他平台下运行会出错，需要验证是否可以采用在其他平台下生成可执行文件？


![alt 图例]("https://github.com/shawn-xsj/AutoGenerateSo/tree/main/img/result.png")
<!-- ![插入本地图片]("/home/saic/xsj/AutoSo/AutoSo2/AutoGenerateSo/img/result.png") -->
<!-- ![插入图片测试]("http://pic.downcc.com/upload/2015-9/2015923174024.png") -->



