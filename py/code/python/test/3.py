import math
import random

cla_all_num = 0
cla_num = {}
cla_tag_num = {}
landa = 0.6  # 拉普拉斯修正值


def train(taglist, cla):  # 训练，每次插入一条数据
    global cla_all_num
    # 插入分类
    global cla_all_num
    cla_all_num += 1
    if cla in cla_num:  # 是否已存在该分类
        cla_num[cla] += 1
    else:
        cla_num[cla] = 1
    if cla not in cla_tag_num:
        cla_tag_num[cla] = {}  # 创建每个分类的标签字典
    # 插入标签
    tmp_tags = cla_tag_num[cla]  # 浅拷贝，用作别名
    for tag in taglist:
        if tag in tmp_tags:
            tmp_tags[tag] += 1
        else:
            tmp_tags[tag] = 1


def P_C(cla):  # 计算分类 cla 的先验概率
    return cla_num[cla] / cla_all_num


def P_W_C(tag, cla):  # 计算分类 cla 中标签 tag 的后验概率
    tmp_tags = cla_tag_num[cla]  # 浅拷贝，用作别名
    if tag not in cla_tag_num[cla]:
        return landa / (cla_num[cla] + len(tmp_tags) * landa)  # 拉普拉斯修正
    return (tmp_tags[tag] + landa) / (cla_num[cla] + len(tmp_tags) * landa)


def test(test_tags):  # 测试
    res = ""  # 结果
    res_P = None
    for cla in cla_num.keys():
        log_P_W_C = 0
        for tag in test_tags:
            log_P_W_C += math.log(P_W_C(tag, cla), 2)
        tmp_P = log_P_W_C + math.log(P_C(cla), 2)  # P(w|Ci) * P(Ci)
        if res_P is None:
            res = cla
            res_P = tmp_P
        if tmp_P > res_P:
            res = cla
            res_P = tmp_P
    return res, res_P


def create_WatermelonData():
    dataset = []
    p1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]  # 编号
    p2 = [
        "青绿",
        "乌黑",
        "乌黑",
        "青绿",
        "浅白",
        "青绿",
        "乌黑",
        "乌黑",
        "乌黑",
        "青绿",
        "浅白",
        "浅白",
        "青绿",
        "浅白",
        "乌黑",
        "浅白",
        "青绿",
    ]  # 色泽
    p3 = [
        "蜷缩",
        "蜷缩",
        "蜷缩",
        "蜷缩",
        "蜷缩",
        "稍蜷",
        "稍蜷",
        "稍蜷",
        "稍蜷",
        "硬挺",
        "硬挺",
        "蜷缩",
        "稍蜷",
        "稍蜷",
        "稍蜷",
        "蜷缩",
        "蜷缩",
    ]  # 根蒂
    p4 = [
        "浊响",
        "沉闷",
        "浊响",
        "沉闷",
        "浊响",
        "浊响",
        "浊响",
        "浊响",
        "沉闷",
        "清脆",
        "清脆",
        "浊响",
        "浊响",
        "沉闷",
        "浊响",
        "浊响",
        "沉闷",
    ]  # 敲声
    p5 = [
        "清晰",
        "清晰",
        "清晰",
        "清晰",
        "清晰",
        "清晰",
        "稍糊",
        "清晰",
        "稍糊",
        "清晰",
        "模糊",
        "模糊",
        "稍糊",
        "稍糊",
        "清晰",
        "模糊",
        "稍糊",
    ]  # 纹理
    p6 = [
        "凹陷",
        "凹陷",
        "凹陷",
        "凹陷",
        "凹陷",
        "稍凹",
        "稍凹",
        "稍凹",
        "稍凹",
        "平坦",
        "平坦",
        "平坦",
        "凹陷",
        "凹陷",
        "稍凹",
        "平坦",
        "稍凹",
    ]  # 脐部
    p7 = [
        "硬滑",
        "硬滑",
        "硬滑",
        "硬滑",
        "硬滑",
        "软粘",
        "软粘",
        "硬滑",
        "硬滑",
        "软粘",
        "硬滑",
        "软粘",
        "硬滑",
        "硬滑",
        "软粘",
        "硬滑",
        "硬滑",
    ]  # 触感
    p8 = [
        0.697,
        0.774,
        0.634,
        0.608,
        0.556,
        0.403,
        0.481,
        0.437,
        0.666,
        0.243,
        0.245,
        0.343,
        0.639,
        0.657,
        0.36,
        0.593,
        0.719,
    ]  # 密度
    p9 = [
        0.46,
        0.376,
        0.264,
        0.318,
        0.215,
        0.237,
        0.149,
        0.211,
        0.091,
        0.267,
        0.057,
        0.099,
        0.161,
        0.198,
        0.37,
        0.042,
        0.103,
    ]  # 含糖率
    p10 = [
        "是",
        "是",
        "是",
        "是",
        "是",
        "是",
        "是",
        "是",
        "否",
        "否",
        "否",
        "否",
        "否",
        "否",
        "否",
        "否",
        "否",
    ]  # 好瓜
    for i in range(len(p1)):
        dataset.append(
            [p1[i], p2[i], p3[i], p4[i], p5[i], p6[i], p7[i], p8[i], p9[i], p10[i]]
        )
    return dataset


def naive_bayes():
    dataset = create_WatermelonData()
    label_counts = {}
    labels = [data[-1] for data in dataset]
    for label in labels:
        if label not in label_counts:
            label_counts[label] = 0
        label_counts[label] += 1
    p_label = {label: count / len(labels) for label, count in label_counts.items()}
    p_feature_given_label = {}
    for feature_index in range(1, len(dataset[0]) - 1):
        feature_counts_given_label = {}
        for data in dataset:
            feature_value = data[feature_index]
            label = data[-1]
            if label not in feature_counts_given_label:
                feature_counts_given_label[label] = {}
            if feature_value not in feature_counts_given_label[label]:
                feature_counts_given_label[label][feature_value] = 0
            feature_counts_given_label[label][feature_value] += 1
        p_feature_given_label[feature_index] = feature_counts_given_label
    return p_label, p_feature_given_label


def test(sample):
    p_label, p_feature_given_label = naive_bayes()
    max_prob = -1
    result_label = None
    for label, p in p_label.items():
        prob = p
        for feature_index, feature_value in enumerate(sample):
            if feature_index == 0:  # 跳过编号
                continue
            if feature_value in p_feature_given_label[feature_index][label]:
                prob *= p_feature_given_label[feature_index][label][
                            feature_value
                        ] / sum(p_feature_given_label[feature_index][label].values())
            else:
                prob = 0  # 特征值未出现过则概率为0
                break
        if prob > max_prob:
            max_prob = prob
            result_label = label
    return result_label


if __name__ == "__main__":
    naive_bayes()  # 创建朴素贝叶斯分类
    # 单例测试模型
    test_sample = ["青绿", "蜷缩", "浊响", "清晰", "凹陷", "硬滑", 0.697, 0.46]
    result = test(test_sample)
    print(f"测试样本: {test_sample}，分类结果: {result}")
