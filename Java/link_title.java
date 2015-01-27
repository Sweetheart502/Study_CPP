import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class crawler {
    public static void main ( String [] args ) {
        Document doc = null ;

        try {
            doc = Jsoup.connect( "http://news.163.com/domestic/" ).get() ;
        } catch (IOException e) {
            e.printStackTrace();
        }

        // 做一个断言
        assert doc != null;

        // 获取当前网页上的class为item-top的新闻信息
        Elements divs = doc.getElementsByClass( "item-top" );
        // 利用队列存储该页面上的新闻链接地址
        List<String> links = new LinkedList<String>() ;
        List<String> titles = new LinkedList<String>() ;

        for (Element div : divs) {
            // 获取每一则新闻含有a标签的第一个链接地址
            Element a = div.select( "a" ).first() ;

            // 添加入当前队列中
            links.add( a.attr ( "abs:href" ) ) ;
            titles.add( a.text() ) ;

            // 输出显示每一则新闻的链接
            System.out.println( a.attr ( "abs:href" ) );
            System.out.println( a.text() );
        }
    }
}
