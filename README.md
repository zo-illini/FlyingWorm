# FlyingWorm

在游戏中，用wasd和鼠标控制摄像机移动。

调整Track(Actor)下的样条组件，可以更改Boss移动的轨迹。

Boss由WormHead, WormBodyx5 和WormTail组成，WormHead下的Speed Variable控制速度，请无视组件中的Acceleration，turn speed等各项。

WormBody和WormTail的跟随都继承自C++ class DampingCube。

