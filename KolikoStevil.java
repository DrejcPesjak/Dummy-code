public class KolikoStevil {
	//counts how many numbers between 1 and 16000 are dividable by 4,6 or 9 and not by 12
	public static void main(String[] args) {
		int stevec = 0;

		for(int i = 0; i<16000; i++) {
			if((i%4==0 || i%6==0 || i%9==0) && i%12!=0)
				stevec++;
		}

		System.out.println(stevec);
	}
}