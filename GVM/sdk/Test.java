
class Test{
    public Test(){
      Print(5);
    }

    public static native void Print(int num);
	
    public static void main(String args[]){
      //Test t = new Test();
	  for(int i = 0; i < 10; i++){
	  	  Print(i);
	  }
    }
}