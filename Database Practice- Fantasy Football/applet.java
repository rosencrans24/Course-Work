import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.util.*;


public class applet extends JFrame
{
    JPanel jp = new JPanel();
    JLabel jl = new JLabel();

    JTextField qt = new JTextField(20);
    JTextField st = new JTextField(20);
    JTextField bt = new JTextField(20);
    JTextField dt = new JTextField(20);

    JButton qu = new JButton("Query");
    JButton si = new JButton("Single Insert");
    JButton bi = new JButton("Bulk Load");
    JButton del = new JButton("Delete");

    JTable table;


    public applet()
    {
        jp.setLayout( new BoxLayout( jp, BoxLayout.Y_AXIS ));
        setTitle("Project Phase 2");
        setVisible(true);
        setSize(1000, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        jp.add(qt);



        qt.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {

            }
        });

        jp.add(qu);
        qu.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) {
                String input = qt.getText();
                try {
                    ResultSet rs = Main.queryRS(input);
                    table = new JTable(buildTableModel(rs));
                    JOptionPane.showMessageDialog(null, new JScrollPane(table));
                } catch (Exception l) {
                    l.printStackTrace();

                }
            }
        });
        jp.add(st);
        jp.add(si);
        si.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                String input = st.getText( );
                int res = Main.insertion( input, 0 );
                System.out.println(Main.executionTime);
            }
        });
        jp.add(bt);
        jp.add(bi);
        bi.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                String input = bt.getText( );
                int res = Main.insertion( input, 1 );
                System.out.println(Main.executionTime);
            }
        });
        jp.add(dt);
        jp.add(del);
        del.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e)
            {
                String input = dt.getText( );
                Main.deleteAllDataFromTable(input);
            }
        });


        jp.add( jl );
        add(jp);

    }

    public static DefaultTableModel buildTableModel(ResultSet rs)
            throws SQLException {

        ResultSetMetaData metaData = rs.getMetaData();

        // names of columns
        Vector<String> columnNames = new Vector<String>();
        int columnCount = metaData.getColumnCount();
        for (int column = 1; column <= columnCount; column++) {
            columnNames.add(metaData.getColumnName(column));
        }

        // data of the table
        Vector<Vector<Object>> data = new Vector<Vector<Object>>();
        while (rs.next()) {
            Vector<Object> vector = new Vector<Object>();
            for (int columnIndex = 1; columnIndex <= columnCount; columnIndex++) {
                vector.add(rs.getObject(columnIndex));
            }
            data.add(vector);
        }

        return new DefaultTableModel(data, columnNames);

    }
    public static void main(String[] args)
    {
        applet t = new applet();
    }
}