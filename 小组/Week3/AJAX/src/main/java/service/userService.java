package service;

import java.io.IOException;
import java.io.Writer;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Map;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.support.hsf.HSFJSONUtils;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.databind.ObjectMapper;

import USER.User;
import com.fasterxml.jackson.databind.SerializationFeature;

public class userService {
    //登录查询数据库斌返回查询结果
    public static User login(String name, String pwd) throws Exception{
        Connection conn = JDBC.getConn();
        String sql = "select * from stus where loginName = ? and loginPwd = ?;";
        PreparedStatement pstmt = JDBC.getPs(conn,sql);
        pstmt.setString(1,name);
        pstmt.setString(2,pwd);
        ResultSet rs = pstmt.executeQuery();
        if(rs.next()){
            int id = rs.getInt(1);
            int age = rs.getInt(4);
            String gender = rs.getString(5);
            User user = new User(name,pwd,id,gender,age);
            JDBC.close(rs,pstmt,conn);
            return user;
        }
        else{
            JDBC.close(rs,pstmt,conn);
            return null;
        }
    }

    public static User register(String name, String pwd, int age, String gender) throws SQLException {
        User user = new User(name,pwd,gender,age);
        Connection conn = null;
        PreparedStatement pstmt = null;
        try{
            conn = JDBC.getConn();
            String sql = "insert into stus(id, loginName, loginPwd, age, gender) values(?,?,?,?,?);";
            pstmt = JDBC.getPs(conn,sql);
            pstmt.setString(1,null);
            pstmt.setString(2,name);
            pstmt.setString(3,pwd);
            pstmt.setInt(4,age);
            pstmt.setString(5,gender);
            int result = pstmt.executeUpdate();
            if(result != 0)
                return user;
            else
                return null;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (conn != null) {
                conn.close();
            }
            if (pstmt != null) {
                pstmt.close();
            }
        }
        return user;
    }
    //登录成功与否的页面响应
    public static void responseJson(Writer writer, Map<String, Object> map) throws Exception {
        String json = (String) map.get("data");
        User user = (User) JSON.parseObject(json, User.class);
        writer.write("<h3>尊敬的" + user.getUsername() + "您好</h3>");
        writer.write("<hr>");
        writer.write("个人信息:<br>");
        writer.write("账号:" + user.getUsername() + "<br>");
        writer.write("密码:" + user.getPassword() + "<br>");
        writer.write("性别:" + user.getGender() + "<br>");
        writer.write("年龄:" + user.getAge() + "<br>");
    }
    public static void responseJson(Writer writer, String err) throws IOException {
        writer.write("<h3>登录失败</h3><br>");
        writer.write("密码或账号错误");
    }
}
