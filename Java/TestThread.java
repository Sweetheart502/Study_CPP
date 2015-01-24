/**
 * Created by yingxiao on 15-1-23.
 */
public class TestThread extends Thread {
    // 继承Thread类，重载run方法
    public void run () {
        System.out.println( getName() + "是名演员。" );
        int count = 0 ;
        boolean keepRunning = true ;

        while ( keepRunning ) {
            System.out.println( getName() + "登台演出" + ( ++count ) );

            if ( count == 100 ) {
                keepRunning = false ;
            }
        }


        System.out.println( getName() + "演出结束。" );
    }

    public static void main ( String [] args ) {
        Thread actor = new TestThread() ;

        actor.setName( "Mr.Thread" );

        // 线程开始运行即调用start方法
        actor.start();
    }
}
