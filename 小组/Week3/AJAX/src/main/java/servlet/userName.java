package servlet;

import com.alibaba.fastjson.JSONObject;
import service.JDBC;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet("/userName")
public class userName extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1.获取用户名
        String username = req.getParameter("username");
        username = new String(username.getBytes(StandardCharsets.ISO_8859_1));
        boolean get = false;
        //2.调用service查询数据库是否存在该用户名
        try {
            //2.1.静态代码块访问数据库并获取conn对象
            Connection conn = JDBC.getConn();
            String sql = "select * from stus where loginName = ?;";
            //2.2.获取pstmt并设置？和执行sql
            PreparedStatement pstmt = JDBC.getPs(conn,sql);
            pstmt.setString(1,username);
            //2.3.获取执行sql的结果
            ResultSet rs = pstmt.executeQuery();
            //2.4.判断查询执行是否成功
            if(rs.next()) {
                get = true;
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        //3.响应标记
        JSONObject object = new JSONObject();
        object.put("d",get);
        resp.getWriter().write(object.toJSONString());
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
