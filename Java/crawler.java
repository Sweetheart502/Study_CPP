cimport org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.File;
import java.io.IOException;

/**
 * Created by yingxiao on 15-1-25.
 */
public class crawler {
    public static void main ( String [] args) throws IOException{
        Document doc = Jsoup.connect( "http://news.163.com/domestic/" ).get() ;

//        // 网页的html文本
//        String html = doc.body().toString() ;
//
//        System.out.println( html );

        // 网页的标题
        String title = doc.title() ;

        System.out.println(title);

       //获取文章标题和链接
        arcticle();
    }
    public static void arcticle () {
        Document doc ;
        try {
            doc = Jsoup.connect("http://news.163.com/domestic/").get();
            // 创建一个队列获取类名为list-item clearfix的类
            Elements List = doc.getElementsByAttributeValue("class","list-item clearfix") ;

            // 循环遍历每一个元素
            for (Element element :List) {

                Elements links = element.getElementsByTag("a");
                for (Element link : links) {
                    //　分别获取新闻链接和标题
                    String linkHref = link.attr("href");
                    String linkText = link.text().trim();
                    //　分别输出新闻链接和标题
                    System.out.println(linkHref);
                    System.out.println(linkText);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
