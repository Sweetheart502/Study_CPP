import java.io.File;
import java.io.IOException;

/**
 * Created by yingxiao on 15-1-24.
 */
public class DeleteFile {
    // 删除指定文件
    public static void main ( String [] args ) throws IOException {
        String fName = "./"+ File.separator+"test.txt" ;

        File f = new File ( fName ) ;

        if ( f.exists() && f.isFile() ) {
            // 如果文件存在则删除
            f.delete() ;
        } else {
            // 输出错误信息
            System.out.println( "The file not exist." );
        }
    }
}
