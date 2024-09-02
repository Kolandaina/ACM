import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

dataSet = np.random.rand(100, 3)

for k in range(3, 7):
    clf = KMeans(n_clusters=k)
    s = clf.fit(dataSet)
    numSamples = len(dataSet)
    centroids = clf.labels_
    print(centroids, type(centroids))
    print(clf.inertia_)
    mark = ["or", "ob", "og", "ok", "r", "+r", "sr", "dr", "<r", "pr"]

    for i in range(numSamples):
        plt.plot(dataSet[i][0], dataSet[i][1], mark[clf.labels_[i]])
        mark = ["Dr", "Db", "Dg", "Dk", "b", "+b", "sb", "db", "<b", "pb"]
        centroids = clf.cluster_centers_
        for i in range(k):
            plt.plot(centroids[i][0], centroids[i][1], mark[i], markersize=12)
        # plt.show()

import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.datasets import load_iris

iris = load_iris()
X = iris.data[:]
plt.scatter(X[:, 0], X[:, 1], c="red", marker="o", label="see")
plt.xlabel("petal length")
plt.ylabel("petal width")
plt.legend(loc=2)
plt.show()

estimator = KMeans(n_clusters=3)
estimator.fit(X)
label_pred = estimator.labels_

x0 = X[label_pred == 0]
x1 = X[label_pred == 1]
x2 = X[label_pred == 2]
plt.scatter(x0[:, 0], x0[:, 1], c="red", marker="o", label="label0")
plt.scatter(x1[:, 0], x1[:, 1], c="green", marker="*", label="label1")
plt.scatter(x2[:, 0], x2[:, 1], c="blue", marker="+", label="label2")

plt.xlabel("petal length")
plt.ylabel("petal width")
plt.legend(loc=2)
plt.show()
