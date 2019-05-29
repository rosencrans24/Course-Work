

import com.mysql.jdbc.*;

import javax.swing.plaf.nimbus.State;
import java.sql.*;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.util.Scanner;


public class Main {
    static long executionTime=0;
    static long count=0;
    //connect to database.
    /*Additional info:
    //IP of database:     128.123.64.32
    //String url = "jdbc:mysql://dbclass.cs.nmsu.edu:3306/cs482502fa18_kborneme";*/
    public static Connection getConnection() throws Exception{
        try {
            String driver = "com.mysql.cj.jdbc.Driver";
            String url = "jdbc:mysql://dbclass.cs.nmsu.edu:3306/cs482502fa18_jrosencr?useUnicode=true&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC";
            String username = "jrosencr";
            String password = "8MtXzQ62";
            Class.forName(driver);

            Connection connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected");
            return connection;
        }
        catch(Exception e) {
            System.out.println(e); }

        return null;
    }

    //create table if it doesn't exist. Do nothing if it does exist.
    public static void createTable() throws Exception{
        try{
            Connection connection = getConnection();//once we call this, we are connected to DB and ready to modify it.


            //the following commented out code is the format for creating a table.
            /*PreparedStatement create = connection.prepareStatement("CREATE TABLE IF NOT EXISTS " +
                    "tablename(id int NOT NULL AUTO_INCREMENT, first varchar(255), last varchar(255), PRIMARY KEY(id))");

            create.executeUpdate();*/

            PreparedStatement create = connection.prepareStatement("CREATE TABLE IF NOT EXISTS " +
                    "tablename(id int NOT NULL AUTO_INCREMENT, first varchar(255), last varchar(255), PRIMARY KEY(id))");

            create.executeUpdate();

        }
        catch (Exception e) {
            System.out.println(e);
        }
        finally{
                System.out.println("Function completed.");
        }
    }

    public static int insert(String SQL_Insertion, Connection connection ){
        long startTime = System.currentTimeMillis();
        long endTime = System.currentTimeMillis();
        final String var1 = "John";
        final String var2 = "Miller";

        try {

            //PreparedStatement posted = connection.prepareStatement("INSERT INTO tablename (first, last) VALUES ('"+var1+"', '"+var2+"' )");
            PreparedStatement posted = connection.prepareStatement(SQL_Insertion);
            posted.executeUpdate();
        }

        catch(Exception e) {
            System.out.println(e);
            return 0;
        }
        finally {
            System.out.println("Insert Completed");
            endTime = System.currentTimeMillis();
            executionTime = endTime- startTime;

            return 1;
        }
    }
    public static int insertBulk(String f, String s){
        try {
            Connection connection = getConnection();
            Statement ps = connection.createStatement();
            String fileName = f;
            String tableName = s;
            String sql= "LOAD DATA INFILE \'"+fileName+ "\' INTO TABLE " + tableName + " FIELDS TERMINATED BY ','" +"LINES TERMINATED BY '\\n'" ;
            ps.executeUpdate(sql);
            /*File f = new File( file );
            BufferedReader reader = new BufferedReader( new FileReader( f ) );
            String line = reader.readLine( );
            while( line != null ){
                String line1 = "INSERT into " + s + " VALUES ("+ line + ")";
                ps.addBatch( line1 );
                line = reader.readLine( );
            }
            ps.executeBatch();
            ps.close( );*/

        }

        catch(Exception e) {
            System.out.println(e);
            return 0;
        }
        finally {
            System.out.println("Insert Completed");
            return 1;
        }
    }

    public static int insertion( String s, int n ){
        int res = 0;
        long startTime = System.currentTimeMillis();
        long endTime = System.currentTimeMillis();
        String file = "C:/Users/rosen/OneDrive/Documents/School/src/" + s;
        s = s.replace( ".txt","" );
        if( n == 0 ){
            try{
                Connection connection = getConnection();
                BufferedReader reader = new BufferedReader( new FileReader( new File ( file ) ) );
                String line = reader.readLine( );
                while( line != null ){
                    String line1 = "INSERT into " + s + " VALUES ("+ line + ")";
                    res = insert( line1, connection );
                    if( res == 0 ) {
                        endTime = System.currentTimeMillis();
                        break;
                    }
                    line = reader.readLine( );
                }
                endTime = System.currentTimeMillis();
            }
            catch( Exception e ){
                e.printStackTrace( );
            }
        }
        else if( n == 1 ){
            res = insertBulk( file, s );
            endTime = System.currentTimeMillis();
        }
        executionTime = endTime - startTime;
        return res;
    }


    public static ArrayList<String> query(String SQL_Query) throws Exception{
        try{
            Connection connection = getConnection();

            /*PreparedStatement statement = connection.prepareStatement("SELECT first, last FROM tablename WHERE first = 'John' " );*/
            PreparedStatement statement = connection.prepareStatement(SQL_Query);
            ResultSet result = statement.executeQuery();

            ArrayList<String> array = new ArrayList<String>();
            while(result.next()) {
                System.out.println(result.getString("first"));
                System.out.print(" ");
                System.out.println(result.getString("last"));

                array.add(result.getString("last"));
            }

            System.out.println("All records have been selected");
            return array;

        }
        catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }

    public static ResultSet queryRS(String SQL_Query) throws Exception{
        try{
            Connection connection = getConnection();

            /*PreparedStatement statement = connection.prepareStatement("SELECT first, last FROM tablename WHERE first = 'John' " );*/
            PreparedStatement statement = connection.prepareStatement(SQL_Query);
            ResultSet result = statement.executeQuery();

//            ArrayList<String> array = new ArrayList<String>();
//            while(result.next()) {
//                System.out.println(result.getString("first"));
//                System.out.print(" ");
//                System.out.println(result.getString("last"));
//
//                array.add(result.getString("last"));
//            }
//
//            System.out.println("All records have been selected");
            return result;

        }
        catch (Exception e) {
            System.out.println(e);
        }
        return null;
    }


    public static void deleteAllDataFromTable(String tableName) {

        long startTime = System.currentTimeMillis();
        long endTime = System.currentTimeMillis();

        try {
            Connection connection = getConnection();
            Statement statement = connection.createStatement();
            // Use TRUNCATE
            // String sql = "TRUNCATE " + tableName;
            // Execute deletion
            //statement.executeUpdate(sql);
            // Use DELETE
            String sql = "DELETE FROM " + tableName;
            // Execute deletion
            statement.executeUpdate(sql);
        }

        catch(Exception e) {
            System.out.println(e);
        }
        finally {
            System.out.println("Delete Completed");
        }
        endTime = System.currentTimeMillis();
        executionTime = endTime - startTime;
    }








    /*public static void main(String[] args) throws Exception{

        Scanner scan = new Scanner(System.in);
        int DB_Command;

        //createTable calls connect method.
        createTable();

        System.out.println("What would you like to do with the DataBase? \n Enter the corresponding number:");
        System.out.println("1 ---------- INSERT (single) \n 2 ---------- BULK LOAD \n 3 ---------- QUERY \n 4 --------- DELETE");
        DB_Command = scan.nextInt();

        if(DB_Command == 1) { //single insertion
            //Insert into Database
            System.out.println(" \n Enter a MYSQL intertion. \n Similar syntax could be the following: \n INSERT INTO tablename (id, first, last) VALUES ('10', 'Rick', 'Miller')");
            String SQL_Insertion = scan.nextLine();
            SQL_Insertion = scan.nextLine();
            //String SQL_InsertionExample = "INSERT INTO tablename (id, first, last) VALUES ('10', 'Rick', 'Miller')";
            insert(SQL_Insertion);

        }
        else if (DB_Command == 2) { //Bulk Load

        }
        else if (DB_Command == 3) { //Query
            System.out.println(" \n Enter a MYSQL query. \n Similar syntax could be the following: \n \"SELECT first FROM tablename WHERE id = 1 \n or it could be" +
                    " \"SELECT * FROM tablename WHERE first = 'John'");
            String SQL_Query = scan.nextLine();
            SQL_Query = scan.nextLine();
            query(SQL_Query);
        }
        else if (DB_Command == 4) { //Delete

        }
        else {
            //System.exit(0);
        }




//        //Insert into Database
//        System.out.println(" \n Enter a MYSQL intertion. \n Similar syntax could be the following: \n INSERT INTO tablename (id, first, last) VALUES ('10', 'Rick', 'Miller')");
//        String SQL_Insertion = scan.nextLine();
//        String SQL_InsertionExample = "INSERT INTO tablename (id, first, last) VALUES ('10', 'Rick', 'Miller')";
//        insert(SQL_Insertion);

       /* //Query the Database
        System.out.println(" \n Enter a MYSQL query. \n Similar syntax could be the following: \n \"SELECT first FROM tablename WHERE id = 1 \n or it could be" +
                        " \"SELECT * FROM tablename WHERE first = 'John'");
        String SQL_Query = scan.nextLine();
        query(SQL_Query);




    } */
}
