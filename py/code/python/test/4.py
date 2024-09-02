import tensorflow as tf
import os

os.environ["CUDA_VISIBLE_DEVICES"] = "0"
print(tf.__version__)
a = tf.constant(1.)
b = tf.constant(2.)
print(a + b)
print('GPU:', tf.test.is_gpu_available())
