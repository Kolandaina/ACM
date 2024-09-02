# 去除warning警报
import warnings 
warnings.filterwarnings("ignore")
# 导入加载数据集的方法
from sklearn.datasets import load_boston
# 特征处理器
from sklearn.preprocessing import PolynomialFeatures
# 导入数据集划分方法
from sklearn.model_selection import train_test_split
# 加载数据集
boston = load_boston()
X = boston.data
y = boston.target
# 查看数据集形状
print("特征数据形状：",X.shape)
print("响应变量形状：",y.shape)
# 设置多项式的最高次数为3
poly = PolynomialFeatures(degree=3)
poly.fit(X)
X_ = poly.transform(X)
# 查看特征处理之后的数据集形状
print("特征数据形状：",X_.shape)
print("响应变量形状：",y.shape)
# 按照8：2的比例切割数据集为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X_, y,train_size=0.8)
# 查看训练集形状
print("训练集特征维度", X_train.shape)
print("训练集响应变量维度", y_train.shape)
print("测试集特征维度", X_test.shape)
print("测试集响应变量维度", y_test.shape)

# 导入线性回归模型
from sklearn.linear_model import LinearRegression
# 创建线性回归模型
pr = LinearRegression()
# 使用线性回归模型拟合训练集数据
pr.fit(X_train, y_train)
# 预测数据
yhat1 = pr.predict(X_train)
yhat2 = pr.predict(X_test)
# 导入均方误差方法，并使用均方误差评估模型
from sklearn.metrics import mean_squared_error
# 计算训练集的均方误差
MSE1 = mean_squared_error(y_train, yhat1)
print("训练集均方误差",MSE1)
# 计算测试集的均方误差
MSE2 = mean_squared_error(y_test, yhat2)
print("测试集均方误差",MSE2)

# 导入岭回归模型
from sklearn.linear_model import Ridge
# 创建岭回归模型
pr = Ridge(alpha=1e10)
# 使用岭回归模型拟合训练集数据
pr.fit(X_train, y_train)
# 预测数据
yhat1 = pr.predict(X_train)
yhat2 = pr.predict(X_test)
# 导入均方误差方法，并使用均方误差评估模型
from sklearn.metrics import mean_squared_error
# 计算训练集的均方误差
MSE1 = mean_squared_error(y_train, yhat1)
print("训练集均方误差",MSE1)
# 计算测试集的均方误差
MSE2 = mean_squared_error(y_test, yhat2)
print("测试集均方误差",MSE2)

# 导入套索回归模型
from sklearn.linear_model import Lasso
# 创建套索回归模型
lasso_reg = Lasso(alpha=1e10)
# 使用套索回归模型拟合训练集数据
lasso_reg.fit(X_train, y_train)
# 预测数据
yhat1_lasso = lasso_reg.predict(X_train)
yhat2_lasso = lasso_reg.predict(X_test)
# 导入均方误差方法，并使用均方误差评估模型
from sklearn.metrics import mean_squared_error
# 计算训练集的均方误差
MSE1_lasso = mean_squared_error(y_train, yhat1_lasso)
print("套索回归训练集均方误差:", MSE1_lasso)
# 计算测试集的均方误差
MSE2_lasso = mean_squared_error(y_test, yhat2_lasso)
print("套索回归测试集均方误差:", MSE2_lasso)
