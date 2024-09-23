import java.io.*;
import java.util.Arrays;

public class TemplateCustom {
    public static final String OUTPUT_FILENAME = "compareResult.txt"; //文件名 不要改

    /**
     * 自定义对比函数, 下面是每行对比，特殊情况，可以重新下面对比函数
     *
     * @param outputLine        用户输出结果
     * @param expectLine        预期结果a
     * @param compareResultFile 对比结果输出文件
     */
    private static void compare(String outputLine, String expectLine, FileOutputStream compareResultFile) throws IOException {
        // 去除前后的空格并去掉首尾的方括号
        outputLine = outputLine.trim().replaceAll("[\\[\\]]", "");
        expectLine = expectLine.trim().replaceAll("[\\[\\]]", "");

        // 按逗号分割成数组
        String[] outputArray = outputLine.split(",\\s*");
        String[] expectArray = expectLine.split(",\\s*");

        // 按字典序排序
        Arrays.sort(outputArray);
        Arrays.sort(expectArray);

        // 判断长度是否相同
        if (outputArray.length != expectArray.length) {
            compareResultFile.write(("0").getBytes()); // 长度不一致，输出0
            return;
        }

        // 对比每一个对应的字符串是否相同
        for (int i = 0; i < outputArray.length; i++) {
            if (!outputArray[i].equals(expectArray[i])) {
                compareResultFile.write(("0").getBytes()); // 有不同的字符串，输出0
                return;
            }
        }

        // 所有比较通过，输出1
        compareResultFile.write(("1").getBytes());
    }

    public static void main(String[] args) throws IOException {
        String submissionId = args[0]; //code 执行的任务id
        String outputFileName = args[1];//用户代码执行后的结果
        String expectFileName = args[2];//预期的结果
        File outputFile = new File(outputFileName);
        File expectFile = new File(expectFileName);
        File compareResultFile = new File(OUTPUT_FILENAME);
        try (FileInputStream outputStream = new FileInputStream(outputFile);
             FileInputStream expectStream = new FileInputStream(expectFile);
             BufferedReader outputReader = new BufferedReader(new InputStreamReader(outputStream));
             BufferedReader expectReader = new BufferedReader(new InputStreamReader(expectStream));
             FileOutputStream compareResult = new FileOutputStream(compareResultFile);) {
            String outputLine, expectLine;
            while ((outputLine = outputReader.readLine()) != null && (expectLine = expectReader.readLine()) != null) {
                //输出的结果会写入文件中，compare函数会读取文件，进行对比，推荐每个testCase的结果写成一行
                compare(outputLine, expectLine, compareResult);
            }
        }
    }
}