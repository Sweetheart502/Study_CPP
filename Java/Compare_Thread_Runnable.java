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

            // 每输出十个，则调用一次sleep
            if ( count % 10 == 0 ) {
                // 注意需要进行异常处理
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }


        System.out.println( getName() + "演出结束。" );
    }

    public static void main ( String [] args ) {
        Thread actor = new TestThread() ;

        actor.setName( "Mr.Thread" );

        // 线程开始运行即调用start方法
        actor.start();

        Thread actress = new Thread( new Actress() , "Ms.Runnable" ) ;

        // 利用Runnable接口
        actress.start();
    }
}

class Actress implements Runnable {

    @Override
    public void run() {
        System.out.println( Thread.currentThread().getName() + "是名演员。" );
        int count = 0 ;
        boolean keepRunning = true ;

        while ( keepRunning ) {
            System.out.println(  Thread.currentThread().getName() + "登台演出" + ( ++count ) );

            if ( count == 100 ) {
                keepRunning = false ;
            }

            // 每输出十个，则调用一次sleep
            if ( count % 10 == 0 ) {
                // 注意需要进行异常处理
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        System.out.println( Thread.currentThread().getName() + "演出结束。" );
    }
}