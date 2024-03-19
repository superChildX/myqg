package JDBC;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class Longin_Statement_prepareStatement {
    //  /JDBC.properties
    //url = jdbc:mysql://127.0.0.1:3306/userlogin?useSSL=false 运用此地址的操作

    public static void main(String[] args) throws Exception {

        //1.调取自定义方法运行并注册驱动
        Connection conn = myJDBC.getConnect();

        //2.接收用户名和密码的输入
        String username = "zhangsan";//sql注入时可以乱写用户名
        String pwd = "123";//如果不是123 是 ' or '1' = '1 也会登录成功---这就是sql注入---是因为拼字符串到sql代码哪里

        //2.定义sql
        String sql = "select * from login where username = '"+username+"' and password = '"+pwd+"'";
        //sql = "select * from login where username = "乱写" and password = '' or '1' = '1' "---这是个必对的语句

        //3.获取stmt对象
        Statement stmt = conn.createStatement();

        //4.执行sql
        ResultSet rs = stmt.executeQuery(sql);

        //5.判断登录是否成功
        if(rs.next()){
            System.out.println("登录成功~~");
        }else{
            System.out.println("登陆失败!!");
        }

        //5.释放对象
        myJDBC.close(rs,stmt,conn);
    }

    //这时候为了防止sql注入就要用到preparedStatement
    public void testPreparedStatement() throws Exception{
        //1.调取自定义方法运行并注册驱动
        Connection conn = myJDBC.getConnect();

        //2.接收用户名和密码的输入
        String username = "zhangsan";
        String pwd = "123";//这时 ' or '1' = '1 不会成功
        //即使传入上面的字符串，也不会成功，他会自动转义，最后结果是  \' or \'1\' = \'1

        //2.定义sql
        String sql = "select * from login where username = ？ and password = ？";

        //3.获取pstmt对象---加入sql
        PreparedStatement pstmt = conn.prepareStatement(sql);

        //4.设置？值
        pstmt.setString(1,username);
        pstmt.setString(2,pwd);

        //5.执行sql---不用传入sql
        ResultSet rs = pstmt.executeQuery();

        //6.判断登录是否成功
        if(rs.next()){
            System.out.println("登录成功~~");
        }else{
            System.out.println("登陆失败!!");
        }

        //7.释放对象
        myJDBC.close(rs,pstmt,conn);
    }
}
