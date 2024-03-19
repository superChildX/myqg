package Druid;

import JDBC.myJDBC;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;
import java.util.Scanner;

//自定义数据库连接
public class myDruid {
    private static String USERNAME;
    private static String PASSWORD;
    private static String URL;
    private static String DRIVER;
    //后面获取对象需要
    static Properties p = new Properties();

    //编写静态代码块
    static {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入配置包名");
        String ppt = sc.nextLine();
        //1.获取配置文件
        InputStream asStream = myJDBC.class.getResourceAsStream(ppt);

        try {
            //2,加载配置文件获取其中数据
            p.load(asStream);
            USERNAME = p.getProperty("username");
            PASSWORD = p.getProperty("password");
            URL = p.getProperty("url");
            DRIVER = p.getProperty("driver");

            //3.注册驱动
            Class.forName(DRIVER);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //自定义获取Druid对象
    public static DataSource getDTS() throws Exception {
        return com.alibaba.druid.pool.DruidDataSourceFactory.createDataSource(p);
    }

    //自定义获取conn
    public static Connection getConnect(DataSource dts) throws SQLException {
        return dts.getConnection();
    }

    //自定义释放
    public static void close(PreparedStatement pstmt, Connection conn) throws SQLException {
        pstmt.close();
        conn.close();
    }
}
