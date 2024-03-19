package JDBC;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;
import java.util.Scanner;

//自定义jdbc
public class myJDBC {
    private static String USERNAME;
    private static String PASSWORD;
    private static String URL;
    private static String DRIVER;

    //编写静态代码块
    static {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入配置包名");
        String ppt = sc.nextLine();
        //1.获取配置文件
        InputStream asStream = myJDBC.class.getResourceAsStream(ppt);
        Properties p = new Properties();

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


    //自定义获取conn
    public static Connection getConnect() throws SQLException {
        return DriverManager.getConnection(URL, USERNAME, PASSWORD);
    }

    //自定义释放
    public static void close(ResultSet rs, Statement stmt, Connection conn) throws SQLException {
        rs.close();
        stmt.close();
        conn.close();
    }
}
