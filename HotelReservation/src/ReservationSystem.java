
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class ReservationSystem {
	

	//ArrayList<Reserve> reserves = new ArrayList<Reserve>();

	
	
    public static void main(String[] args) {
    	String address;
    	int date;
    	
    	//ReservationSystem rs = new ReservationSystem();
    	/*rs.SearchHotel();//������񌟍�
    	rs.ShowHotels();//�z�e���ꗗ���
    	//ShowRooms();//���p�����ꗗ���
    	rs.Reservation();//�\��
    	rs.ShowResult();//�\�񌋉ʕ\��*/
    	HotelControl hotelsControl = new HotelControl();
    	
    	//������񌟍�
    	SearchHotelWindow sh = new SearchHotelWindow();
    	StringTokenizer Input = new StringTokenizer(sh.SearchHotels() ,":");//�Z��:���t�̏��Ńf�[�^�����ł���
    	address = Input.nextToken();
    	date = Integer.parseInt(Input.nextToken());
    	//�z�e���ꗗ���
    	ShowHotelListWindow shl = new ShowHotelListWindow();
    	Hotel SelectedHotel = shl.ShowHotels(hotelsControl, address,date );
    	//�\��
    	RoomReserveWindow rr = new RoomReserveWindow();
    	Reserve reserve = rr.Reservation(SelectedHotel, date);
    	//�{���ɗ\��ł��邩�ǂ���
    	if(hotelsControl.CheckAvailability(reserve))
    		ShowResult(reserve,SelectedHotel);
    	else
    		System.out.println("�G���[���������܂���");
    	
    	
    }
    
    
    public static void ShowResult(Reserve reserve,Hotel SelectedHotel){//�\�񌋉ʕ\��
    	//Reserve nowReserve = reserves.get(reserves.size() - 1);
    	System.out.println(reserve.user.name+"����\n"
    			+ reserve.date+"�����"+SelectedHotel.name+"��"+reserve.people_number+"�l�ł̂��\�񂪊m�肵�܂���");
    
    }
    
   
    
   
    
    /*public void ShowRooms(){
	//�I�񂾃z�e����
	ArrayList<Room> search_result_room = roomsControl.SearchResult(SelectedHotel,date);
	int selectedRoomNumber = 0;
	
	for(Room element : search_result_room){
		System.out.println(element.room_number);
	}
	System.out.println("�����ԍ���I�����Ă�������");
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



