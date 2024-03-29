package multithreading;
// Java code for thread creation by extending
// the Thread class
class MultithreadingDemo1 extends Thread {
	public void run()
	{
		try {
			// Displaying the thread that is running
			System.out.println(
				"Thread " + Thread.currentThread().getId()
				+ " is running");
		}
		catch (Exception e) {
			// Throwing an exception
			System.out.println("Exception is caught");
		}
	}
}

// Main Class
public class multithreading_thread {
	public static void main(String[] args)
	{
		int n = 8; // Number of threads
		for (int i = 0; i < n; i++) {
			MultithreadingDemo object
				= new MultithreadingDemo();
			object.start();
            try{
            object.join();
            }
            catch(InterruptedException e){
                System.out.println("unable to wait for thread!");
            }
		}
	}
}
