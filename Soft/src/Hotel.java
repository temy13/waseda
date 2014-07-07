
public class Hotel{
	int id;
	String name;
	String address;
	int telephone;
	int rooms;
	//そのホテルの各日程の空き部屋数
	int[] ReserveEmpty = new int[31];//31日後までしか予約は受け付けない。配列のそれぞれに、その日使える部屋数が記録される。
	
	public Hotel(int id,String name, String address,int telephone,int rooms){
		this.id =id;
		this.name=name;
		this.address = address;
		this.telephone = telephone;
		this.rooms=rooms;
		for(int i = 0; i<ReserveEmpty.length; i++)
			this.ReserveEmpty[i] = rooms;
	}
	
}