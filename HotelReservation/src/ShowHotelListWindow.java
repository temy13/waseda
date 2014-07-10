import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class ShowHotelListWindow {
	 //空席のあるホテルの表示
    public Hotel ShowHotels(HotelControl hotelsControl,String address, int date){
    	//先ほど入力された条件にあうホテルのリストを持ってくる
    	ArrayList<Hotel> search_result_hotel = hotelsControl.SearchResult(address, date);
    	Hotel SelectedHotel = null;
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
    	return SelectedHotel;
    }
}
