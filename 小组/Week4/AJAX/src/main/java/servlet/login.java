package servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

import USER.User;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import service.*;

@WebServlet("/login")
public class login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        req.setCharacterEncoding("utf-8");
//        String username = req.getParameter("username");
//        String password = req.getParameter("password");
        String username = new String(req.getParameter("username").getBytes(StandardCharsets.ISO_8859_1));
        String password = new String(req.getParameter("password").getBytes(StandardCharsets.ISO_8859_1));
        resp.setContentType("text/html;charset=UTF-8");
        User user = null;
        try {
            user = userService.login(username, password);
        } catch (Exception e) {
            e.printStackTrace();
        }
        if(user != null) {
            String jsonStr = JSON.toJSONString(user);
            System.out.println(jsonStr);
            Map<String, Object> map = new HashMap<>();
            map.put("status", 200);
            map.put("data", jsonStr);
            map.put("msg", "登录成功");
            try {
                userService.responseJson(resp.getWriter(), map);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        else{
            userService.responseJson(resp.getWriter(),"");
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
