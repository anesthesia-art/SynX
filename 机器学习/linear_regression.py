"""
请利用下面给出的数据，在尽可能不调用过多高级Pytorch库函数
(如torch.nn.Linear、torch.optim.SGD）的前提下，实现下述任务：

小批量数据迭代器：
编写函数 data_iter(batch_size, features, labels)
随机打乱数据，并每次返回一个批次 (x, y)
线性回归模型和损失函数：
编写函数 linreg(x, w, b) 实现线性预测
编写函数 squared_loss(y_hat, y) 计算平方和损失
优化器（SGD）：
编写函数 sgd(params, lr, batch_size)
每一步更新参数，并清零梯度
训练循环：
初始化参数 w 和 b
设定超参数：学习率、迭代次数、批量大小
使用 for 循环实现训练过程
每个 epoch 后打印训练损失
可选拓展：
训练可视化：使用 Matplotlib 或其他可视化工具绘制每个 epoch 的训练损失变化曲线。
超参数调节：在完成基础训练循环后，自行尝试修改参数学习率（lr）、迭代次数（num_epochs）、
批量大小（batch_size）并记录不同参数组合下训练损失的变化，
总结不同超参数对训练速度和模型收敛效果的影响。
"""



