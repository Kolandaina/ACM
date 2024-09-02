from PIL import Image

# 打开原始照片
image = Image.open('your.jpg')

# 计算小照片的宽度和高度
width, height = image.size
small_width = width // 9
small_height = height // 6

# 循环分割照片
for i in range(6):
    for j in range(9):
        # 计算当前小照片的区域
        left = j * small_width
        top = i * small_height
        right = (j + 1) * small_width
        bottom = (i + 1) * small_height

        # 从原始照片中裁剪出当前小照片
        small_image = image.crop((left, top, right, bottom))

        # 保存小照片
        small_image.save(f'small_image_{i}_{j}.jpg')
