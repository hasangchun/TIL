package ServerProgram;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class ClientThread1 extends Thread {
	Socket socket = null;
	BufferedReader in = null;
	BufferedWriter out = null;
	Scanner sc = new Scanner(System.in);

	ClientThread1(Socket socket) {
		this.socket = socket;
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			while (true) {
				String inputMessage = in.readLine();

				if (inputMessage.equalsIgnoreCase("bye")) {
					System.out.println("Ŭ���̾�Ʈ���� bye�� ������ �����Ͽ���.");
					break;
				}
				System.out.println("���� : " + inputMessage);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
