import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class RoomReserveWindow {

	 public Reserve Reservation(Hotel SelectedHotel, int date){
	    	//利用者の情報入力
	    	System.out.println("名前を入力してください");
	    	Reserve reserve = null;
	    	InputStreamReader isr = new InputStreamReader(System.in);
	    	BufferedReader br = new BufferedReader(isr);
	    	try {
				String name = br.readLine();
				User user = new User(name);
				
				System.out.println("人数");
		    	InputStreamReader isr2 = new InputStreamReader(System.in);
		    	BufferedReader br2 = new BufferedReader(isr2);
		    	try {
		    		int people_number = Integer.parseInt(br2.readLine());
		    		//Reserve reserve = new Reserve(SelectedRoom.room_number,user,people_number,date);
		    		reserve = new Reserve(SelectedHotel.id,user,people_number,date);
		    		//hotelsControl.RoomEmptyDecrease(SelectedHotel, date);
		    	} catch (IOException e) {
					e.printStackTrace();
				}

			} catch (IOException e) {
				e.printStackTrace();
			}
	    	return reserve;
	    }
}
