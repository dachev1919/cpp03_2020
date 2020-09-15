package com.company;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;
// імпортування статичних змінних і методів класу Math

public class Main {
    public static void main(String[] args) {
        Main prog = new Main();
        prog.run();
    }
    private static void date(){
        // Инициализация объекта date
        Date date = new Date();
        // Вывод текущей даты с использованием toString()
        System.out.printf("%1$s %2$td %2$tB %2$tY", "Дата:", date);
    }

    private void print(double a, double b, double t) {
        System.out.println("a = "+a);
        System.out.println("b = "+b);
        System.out.println("t = "+t);
        double y = exp(-b * t) * sin(a * t + b) - sqrt(abs(b * t + a));
        System.out.println("y = exp(-b * t) * sin(a * t + b) - sqrt(abs(b * t + a))");
        System.out.println("y = "+y);
    }

    private double calcSquare(double x){
        return x * x;
    }

    private void primer(){
        Scanner sc = new Scanner(System.in);
        System.out.printf("------------------------------------------------");
        System.out.printf("\na - ");
        double a = sc.nextDouble();
        System.out.printf("b - ");
        double b = sc.nextDouble();
        System.out.printf("t - ");
        double t = sc.nextDouble();
        double s = b * sin(calcSquare((a*t)) * cos(2 * t)) -1;
        System.out.println("s = b * sin(calcSquare((a*t)) * cos(2 * t)) -1");
        System.out.println("s = "+s);
    }

    private void run() {
        Scanner s = new Scanner(System.in);
        System.out.printf("a - ");
        double a = s.nextDouble();
        System.out.printf("b - ");
        double b = s.nextDouble();
        System.out.printf("t - ");
        double t = s.nextDouble();
        print(a, b, t);
        primer();
        date();
    }
}
