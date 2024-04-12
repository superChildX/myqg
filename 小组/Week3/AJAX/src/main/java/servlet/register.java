package servlet;

import USER.User;
import com.alibaba.fastjson.JSON;
import service.userService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.sql.SQLException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

@WebServlet("/register")
public class register extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = new String(req.getParameter("username").getBytes(StandardCharsets.ISO_8859_1));
        String password = new String(req.getParameter("password").getBytes(StandardCharsets.ISO_8859_1));
        int age = Integer.parseInt(new String(req.getParameter("age").getBytes(StandardCharsets.ISO_8859_1)));
        String gender = new String(req.getParameter("gender").getBytes(StandardCharsets.ISO_8859_1));
        gender = ("1".equals(gender))?"男":"女";
        resp.setContentType("text/html;charset=UTF-8");


        User user = null;
        try {
            user = userService.register(username, password, age, gender);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        if(user != null){
            String jsonStr = JSON.toJSONString(user);
            Map<String, Object> map = new HashMap<>();
            map.put("status",200);
            map.put("data",jsonStr);
            resp.getWriter().write("<h3>注册成功</h3>");
            resp.getWriter().write("<hr>");
            try {
                userService.responseJson(resp.getWriter(),map);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        else
            resp.getWriter().write("<h3>注册失败</h3>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
