import java.io.File;
import java.io.IOException;

/**
 * Created by yingxiao on 15-1-16.
 */
public class CreatFile {
    // 创建指定文件
    public static void main ( String [] args ) throws IOException{
        String fName = "./"+ File.separator+"test.txt" ;

        File f = new File ( fName ) ;

        if ( f.exists() ) {
            // 输出文件存在
            System.out.println( "The file has existed." );
        } else {
            // 创建指定文件
            f.createNewFile();
        }
    }
}
