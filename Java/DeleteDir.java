import java.io.File;
import java.io.IOException;

/**
 * Created by yingxiao on 15-1-24.
 */
public class DeleteDir {
    // 删除指定目录
    public static void main ( String [] args ) throws IOException {
        String dName = "./"+ File.separator+"test2" ;

        File f = new File ( dName ) ;

        if ( f.exists() && f.isDirectory() ) {
            // 如果目录存在则删除
            f.delete() ;
        } else {
            // 输出错误信息
            System.out.println( "The direction not exist." );
        }
    }
}
