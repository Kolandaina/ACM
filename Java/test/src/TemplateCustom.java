import java.io.*;

public class TemplateCustom {
    public static final String OUTPUT_FILENAME = "compareResult.txt"; //文件名 不要改
    /**
     * 自定义对比函数, 下面是每行对比，特殊情况，可以重新下面对比函数
     * @param outputLine 用户输出结果
     * @param expectLine 预期结果
     * @param compareResultFile   对比结果输出文件
     */
    private static void compare(String outputLine, String expectLine, FileOutputStream compareResultFile) throws IOException {
        outputLine = outputLine.trim();
        expectLine = expectLine.trim();
        if (outputLine.equals(expectLine)) {
            compareResultFile.write(("1").getBytes());
        } else {
            compareResultFile.write(("0").getBytes());
        }
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