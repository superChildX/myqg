package servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import JDBC.JDBC;

@WebServlet("/servlet1")
public class servlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setHeader("Content-Type","application/json;charset=utf-8/text/html;charset=UTF-8");
        resp.setContentType("text/html;charset=UTF-8");
        String name = req.getParameter("username");
        String paw = req.getParameter("password");
//        byte[] bytes = name.getBytes(StandardCharsets.ISO_8859_1);
//        name = new String(bytes,StandardCharsets.UTF_8);
        //与上面代码效果一样
        name = new String(name.getBytes(StandardCharsets.ISO_8859_1));
        paw = new String(paw.getBytes(StandardCharsets.ISO_8859_1));
        System.out.println(name + "   " + paw);
        try {
            Connection conn = JDBC.getConn();
            //定义sql语句
            String sql = "select * from stus where loginName = ? and loginPwd = ?;";
            //获取执行sql对象
            PreparedStatement pstmt = JDBC.getPs(conn, sql);
            pstmt.setString(1,name);
            pstmt.setString(2,paw);
            ResultSet rs = pstmt.executeQuery();
            System.out.println(rs);
            if(!rs.next()){
                resp.setStatus(403);
                resp.getWriter().write("<h3>登录失败</h3>");
            }
            else{
                resp.setStatus(200);
                resp.getWriter().write("<h4>loginName:" + rs.getString("loginName") + "</h4><b>\n" +
                        "<h4>loginPassWord:" + rs.getString("loginPwd") + "</h4><b>\n" +
                        "<h3>登录成功</h3>");
            }
            JDBC.close(rs,pstmt,conn);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
