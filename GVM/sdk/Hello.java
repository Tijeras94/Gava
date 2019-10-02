
class Hello{

    public static native void Print(int num);

    public static void main(String args[]){
        int num1 = 20;
        int num2 = 20;

        int sum = num1 + num2;
        
        Print(sum);

    }
}