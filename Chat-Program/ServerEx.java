package ServerProgram;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerEx {

	public static void main(String[] args) throws IOException {

		ServerSocket listener = null;
		Socket socket = null;

		listener = new ServerSocket(9999);
		System.out.println("������ ��ٸ��� �ֽ��ϴ�.....");
		socket = listener.accept();
		System.out.println("����Ǿ����ϴ�.");
		ServerThread1 server1 = new ServerThread1(socket);
		ServerThread2 server2 = new ServerThread2(socket);

		server1.start();
		server2.start();
		
		try {
			server2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}finally {
			socket.close();
			listener.close();
		}
	}
}
