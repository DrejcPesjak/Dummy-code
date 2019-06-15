public class Enacba2neznanki {
	public static void main(String[] args) {
		int w = 0;
		int m = 800;


		long sestevek = 0;
		
		for(int mm = m; mm<1334; mm++){
			for(int ww = w; ww<277; ww++){
				sestevek = 29*ww + 6*mm;
				//System.out.println(sestevek);
				if(sestevek == 8000)
					System.out.println(ww +" "+ mm);
			}
		}
	
	}

}