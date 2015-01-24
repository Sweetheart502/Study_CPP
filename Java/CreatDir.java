import java.io.File;
import java.io.IOException;

/**
 * Created by yingxiao on 15-1-16.
 */
public class CreatDir {
    //  创建指定目录
    public static void main ( String [] args ) throws IOException {
        String dName = "./"+ File.separator+"test2" ;

        File f = new File ( dName ) ;

        if ( f.exists() && f.isDirectory() ) {
            // 输出目录已经存在
            System.out.println( "The direction has existed." );
        } else {
            // 创建指定目录
            f.mkdir();
        }
    }
}
