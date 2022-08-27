import java.util.Arrays;
import java.util.Comparator;

public class StraightLine {
    public static boolean checkStraightLine(int[][] coordinates){
        boolean isValid = true;
        int dx = coordinates[1][0] - coordinates[0][0]; // dx = x1 - x0
        int dy = coordinates[1][1] - coordinates[0][1]; // dy = y1 - y0

        for(int i=2; i<coordinates.length; i++){
            int dxi = coordinates[i][0] - coordinates[i-1][0]; // dxi = xi - xi-1
            int dyi = coordinates[i][1] - coordinates[i-1][1]; // dyi = yi - yi-1

            if(dx !=0 && dxi != 0){
                double m = (double) dy/dx;
                double mi = (double) dyi/dxi;
                if(m!=mi){
                    isValid = false;
                    break;
                }
            } else if (dx!=dxi) {
                isValid = false;
                break;
            }
        }
        return isValid;
    }
}
