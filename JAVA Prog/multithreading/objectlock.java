// Java program to illustrate
package multithreading;

class objectlock implements Runnable {
	public void run() { Lock(); }
	public void Lock()
	{
		System.out.println(
			Thread.currentThread().getName());
		synchronized (this)
		{
			System.out.println(
				"in block "
				+ Thread.currentThread().getName());
			System.out.println(
				"in block "
				+ Thread.currentThread().getName()
				+ " end");
		}
	}

	public static void main(String[] args)
	{
		objectlock g = new objectlock();
		Thread t1 = new Thread(g);
		Thread t2 = new Thread(g);
		objectlock g1 = new objectlock();
		Thread t3 = new Thread(g1);
		t1.setName("t1");
		t2.setName("t2");
		t3.setName("t3");
		t1.start();
		t2.start();
		t3.start();
	}
}
