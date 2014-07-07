import java.util.ArrayList;


public class HotelControl {
	ArrayList<Hotel> hotels = new ArrayList<Hotel>();
	
	
	//検索されたとき、その条件に当てはまホテルのリストを返す
	public ArrayList<Hotel> SearchResult(String address, int date){
		
		//for debug
		hotels.add(new Hotel(0,"ホテルくん","東京",0,30));
		
		
		
		
		ArrayList<Hotel> SearchedHotels = new ArrayList<Hotel>();
		
		for(Hotel element : hotels) {
			//まず住所が違ったらその時点で違う
			if(!element.address.equals(address))
				continue;
			//今見ているホテルに空きがあるかチェック
			//if(RoomControl.HaveEmpty(element.id, date));//あったら
			if(element.ReserveEmpty[date] > 0);//あったら
					SearchedHotels.add(element);//追加
		
		}
		return SearchedHotels;
	}
	
	//予約確定したのち、予約されたホテルの、指定された日付の空き部屋数は一つ減る
	public void RoomEmptyDecrease(Hotel hotel,int date){
		for(Hotel element : hotels){
			if(element.id == hotel.id){
				element.ReserveEmpty[date] -= 1; 
			}
		}
	}
	
}
