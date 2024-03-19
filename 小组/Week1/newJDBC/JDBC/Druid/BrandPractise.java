package Druid;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Properties;
import java.util.Scanner;

public class BrandPractise {
    public static void main(String[] args) throws Exception {

        //1.连接并注册驱动
        DataSource dts = myDruid.getDTS();
        Connection conn = myDruid.getConnect(dts);

        int choice;
        //2.定义sql语句
        while (true) {
            System.out.println("1.增");
            System.out.println("2.删");
            System.out.println("3.改");
            System.out.println("4.查");
            System.out.println("0.退出");
            choice = Scan();
            switch (choice){
                case 1:
                    add(conn);
                    break;
                case 2:
                    delete(conn);
                    break;
                case 3:
                    update(conn);
                    break;
                case 4:
                    check(conn);
                    break;
                case 0:
                    break;
            }
            if(choice == 0)
                break;
        }
        conn.close();
    }

    public static int Scan(){
        while (true) {
            try {
                Scanner sc = new Scanner(System.in);
                int choice = sc.nextInt();
                if (choice <= 4 && choice >=1)
                    return choice;
                else {
                    System.out.println("输入1-4的数字哟");
                    continue;
                }
            } catch (InputMismatchException e) {
                System.out.println("只能输入数字哟");
            }
        }
    }

    public static int Scan(int x){
        while (true) {
            try {
                Scanner sc = new Scanner(System.in);
                int choice = sc.nextInt();
                return choice;
            } catch (InputMismatchException e) {
                System.out.println("只能输入数字哟");
            }
        }
    }

    public static void add(Connection conn) throws Exception {
        String brandName = "香飘飘";
        String companyName = "香飘飘";
        int ordered = 1;
        String description = "绕地球一圈";
        int status = 1;

        String sql = "insert into tb_brand(brand_name, company_name, ordered, description, status) values(?,?,?,?,?);";

        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setString(1,brandName);
        pstmt.setString(2,companyName);
        pstmt.setInt(3,ordered);
        pstmt.setString(4,description);
        pstmt.setInt(5,status);

        int count = pstmt.executeUpdate();
        if( count > 0 ){
            System.out.println("增加成功");
        }else{
            System.out.println("增加失败");
        }

        pstmt.close();
    }

    public static void delete(Connection conn) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入要删除的产品id：");
        int id = Scan(1);

        String sql = "delete from tb_brand where id = ?;";

        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setInt(1,id);

        int count = pstmt.executeUpdate();

        System.out.println((count > 0));
        pstmt.close();
    }

    public static void update(Connection conn) throws Exception {
        String brandName = "香喷喷";
        String companyName = "香飘飘";
        int ordered = 1000;
        String description = "绕地球三圈";
        int status = 1;
        int id = 4;

        String sql = "update tb_brand\n" +
                "        set brand_name = ?,\n" +
                "        company_name =  ?,\n" +
                "        ordered      =  ?,\n" +
                "        description  =  ?,\n" +
                "        status       =  ?\n" +
                "        where id = ?";

        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setString(1,brandName);
        pstmt.setString(2,companyName);
        pstmt.setInt(3,ordered);
        pstmt.setString(4,description);
        pstmt.setInt(5,status);
        pstmt.setInt(6,id);

        int count = pstmt.executeUpdate();
        System.out.println((count > 0));
        pstmt.close();

    }

    public static void check(Connection conn) throws Exception {

        String sql = "select * from tb_brand";
        //3.获取preparedStatement对象
        PreparedStatement pstmt = conn.prepareStatement(sql);
        //4.执行sql
        ResultSet rs = pstmt.executeQuery();
        ArrayList<Brand> brands = new ArrayList<>();
        Brand brand;
        while(rs.next()){
            int id = rs.getInt("id");
            String brandName = rs.getString("brand_name");
            String companyName = rs.getString("company_name");
            int ordered = rs.getInt("ordered");
            String description = rs.getString("description");
            int status = rs.getInt("status");
            brand = new Brand(id,brandName,companyName,ordered,description,status);
            brands.add(brand);
        }
        System.out.println(brands);
        pstmt.close();
    }
}
