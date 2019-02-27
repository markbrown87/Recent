/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Mark Brown (mark.brown@gmail.com)
 */

import java.io.*;

public class mainScreen extends javax.swing.JFrame {
    
    /**
     * Creates new form mainScreen
     */
    public mainScreen() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        twoByTwo = new javax.swing.JButton();
        fourByFour = new javax.swing.JButton();
        welcomeText = new javax.swing.JLabel();
        threeByThree = new javax.swing.JButton();
        compile = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        dialogBox = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Main Screen");

        twoByTwo.setText("2x2 Puzzle");
        twoByTwo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                twoByTwoActionPerformed(evt);
            }
        });

        fourByFour.setText("4x4 Puzzle");
        fourByFour.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                fourByFourActionPerformed(evt);
            }
        });

        welcomeText.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        welcomeText.setText("Welcome!");

        threeByThree.setText("3x3 Puzzle");
        threeByThree.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                threeByThreeActionPerformed(evt);
            }
        });

        compile.setText("Compile");
        compile.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                compileActionPerformed(evt);
            }
        });

        dialogBox.setEditable(false);
        dialogBox.setColumns(20);
        dialogBox.setRows(5);
        jScrollPane1.setViewportView(dialogBox);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(welcomeText, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(twoByTwo, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 76, Short.MAX_VALUE)
                    .addComponent(fourByFour, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(threeByThree, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(compile, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 638, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(welcomeText, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(twoByTwo)
                        .addGap(15, 15, 15)
                        .addComponent(threeByThree)
                        .addGap(12, 12, 12)
                        .addComponent(fourByFour)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 159, Short.MAX_VALUE)
                        .addComponent(compile)))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void twoByTwoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_twoByTwoActionPerformed
        String pythonScript = "python3 /home/testbot1/Repos/Recent/C++/Sudoku_Solver/scraper.py 2"; 
        String binFile = "/home/testbot1/Repos/Recent/C++/Sudoku_Solver/bin/2x2.bin";
        //String cd = "cd /home/testbot1/Repos/Recent/C++/Sudoku_Solver/"; cd + " && "
        //String cFile = "./SudokuSolver";
        String cFile = "/home/testbot1/Repos/Recent/C++/Sudoku_Solver/SudokuSolver";
        String cProgram = cFile + " < " + binFile;
        
        System.out.println("Running python script... ");
        //performExec(pythonScript);
        System.out.println("Python script Finished... ");
        System.out.println("PATH: " + cProgram);
        System.out.println("Running c++ program... ");
        
        //ProcessBuilder pb1 = new ProcessBuilder("cd", "/home/testbot1/Repos/Recent/C++/Sudoku_Solver/");
        ProcessBuilder pb2 = new ProcessBuilder("/home/testbot1/Repos/Recent/C++/Sudoku_Solver/SudokuSolver", " < " + binFile);
        try{
            //Process proc = pb1.start();
            //if(proc.waitFor() == 0){
                //System.out.println("No error...");
            //} else { System.out.println("Errors 1..."); }
            Process proc2 = pb2.start();
            if(proc2.waitFor() == 0){
                System.out.println("No error...");
            } else { System.out.println("Errors 2..."); }
            
            String tmp = null;
            
            
            BufferedReader in = new BufferedReader(new InputStreamReader(proc2.getInputStream()));
            BufferedReader err = new BufferedReader(new InputStreamReader(proc2.getErrorStream()));

            while ((tmp = err.readLine()) != null){
                System.out.println(tmp);
                dialogBox.setText(dialogBox.getText() + tmp + "\n");
            }
            err.close();

            while ((tmp = in.readLine()) != null){
                System.out.println(tmp);;
                dialogBox.setText(dialogBox.getText() + tmp + "\n");
            }
            in.close();
            
            
            //proc.destroy();
            proc2.destroy();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        catch (InterruptedException e){
            e.printStackTrace();
        }
        //performExec(cProgram);
        System.out.println("c++ program finished... ");
    }//GEN-LAST:event_twoByTwoActionPerformed

    private void fourByFourActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_fourByFourActionPerformed
        String pythonScript = "python3 /home/testbot1/Repos/Recent/C++/Sudoku_Solver/scraper.py 4"; 
        

        performExec(pythonScript);
    }//GEN-LAST:event_fourByFourActionPerformed

    private void threeByThreeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_threeByThreeActionPerformed
        String pythonScript = "python3 /home/testbot1/Repos/Recent/C++/Sudoku_Solver/scraper.py 3"; 
        

        performExec(pythonScript);
        
    }//GEN-LAST:event_threeByThreeActionPerformed

    private void compileActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_compileActionPerformed
      
        String makeFile = "g++ /home/testbot1/Repos/Recent/C++/Sudoku_Solver/SudokuSolver.cc -o /home/testbot1/Repos/Recent/C++/Sudoku_Solver/SudokuSolver";
        performExec(makeFile);
        
    }//GEN-LAST:event_compileActionPerformed

    private void performExec(String execCom){
        Process proc = null;
        String tmp = null;
        
        try {
            System.out.println("Trying to execute...");
            proc = Runtime.getRuntime().exec(execCom);
            System.out.println("Executed...");
            
            //proc.waitFor();
            
            System.out.println(proc);
            if(proc != null){
                
                BufferedReader in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
                BufferedReader err = new BufferedReader(new InputStreamReader(proc.getErrorStream()));
                
                //proc.waitFor();
                

                while ((tmp = err.readLine()) != null){
                    System.out.println(err.readLine());
                    dialogBox.setText(dialogBox.getText() + tmp + "\n");
                }
                err.close();

                while ((tmp = in.readLine()) != null){
                    System.out.println(in.readLine());;
                    dialogBox.setText(dialogBox.getText() + tmp + "\n");
                }
                in.close();
                 
                proc.destroy();
            }
        }
        catch(IOException e){
            dialogBox.setText(dialogBox.getText() + "\nAn IOException was tripped...\n");
            e.printStackTrace();
        }  
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(mainScreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(mainScreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(mainScreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(mainScreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mainScreen().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton compile;
    private javax.swing.JTextArea dialogBox;
    private javax.swing.JButton fourByFour;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton threeByThree;
    private javax.swing.JButton twoByTwo;
    private javax.swing.JLabel welcomeText;
    // End of variables declaration//GEN-END:variables
}