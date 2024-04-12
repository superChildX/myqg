package utils;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class JDBC {
    private static String USER;
    private static String PASSWORD;
    private static String URL;
    private static String DRIVER;
    static {
        //1.获取配置文件
        InputStream asStream = JDBC.class.getResourceAsStream("/JDBC.properties");
        Properties p = new Properties();

        try {
            //2.加载配置文件
            //解析流  通过创建properties对象读取流
            //配置文件读到了p中
            p.load(asStream);
            USER = p.getProperty("user");
            PASSWORD = p.getProperty("password");
            URL = p.getProperty("url");
            DRIVER = p.getProperty("driver");
            //3.注册驱动
            Class.forName(DRIVER);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static Connection getConn() throws SQLException {
        return DriverManager.getConnection(URL,USER,PASSWORD);
    }
    public static PreparedStatement getPs(Connection conn,String sql) throws SQLException {
        return conn.prepareStatement(sql);
    }
    public static void close(ResultSet rs, Statement stmt, Connection conn) throws Exception {
        rs.close();
        stmt.close();
        conn.close();
    }
    public static void close(ResultSet rs, PreparedStatement pstmt, Connection conn) throws Exception {
        rs.close();
        pstmt.close();
        conn.close();
    }
}
