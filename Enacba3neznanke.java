public class Enacba3neznanke {
	public static void main(String[] args) {
		int x = 0;
		int y = 0;
		int z = 0;


		long sestevek = 0;
		
		for(int mm = x; mm<7; mm++){
			for(int ww = y; ww<6; ww++){
				for(int kk = z; kk<9; kk++) {
					sestevek = 7*ww + 8*mm + 5*kk;
					//System.out.println(sestevek);
					if(sestevek == 40)
						System.out.println(mm +" "+ww+" " +kk);
				}
			}
		}
	
	}

}