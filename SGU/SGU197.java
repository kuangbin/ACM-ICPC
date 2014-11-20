import java.util.*;
import java.io.*;
import java.math.*;

public class Solution
{
	static int P;
	class Matrix{
		int [][]mat = new int[100][100];
		int n;
		void init(int _n){
			n = _n;
			//Arrays.fill(mat, 0);
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++)
					mat[i][j] = 0;
		}
		Matrix mul(Matrix b){
			Matrix ret = new Matrix();
			ret.init(n);
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++){
					for(int k = 0;k < n;k++){
						ret.mat[i][j] = ret.mat[i][j] + mat[i][k]*b.mat[k][j]%P;
						ret.mat[i][j] %= P;
					}
				}
			return ret;
		}
	}
	static Matrix pow_M(Matrix a,BigInteger n){
		Matrix ret = new Solution().new Matrix();
		Matrix tmp = a;
		ret.init(a.n);
		for(int i = 0;i < a.n;i++)
			ret.mat[i][i] = 1;
		while(!n.equals(BigInteger.ZERO)){
			if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
				ret = ret.mul(tmp);
			tmp = tmp.mul(tmp);
			n = n.divide(BigInteger.valueOf(2));
		}
		return ret;
	}
	static boolean check(int s1,int s2,int n){
		for(int i = 0;i < n-1;i++){
			if( (s1&(1<<i)) == 0 && (s1&(1<<(i+1))) == 0 
					&& (s2&(1<<i)) == 0 && (s2&(1<<(i+1))) == 0)
				return false;
			if( (s1&(1<<i)) > 0 && (s1&(1<<(i+1))) > 0 
					&& (s2&(1<<i)) > 0 && (s2&(1<<(i+1))) > 0)
				return false;
		}
		return true;
	}
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		BigInteger n;
		int m;
		while(cin.hasNext()){
			n = cin.nextBigInteger();
			m = cin.nextInt();
			P = cin.nextInt();
			Matrix a = new Solution().new Matrix();
			a.init(1<<m);
			for(int i = 0;i < (1<<m);i++)
				for(int j = 0;j < (1<<m);j++)
					if(check(i,j,m))
						a.mat[i][j] = 1;
			a = pow_M(a,n.subtract(BigInteger.ONE));
			int ans = 0;
			for(int i = 0;i < (1<<m);i++)
				for(int j = 0;j < (1<<m);j++){
					ans = ans + a.mat[i][j];
					ans = ans%P;
				}
			System.out.println(ans);
		}

	}

}
