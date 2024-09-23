import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

class Sea {
    boolean hasShips(int topRight, int bottomLeft) {
        
    }
}

public class Entrance {
    public static final String SEPARATOR = "\u001B\t\u001D";
    public static final String OUTPUT_FILENAME = "result.txt";
    public static final String MEMORY_FILENAME = "memory.txt";

    public static void main(String[] args) throws IOException {

        try (BufferedReader brCoder = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));
             FileOutputStream fosCoder = new FileOutputStream(OUTPUT_FILENAME);
             FileOutputStream memoryCoder = new FileOutputStream(MEMORY_FILENAME);) {
            Runtime r = Runtime.getRuntime();
            long startMem = r.totalMemory() - r.freeMemory();

            String lineCoder;
            while ((lineCoder = brCoder.readLine()) != null && !"".equals(lineCoder)) {

                fosCoder.write((new {
                    {
                        outputSerializeClassName
                    }
                } ().serialize({{outputName}}) + "\n").getBytes());
                System.out.print(SEPARATOR);
            }

            long endMem = r.totalMemory() - r.freeMemory();
            memoryCoder.write(String.format("%.2f", (endMem - startMem) / (float) (1000 * 1000)).getBytes());
        }
    }
}