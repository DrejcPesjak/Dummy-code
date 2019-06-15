import java.lang.Math;

public class RegulaFalsi {
    public static void main(String[] args) {
        //equation: f(x) = x⁷ + x² + 12/5 x -2

        //interval
        double a = 0;
        double b = 1;

        for(int stKorakov = 0; stKorakov < 100; stKorakov++) {
            double fa = enacba(a);
            double fb = enacba(b);

            //naklon premice
            double k = (fa-fb)/(a-b);
            double n = fa - (k*a);

            //presečišče z x osjo
            double c = -n / k;
            double fc = enacba(c);
            //System.out.printf("a: %.6f | fa: %.6f %nb: %.6f | fb: %.6f %nc: %.6f | fc:%.6f %n",a,fa,b,fb,c,fc);
            System.out.println(c);


            if(fa<0 && fb>0){
                if(fc<0)
                    a=c;
                else
                    b=c;

            } else if(fa>0 && fb<0) {
                if(fc<0)
                    b=c;
                else
                    a=c;

            } else
                break;
        }
    }

    private static double enacba(double x) {
        return (Math.pow(x,7) + x*x + (double)(18.0/5.0) *x - 2.0);
    }
}
