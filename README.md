全国大学生智能车竞赛-AI电磁组
=========
本项目用于记录2021年全国大学生智能车竞赛一年多来的成果。
## 内容列表

- [背景](##背景)
- [安装](##安装)
- [使用说明](##使用说明)
- [成果](##成果)

## 背景
项目起源于2021年智能车竞赛AI电磁组，基本要求：在未知闭环赛道上，使用AI模型预测未来路径，控制小车完成一圈循迹。
本人负责软件开发，具体为模型的训练与部署、小车系统的控制，队友负责硬件开发。
> 具体赛题(引用)：https://blog.csdn.net/zhuoqingjoking97298/article/details/110253008


## 安装
下载安装Git克隆本项目到本地后，使用AURIX Development Studio编译后，使用DAPminiWiggler烧录到TC377芯片中。

## 使用说明
主要源码目录简介：
```
-Design_test
  |- code                          各模块功能
      |- AI                        DNN、LSTM模型的部署与预测
      |- Flash                     芯片断电保存数据
      |- ICM                       陀螺仪读取姿态
      |- Menu                      OLED交互菜单
      |- PCI                       外设控制(电机、编码器、干簧管)
      |- PID                       PID控制轨迹
      |- Special_Control           赛道特殊元素处理判断
      |- UART                      串口通讯
  |- USER                          主程序、定时器并行调度
  |- Libraries                     项目依赖配置、开源库
```

## 成果
决赛视频：https://pan.baidu.com/s/1K7YETY95D7Atu9Mz_Q9bMw?pwd=b8b6 提取码: b8b6 复制这段内容后打开百度网盘手机App，操作更方便哦

技术报告：https://uestc.feishu.cn/file/KzZ1bh5rpotIBoxjDWncxUY5nac?from=from_copylink
