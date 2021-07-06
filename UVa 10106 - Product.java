import java.math.BigInteger;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		BigInteger x, y;
		
		while(reader.hasNext()) {
			x = reader.nextBigInteger();
			y = reader.nextBigInteger();
			BigInteger res = x.multiply(y);
			System.out.println(res);
		}
		reader.close();
	}
}
