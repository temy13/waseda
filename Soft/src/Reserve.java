
public class Reserve {
	//int room_number;
	int hotel_id;
	User user;
	int people_number;
	int date;
	public Reserve(int hotel_id,User user,int people,int date){
		this.hotel_id = hotel_id;
		this.user = user;
		people_number = people;
		this.date = date;
	}
}
