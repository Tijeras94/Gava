
class Hello{

    public static native void Print(int num);
    public static native void Print(double num);
    public static native void Print(float num);
    public static int factorial(int n){
		if(n==0) return 1; 
		else return (n* factorial(n-1));
    }   
	
    public static void main(String args[]){
        //int num1 = 20;
        //int num2 = 20;

        //int sum = factorial(5)   + 10;
        
        //Print(sum);
        float name = 0;
        int i= 0;
        while(i<10){
          //Print(i);
          i++;
          name += 2.5f;
        }
        Print(name);


    }
}