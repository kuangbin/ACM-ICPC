import java.util.*;
import java.math.*;

public class Solution
{
	public static void main(String []arg){
		Scanner cin = new Scanner(System.in);
		BigInteger n = cin.nextBigInteger();
		if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)){
			System.out.println(n.divide(BigInteger.valueOf(2)));
		}
		else {
			BigInteger n2 = n.divide(BigInteger.valueOf(2));
			n2 = n2.subtract(BigInteger.ONE);
			if(n2.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
				n2 = n2.subtract(BigInteger.ONE);
			System.out.println(n2);
		}
	}
}

