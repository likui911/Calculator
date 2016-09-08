# Calculator
Finite State Machine and the Cheap Calculator

## 实现的功能
1. 支持整数、小数输入
2. 支持+ - * / 四则运算
3. CE 清除当前操作数
4. C 清除所有、回到初始状态
5. 回显操作数和结果

## HSM状态图
计算器可以分为七种状态：Start、Operand_1、Negate_1、Operator、Operand_2、Negate_2、Error。其中Start、Operand_1、Operand_1状态又分了几种子状态。
下面简要的介绍下状态状态转换的过程：

1. 启动软件，进入Start状态
2. 当用户点击1-9、0、Point按钮，软件进入Operand_1 状态。
3. 当用户点击+、-、*、/按钮，软件进入Operator状态。
4. 此时当用户再次点击1-9、0、Point按钮，软件进入Operand_2 状态。
5. 如果用户点击=按钮，软件就进入了Start状态。
6. 如果此时进行的是除法运算且除数为0，软件进入Error状态，用户只有点击C按钮才可以跳出。

在实际开发的过程中，我们只需要关心现在程序处在什么状态，可以进行什么样的操作。然后就是状态转换的条件要处理下。

![状态图](http://likui.online/images/HSM.png)

## 运行效果展示
![运行效果](http://likui.online/images/CALC.png)

[Fork Me](https://github.com/likui911/Calculator)

[Contact Me](http://likui.online/)
