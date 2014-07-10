import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class ShowHotelListWindow {
	 //��Ȃ̂���z�e���̕\��
    public Hotel ShowHotels(HotelControl hotelsControl,String address, int date){
    	//��قǓ��͂��ꂽ�����ɂ����z�e���̃��X�g�������Ă���
    	ArrayList<Hotel> search_result_hotel = hotelsControl.SearchResult(address, date);
    	Hotel SelectedHotel = null;
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
    	return SelectedHotel;
    }
}
