# UE5Lab
UE5 相关的研究，解答写平时的疑惑

## Windows
### 无边框
1. 修改项目设置
``
[/Script/EngineSettings.GeneralProjectSettings]
bUseBorderlessWindow=True
``

[UE4设置窗口无边框](https://blog.csdn.net/maxiaosheng521/article/details/103634958)

### Splash Screen
`` \Engine\Content\Splash\Splash.bmp ``
NOSPLASH

### Windows编程
#### RegisterClass: 
窗口类的注册操作，这是Windows GUI程序创建窗口前的必要步骤。具体步骤如下:
1. 填充`WNDCLASS`结构体，设定了窗口的基本行为特征
2. 系统注册窗口类，将定义好的窗口类提交给操作系统内核，完成以下核心操作：
    1. 在系统内部建立窗口类与消息处理函数`WndProc`的映射关系
    2. 记录窗口的默认视觉属性（如光标、背景色等）
    3. 分配唯一标识符，用于后续窗口创建时识别该窗口类

https://learn.microsoft.com/en-us/windows/win32/winmsg/window-class-styles




## Visual Studio 
### UnrealVS插件
1. 点击安装插件 UnrealEngine\Engine\Extras\UnrealVS\VS2022\UnrealVS.vsix
2. 打开VS，右键点击工具栏区域（toolbar area），开启UnrealVS

[using the unrealvs extension for unreal engine cplusplus projects](https://dev.epicgames.com/documentation/en-us/unreal-engine/using-the-unrealvs-extension-for-unreal-engine-cplusplus-projects)

## C++ 
### CRTP Curiously Recurring Template Pattern 奇异递归模板模式
在UE4中，TSharedFromThis的用法属于C++设计模式中的奇异递归模板模式（Curiously Recurring Template Pattern，CRTP）​, 这种模式的特征是：​一个类通过继承模板类并**将自身作为模板参数传递**

为何称为CRTP？
CRTP的名称来源于其语法特性：

1. ​递归性：子类将自身类型作为基类模板参数
2. 模板化继承：基类**TSharedFromThis**是一个模板类
3. ​编译期多态：通过静态类型推导实现功能，而非运行时虚函数机制


在UE4中，TSharedFromThis通过CRTP实现安全共享指针管理，继承该类的对象可通过AsShared()获取自身的TSharedPtr，确保对象生命周期由智能指针管理，避免裸指针导致的悬垂引用。例如：

``TSharedPtr<MyClass> SharedPtr = this->AsShared();``

---

### BlueprintType vs Blueprintable
| 特性    | BlueprintType | Blueprintable |
| -------- | ------- | ------- |
| 功能  | 允许创建蓝图变量 | 允许创建蓝图子类    |
| 影响对象 | 类或结构体(Class/Struct) | 类(Class)    |
| 常见应用  | 数据容器，枚举类型 | 基础Actor |
| 举例  | 玩家数据： FPlayerData | 玩家角色：AMyCharacter |


### 可见性/可写性

|说明符|	可见范围	|适用场景|	典型示例| 举例|
| -------- | ------- | ------- |  ------- | ------- |
|​**VisibleAnywhere**	|默认对象 + 实例对象	|全局或局部只读信息	|生命值、实时坐标| ... |
|​**VisibleInstanceOnly**	|仅实例对象|	实例特有的运行时状态|	目标位置、临时标记| uint8 bWasJumping(ACharacter) |
|​**VisibleDefaultsOnly**|	仅默认对象|	全局基础配置或默认值	|基础属性、初始化参数|  TObjectPtr<AActor> ChildActorTemplate(UChildActorComponent) |



|说明符	|可编辑范围	|适用场景	|典型示例| 举例|
| -------- | ------- | ------- |  ------- | ------- |
|​ **EditAnywhere**	    |​默认对象 + 实例对象 |​	需灵活调整的通用参数 |​	角色移动速度、材质参数| ... |
| **EditInstanceOnly**	|​仅实例对象         |​	实例特有的参数      |​	场景中特定敌人的位置| TArray<TObjectPtr<AActor>> HiddenActors(USceneCaptureComponent) |​
| **EditDefaultsOnly**	|​仅默认对象         |​	全局固定配置参数    |​	武器基础伤害、技能冷却时间| uint8 bReplicates(UActorComponent)|​

