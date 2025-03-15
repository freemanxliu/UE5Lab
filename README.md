# UE5Lab
UE5 相关的研究，解答写平时的疑惑

## C++ 
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

