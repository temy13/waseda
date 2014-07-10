
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class ReservationSystem {
	

	//ArrayList<Reserve> reserves = new ArrayList<Reserve>();

	
	
    public static void main(String[] args) {
    	String address;
    	int date;
    	
    	//ReservationSystem rs = new ReservationSystem();
    	/*rs.SearchHotel();//部屋情報検索
    	rs.ShowHotels();//ホテル一覧画面
    	//ShowRooms();//利用部屋一覧画面
    	rs.Reservation();//予約
    	rs.ShowResult();//予約結果表示*/
    	HotelControl hotelsControl = new HotelControl();
    	
    	//部屋情報検索
    	SearchHotelWindow sh = new SearchHotelWindow();
    	StringTokenizer Input = new StringTokenizer(sh.SearchHotels() ,":");//住所:日付の順でデータが飛んでくる
    	address = Input.nextToken();
    	date = Integer.parseInt(Input.nextToken());
    	//ホテル一覧画面
    	ShowHotelListWindow shl = new ShowHotelListWindow();
    	Hotel SelectedHotel = shl.ShowHotels(hotelsControl, address,date );
    	//予約
    	RoomReserveWindow rr = new RoomReserveWindow();
    	Reserve reserve = rr.Reservation(SelectedHotel, date);
    	//本当に予約できるかどうか
    	if(hotelsControl.CheckAvailability(reserve))
    		ShowResult(reserve,SelectedHotel);
    	else
    		System.out.println("エラーが発生しました");
    	
    	
    }
    
    
    public static void ShowResult(Reserve reserve,Hotel SelectedHotel){//予約結果表示
    	//Reserve nowReserve = reserves.get(reserves.size() - 1);
    	System.out.println(reserve.user.name+"さま\n"
    			+ reserve.date+"日後に"+SelectedHotel.name+"で"+reserve.people_number+"人でのご予約が確定しました");
    
    }
    
   
    
   
    
    /*public void ShowRooms(){
	//選んだホテルの
	ArrayList<Room> search_result_room = roomsControl.SearchResult(SelectedHotel,date);
	int selectedRoomNumber = 0;
	
	for(Room element : search_result_room){
		System.out.println(element.room_number);
	}
	System.out.println("部屋番号を選択してください");
	InputStreamReader isr = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(isr);
	try {
		String date_buf = br.readLine();
		selectedRoomNumber = Integer.parseInt(date_buf);
		
		for(Room element : search_result_room){
    		if(selectedRoomNumber == element.room_number){
    			SelectedRoom = element;break;
    		}	    			
    	}

	} catch (IOException e) {
		e.printStackTrace();
	}
	
}*/
    
}



