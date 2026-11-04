package ex11;

import java.io.*;
import java.util.regex.*;

public class ResumeFormatter {

    public static void main(String[] args) {

        File inputFolder = new File("input_resumes");
        File outputFolder = new File("cleaned_resumes");

        // Check whether input folder exists
        if (!inputFolder.exists()) {
            System.out.println("Input folder not found!");
            return;
        }

        // Create output folder if it does not exist
        if (!outputFolder.exists()) {
            outputFolder.mkdir();
        }

        // Read all files from input folder
        File[] files = inputFolder.listFiles();

        if (files == null) {
            System.out.println("Unable to read input folder!");
            return;
        }

        // Process each text file
        for (File file : files) {
            if (file.isFile() && file.getName().endsWith(".txt")) {
                processResume(file, outputFolder);
            }
        }

        System.out.println("All resumes formatted successfully!");
    }

    static void processResume(File file, File outputFolder) {

        String name = "Not Found";
        String email = "Not Found";
        String skills = "Not Found";

        Pattern emailPattern = Pattern.compile(
            "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}"
        );

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {

            String line;

            while ((line = br.readLine()) != null) {

                // Extract Name
                if (line.toLowerCase().contains("name:")) {
                    name = line.split(":", 2)[1].trim();
                }

                // Extract Email using Regular Expression
                Matcher matcher = emailPattern.matcher(line);

                if (matcher.find()) {
                    email = matcher.group();
                }

                // Extract Skills
                if (line.toLowerCase().contains("skills:")) {
                    skills = line.split(":", 2)[1].trim();
                }
            }

            // Create output file
            File outputFile = new File(
                outputFolder, "Formatted_" + file.getName()
            );

            // Write formatted resume
            try (FileWriter writer = new FileWriter(outputFile)) {

                writer.write("========== FORMATTED RESUME ==========\n");
                writer.write("Name   : " + name + "\n");
                writer.write("Email  : " + email + "\n");
                writer.write("Skills : " + skills + "\n");
                writer.write("======================================\n");
            }

            System.out.println("Processed: " + file.getName());

        } catch (IOException e) {
            System.out.println("Error processing file: " + file.getName());
        }
    }
}


