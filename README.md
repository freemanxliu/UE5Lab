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
| 特性    | VisibleAnywhere | VisibleInstanceOnly | VisibleDefaultsOnly  
| -------- | ------- | ------- |  ------- |
| 可见性  | 可见，不可编辑 | 实例可见，不可编辑 | 蓝图可见，不可编辑 |
| 适用场景  | 数据容器，枚举类型 | 基础Actor |


| 特性    | EditAnywhere | EditInstanceOnly | EditDefaultsOnly |
| -------- | ------- | ------- |  ------- |
| 可见性/可编辑性  |可见，可编辑  | 实例可见，可编辑  | 蓝图可见，可编辑  |
| 适用场景  | 	需灵活调整的通用参数 | 实例特有的参数 | 全局固定配置参数|
| 举例  | 角色移动速度、材质参数 | 场景中特定敌人的位置 | 武器基础伤害、技能冷却时间|

