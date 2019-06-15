import java.lang.Math;

public class Bisekcija {
    public static void main(String[] args) {
        //začetni interval
        double a = 0.5;
        double b = 1.0;

        for(int stKorakov = 0; stKorakov<20; stKorakov++) {
            double c = (a+b)/2.0;
            double fc = enacba(c);

            double fa = enacba(a); double fb = enacba(b);
            System.out.printf("a: %.6f | fa: %.6f %nb: %.6f | fb: %.6f %nc: %.6f | fc:%.6f %n%n",a,fa,b,fb,c,fc);

            if(fa < 0 && fb > 0){
                if(fc < 0)
                    a = c;
                else
                    b = c;

            } else if(fa > 0 && fb < 0) {
                if(fc < 0)
                    b = c;
                else
                    a = c;

            } else
                break;

        }
    }

    private static double enacba(double x) {
        return (x+Math.log(x));
        //(Math.pow(x,3) - Math.cos(x));
    }
}
