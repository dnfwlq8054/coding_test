public class Graceful_Year{

    static boolean checkYear(int year){
        boolean[] isCheck = new boolean[10];

        while(year != 0){
            if(!isCheck[year % 10]) isCheck[year % 10] = true;
            else return false;
            year /= 10;
        }

        return true;
    }

    public static void main(String[] args){
        int year = 2200;

        while(true){
            if(checkYear(++year)) break;
        }

        System.out.println(year);
    }
}
