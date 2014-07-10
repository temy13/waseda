import java.util.ArrayList;


public class HotelControl {
	ArrayList<Hotel> hotels = new ArrayList<Hotel>();
	ArrayList<Reserve> reserveList = new ArrayList<Reserve>();	
	
	//�������ꂽ�Ƃ��A���̏����ɓ��Ă͂܃z�e���̃��X�g��Ԃ�
	public ArrayList<Hotel> SearchResult(String address, int date){
	
		//for debug
		hotels.add(new Hotel(0,"�z�e������","����",0,30));
		
		
		
		
		ArrayList<Hotel> SearchedHotels = new ArrayList<Hotel>();
		
		for(Hotel element : hotels) {
			//�܂��Z����������炻�̎��_�ňႤ
			if(!element.address.equals(address))
				continue;
			//�����Ă���z�e���ɋ󂫂����邩�`�F�b�N
			//if(RoomControl.HaveEmpty(element.id, date));//��������
			if(element.ReserveEmpty[date] > 0);//��������
					SearchedHotels.add(element);//�ǉ�
		
		}
		return SearchedHotels;
	}
	//�ǉ����钼�O�ł�����Ɨ\��ł��邩�`�F�b�N����
	public boolean CheckAvailability(Reserve reserve){
		//�z�e���̏�����
		Hotel reservedHotel = null;
		for(Hotel element : hotels) {
			if(reserve.hotel_id == element.id)
				reservedHotel = element;
		}
		if(reservedHotel == null) return false;
		//�����Ɨ\��ł����Ԃ�������
		if(reservedHotel.ReserveEmpty[reserve.date] > 0){
			reserveList.add(reserve);//���X�g�ɒǉ�
			RoomEmptyDecrease(reservedHotel,reserve.date);
			return true;
		}else
			return false;
		
	}
	
	
	//�\��m�肵���̂��A�\�񂳂ꂽ�z�e���́A�w�肳�ꂽ���t�̋󂫕������͈����
	public void RoomEmptyDecrease(Hotel hotel,int date){
		for(Hotel element : hotels){
			if(element.id == hotel.id){
				element.ReserveEmpty[date] -= 1; 
			}
		}
	}
	
	
	
}
