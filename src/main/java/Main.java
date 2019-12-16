public class Main {

    static {
        System.loadLibrary("cpu");
    }

    private native String getCpuInfo();

    public static void main(String[] args) {
        String s = new Main().getCpuInfo();
        System.out.println(s);
    }

}

/*
    javac -h . Main.java
    gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libcpu.so CPU.c
    java -Djava.library.path=. Main
 */
