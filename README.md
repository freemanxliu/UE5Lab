# UE5Lab
UE5 相关的研究，解答写平时的疑惑


### BlueprintType vs Blueprintable
| 特性    | BlueprintType | Blueprintable |
| -------- | ------- | ------- |
| 功能  | 允许创建蓝图变量 | 允许创建蓝图子类    |
| 影响对象 | 类或结构体(Class/Struct) | 类(Class)    |
| 常见应用  | 数据容器，枚举类型 | 基础Actor |
| 举例  | 玩家数据： FPlayerData | 玩家角色：AMyCharacter |
