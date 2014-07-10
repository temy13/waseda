import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class SearchHotelWindow {
	
	//利用予定日入力
	public String SearchHotels(){
		
		String address="";
		int date = 0;

    	//場所指定
    	System.out.println("県を入れてください");
    	InputStreamReader isr = new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader(isr);
    	try {
			address = br.readLine();
			//日付指定
	    	System.out.println("何日後に予約するかを決めてください");
	    	while(true){
	    	InputStreamReader isr2 = new InputStreamReader(System.in);
	    	BufferedReader br2 = new BufferedReader(isr2);
	    	try {
				String date_buf = br2.readLine();
				date = Integer.parseInt(date_buf);
				if(date > 0 && date < 32)
					break;
				else
					System.out.println("1~31の数字でお願いします");
			} catch (IOException e) {
				e.printStackTrace();
			}
	    	}

		} catch (IOException e) {
			e.printStackTrace();
		}
    	    	
    	return address+":"+String.valueOf(date);
    }

}
