# auto generate so
## 实现基本功能(V0.1)  
### 完成的功能    
1. 可以选择源文件在的文件夹;    
2. 可以选择生成的so文件存储的文件夹;    
3. 点击Generator可以生成so文件;  
4. 能够显示是否完成的状态,如果完成了finish; 
5. 生成了可执行文件：在exe　文件夹中的ａutogenso3,　修改权限chmod +x autogenso3, 然后运行./autogenso3 


### 待优化  
1. 界面美化度待优化;  
2. 当前源文件需要都放在同一个文件夹中，需要调整为放到src和inc中;  
3. 多次操作的考虑：改动代码后，如果点击继续生成，会生成新的么; (已解决，20210427, 能生成新的so文件)
4. 能够输入模块名称，实现不同的模块生成不同的libso;(已解决，20210427)
5. 当前生成的可执行文件只能在ubuntu16.04下运行，在其他平台下运行会出错，需要验证是否可以采用在其他平台下生成so文件？


![alt 图例]("https://github.com/shawn-xsj/AutoGenerateSo/tree/main/img/result.png")
<!-- ![avatar]("/home/saic/xsj/AutoSo/AutoSo2/AutoGenerateSo/img/result.png") -->

