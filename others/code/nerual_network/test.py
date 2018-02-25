# coding=utf-8
import numpy as np
import math

# classes = ['plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']
# num_classes = len(classes)
# samples_per_class = 7
# for y, cls in enumerate(classes):
#     idxs = np.flatnonzero(y_train == y)
#     print(idxs)

# a = np.random.randint(2, 5, size=(3, 5))
# print(a)
# equalThree = (a == 3)
# print(np.flatnonzero(equalThree))

# a = np.array([1, 2])
# c = np.array([[1, 2]])
# b = np.tile(a, (5, 1))
# print(np.sum(b, axis=0))
# print(b + a)
# print(b + c) # meaning that [] or [[]] can both automatically expand

# a = np.array([1, 2, 3, 4])
# b = np.tile(a, (2, 3, 2))
# print(b)
# print(np.sum(b, axis=2)) # gao wei hui tan suo dao di wei...


# print(b.shape) # 2L 8L so axis[0] is the 2L
# c = np.sum(b, 1) # 0 is the currently max dimension
# print(c)  # axis = 0 lie qiu he
# print(c.shape)

# a = np.array([1, 4, 9, 16])
# a = np.tile(a, (2, 1))
# a[1][1] = 1
# print a[1, :]
# print a[1]

# a = np.array([1, 2, 3])
# print(np.sum(a, 0))

# b = np.bincount(a)
# print(b)
# c = (a - b) ** 2
# print(np.sum(c))

# import numpy as np
# a = np.array([
#               [
#                   [1, 5, 5, 2],
#                   [9, -6, 2, 8],
#                   [-3, 7, -9, 1]
#               ],
#
#               [
#                   [-1, 5, -5, 2],
#                   [9, 6, 2, 8],
#                   [3, 7, 9, 1]
#               ]
#             ])
# print(np.sum(a, axis=0))

# bar = [1, 2, 3, 4]
# print(bar[4:])
# print(bar[:3] + bar[4:])
# print(bar[:2] + bar[3:])
# a = np.array([1, 2, 3, 4, 5, 6])
# a = np.split(a, 3)
# print(a)
# print(a[:1] + a[2:])
# b = np.vstack(a[:1] + a[2:]).reshape(1, -1)[0]
# print(a)
# b = np.concatenate((a[:1], a[2:]))
# x = np.array(list(a)[:1] + list(a)[2:])
# print(b)
# print([np.sum(a, axis=1)].T)
# c = np.transpose([np.sum(a, axis=1)])
# print(a + c)
#
# a = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]])
# print(a)
# print(np.vstack(a))
# b = np.array_split(a, 2)
# c = np.vstack(b)
# print(b)
# print(c)
# if isinstance(b, list): print("yes")

# r = np.random.rand(5000, 3072)
# fold = np.array_split(r, 5)
# y = np.array([1, 2, 3, 5, 5])
# print(y)
# print(y.shape)
# ysplit = np.array_split(y, 5)
# yvstack = np.hstack(ysplit[0:2] + ysplit[3:])
# print(yvstack.shape)
# train = np.vstack(fold[:2] + fold[3:])
# print(train.shape)

# 从1darray（这里的10会转为np,arange(10))中随机取5个，False为取后不放回，还可以加一个取每一个的
# 概率数组
# print(np.random.choice(10, 5, False))
#
# a = np.arange(27)
# a = a.reshape((3, 9))
# a = np.hstack([a, np.ones((a.shape[0], 1))])
# print(a)
# print(np.mean(a, axis=0))  # axis = 0即通过取平均消去最新的维度

# print(np.random.rand(10, 1).shape)
# # print(np.arange(10).shape)
# c = np.arange(9).reshape((3, 3))
# print(c[np.arange(2), np.arange(2)])

# print(np.random.randint(0, 10, (1, 10)))
# a = np.arange(10)
# idx = np.random.choice(10, 4, replace=True)
# b = a[idx]
# print(b)

# a = np.arange(16).reshape(4, 4)
# b = np.argmax(a, axis=1)
# print(b)

# a = np.arange(16).reshape((4, 4))
# y = np.arange(4)
# print(np.zeros(5))

# a = np.arange(20).reshape(4, 5)
# a_pad = np.pad(a, ((2, 2), (2, 2)), "constant")
# pad = 2
# print((pad, ))
# print(a_pad[pad:-pad, pad:-1])

# print(np.zeros((4, 4), dtype=np.float64))

# a = np.arange(9).reshape(3, 3)
# b = np.arange(3)
# print(a + (b)[None, :])
# print((b)[None, :], b[:, None], b)
# print(a[:, :])

# a = np.arange(20).reshape(4, 5)
# print(np.argmax(a, axis=0))



# import tensorflow as tf
# import numpy as np
# import sys
# import math
# x_data=np.random.rand(100).astype(np.float32)
# #print(x_data)
# #sys.exit(0)
# y_data=x_data*0.1+0.3
#
#
# W = tf.Variable(tf.constant([100], dtype=tf.float32))
# b = tf.Variable(tf.constant([100], dtype=tf.float32))
# x = tf.placeholder(tf.float32, [1])
# y = x * W + b
# _y = tf.placeholder(tf.float32, [1])
#
#
# loss = tf.square(y-_y)
# #四种梯度下降法
# #train=tf.train.GradientDescentOptimizer(1e-1).minimize(loss) #1300 steps后达到误差范围。
# #train=tf.train.AdamOptimizer(1e-1).minimize(loss)            #9000 steps后达到误差范围。
# train = tf.train.MomentumOptimizer(1e-1, 0.9).minimize(loss)     #500  steps后达到误差范围。
#
#
# sess = tf.Session()
# sess.run(tf.global_variables_initializer())
# idx=0
# while True:
#   xx = [x_data[idx%100]]
#   yy = [y_data[idx%100]]
#   idx += 1
#   ww, bb, tt = sess.run([W, b, train], feed_dict={x:xx,_y:yy})
#   if math.fabs(ww-0.1)<1e-6 and math.fabs(bb-0.3)<1e-6:
#     print(ww, bb)
#     print("train_step:%d" %(idx))
#     break;
#    #说明：使用0.1的学习率，训练一维线性方程 y=0.1*x+0.3，初始时,W和b设为100。运行到W,b误差小于1e-6为止。


# import tensorflow as tf
# a = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[2, 3], name='a')
# b = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[3, 2], name='b')
# c = tf.matmul(a, b)
#
# sess = tf.Session(config=tf.ConfigProto(log_device_placement=True))
#
# print(sess.run(c))
# x = np.asarray([[0, 1], [0, 2]])  # W[x] 的第一维为W的第1 2 行，第二维为W的 1 3 行， 所以反向时也仅对这些位置的W做改变
# W = np.linspace(0, 1, num=5*3).reshape(5, 3)
# print(W)
# # print(W[x, :])
# print(W[x, :])
# np.add.at(W, x, W[x, :])
# print(W)
#
# V, N, T, D = 5, 2, 3, 4
# dout = np.zeros((N, T, D))
# W = np.zeros((V, D))
# x = np.zeros(N, T)
# np.add.at

a = np.arange(4).reshape((2, 2))
b = a
print(np.multiply(a, b))