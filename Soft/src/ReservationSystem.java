
import java.io.*;
import java.util.ArrayList;


public class ReservationSystem {
	
	HotelControl hotelsControl = new HotelControl();
	//RoomControl roomsControl = new RoomControl();
	ArrayList<Reserve> reserves = new ArrayList<Reserve>();
	String address;
	int date;
	Hotel SelectedHotel;
	//Room SelectedRoom;
	
	
    public static void main(String[] args) {
    	
    	ReservationSystem rs = new ReservationSystem();
    	rs.SearchHotel();//部屋情報検索
    	rs.ShowHotels();//ホテル一覧画面
    	//ShowRooms();//利用部屋一覧画面
    	rs.Reservation();//予約
    	rs.ShowResult();//予約結果表示
    }
    
    
  //利用予定日入力
    public void SearchHotel(){

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
    	    	
    }
    //空席のあるホテルの表示
    public void ShowHotels(){
    	//先ほど入力された条件にあうホテルのリストを持ってくる
    	ArrayList<Hotel> search_result_hotel = hotelsControl.SearchResult(address, date);
    	int selectedNumber=0;
    	int i = 1;
    	if(search_result_hotel.isEmpty())
    	{
    		System.out.println("該当するものはありませんでした");
    		System.exit(0);
    	}
    	else{
    	//検索条件に合致したホテルを表示していく
    	for(Hotel element : search_result_hotel){
    		System.out.println(i + ":" +element.name);
    		i++;
    	}
    	System.out.println("リストの番号を選択してください");
    	InputStreamReader isr = new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader(isr);
    	try {
			String date_buf = br.readLine();
			//入力された番号の値からホテルの情報を確保する
			selectedNumber = Integer.parseInt(date_buf);
			SelectedHotel = search_result_hotel.get(selectedNumber-1);//検索結果にあったホテルのリストから目的のホテルのデータを保存
		} catch (IOException e) {
			e.printStackTrace();
		}
    	}
    	
    }
    
    public void Reservation(){
    	//利用者の情報入力
    	System.out.println("名前");
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
	    		reserves.add(new Reserve(SelectedHotel.id,user,people_number,date));
	    		hotelsControl.RoomEmptyDecrease(SelectedHotel, date);
	    	} catch (IOException e) {
				e.printStackTrace();
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
    	
    }
    public void ShowResult(){//予約結果表示
    	Reserve nowReserve = reserves.get(reserves.size() - 1);
    	System.out.println(nowReserve.user.name+"さま\n"
    			+ nowReserve.date+"日後に"+SelectedHotel.name+"で"+nowReserve.people_number+"人でのご予約が確定しました");
    
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



