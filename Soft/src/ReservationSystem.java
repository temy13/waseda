
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
    	rs.SearchHotel();//������񌟍�
    	rs.ShowHotels();//�z�e���ꗗ���
    	//ShowRooms();//���p�����ꗗ���
    	rs.Reservation();//�\��
    	rs.ShowResult();//�\�񌋉ʕ\��
    }
    
    
  //���p�\�������
    public void SearchHotel(){

    	//�ꏊ�w��
    	System.out.println("�������Ă�������");
    	InputStreamReader isr = new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader(isr);
    	try {
			address = br.readLine();
			//���t�w��
	    	System.out.println("������ɗ\�񂷂邩�����߂Ă�������");
	    	while(true){
	    	InputStreamReader isr2 = new InputStreamReader(System.in);
	    	BufferedReader br2 = new BufferedReader(isr2);
	    	try {
				String date_buf = br2.readLine();
				date = Integer.parseInt(date_buf);
				if(date > 0 && date < 32)
					break;
				else
					System.out.println("1~31�̐����ł��肢���܂�");
			} catch (IOException e) {
				e.printStackTrace();
			}
	    	}
		} catch (IOException e) {
			e.printStackTrace();
		}
    	    	
    }
    //��Ȃ̂���z�e���̕\��
    public void ShowHotels(){
    	//��قǓ��͂��ꂽ�����ɂ����z�e���̃��X�g�������Ă���
    	ArrayList<Hotel> search_result_hotel = hotelsControl.SearchResult(address, date);
    	int selectedNumber=0;
    	int i = 1;
    	if(search_result_hotel.isEmpty())
    	{
    		System.out.println("�Y��������̂͂���܂���ł���");
    		System.exit(0);
    	}
    	else{
    	//���������ɍ��v�����z�e����\�����Ă���
    	for(Hotel element : search_result_hotel){
    		System.out.println(i + ":" +element.name);
    		i++;
    	}
    	System.out.println("���X�g�̔ԍ���I�����Ă�������");
    	InputStreamReader isr = new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader(isr);
    	try {
			String date_buf = br.readLine();
			//���͂��ꂽ�ԍ��̒l����z�e���̏����m�ۂ���
			selectedNumber = Integer.parseInt(date_buf);
			SelectedHotel = search_result_hotel.get(selectedNumber-1);//�������ʂɂ������z�e���̃��X�g����ړI�̃z�e���̃f�[�^��ۑ�
		} catch (IOException e) {
			e.printStackTrace();
		}
    	}
    	
    }
    
    public void Reservation(){
    	//���p�҂̏�����
    	System.out.println("���O");
    	InputStreamReader isr = new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader(isr);
    	try {
			String name = br.readLine();
			User user = new User(name);
			
			System.out.println("�l��");
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
    public void ShowResult(){//�\�񌋉ʕ\��
    	Reserve nowReserve = reserves.get(reserves.size() - 1);
    	System.out.println(nowReserve.user.name+"����\n"
    			+ nowReserve.date+"�����"+SelectedHotel.name+"��"+nowReserve.people_number+"�l�ł̂��\�񂪊m�肵�܂���");
    
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



