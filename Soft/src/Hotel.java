
public class Hotel{
	int id;
	String name;
	String address;
	int telephone;
	int rooms;
	//���̃z�e���̊e�����̋󂫕�����
	int[] ReserveEmpty = new int[31];//31����܂ł����\��͎󂯕t���Ȃ��B�z��̂��ꂼ��ɁA���̓��g���镔�������L�^�����B
	
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