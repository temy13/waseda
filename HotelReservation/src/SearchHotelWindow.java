import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class SearchHotelWindow {
	
	//���p�\�������
	public String SearchHotels(){
		
		String address="";
		int date = 0;

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
    	    	
    	return address+":"+String.valueOf(date);
    }

}
