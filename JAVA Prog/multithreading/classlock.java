package multithreading;
class classlock implements Runnable {
	public void run() { Lock(); }

	public void Lock()
	{
		System.out.println(
			Thread.currentThread().getName());
		synchronized (classlock.class)
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
		classlock g1 = new classlock();
		Thread t1 = new Thread(g1);
		Thread t2 = new Thread(g1);
		classlock g2 = new classlock();
		Thread t3 = new Thread(g2);
		t1.setName("t1");
		t2.setName("t2");
		t3.setName("t3");
		t1.start();
		t2.start();
		t3.start();
	}
}
