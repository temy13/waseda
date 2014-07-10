import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class SearchHotelWindow {
	
	//—˜—p—\’è“ú“ü—Í
	public String SearchHotels(){
		
		String address="";
		int date = 0;

    	//êŠw’è
    	System.out.println("Œ§‚ğ“ü‚ê‚Ä‚­‚¾‚³‚¢");
    	InputStreamReader isr = new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader(isr);
    	try {
			address = br.readLine();
			//“ú•tw’è
	    	System.out.println("‰½“úŒã‚É—\–ñ‚·‚é‚©‚ğŒˆ‚ß‚Ä‚­‚¾‚³‚¢");
	    	while(true){
	    	InputStreamReader isr2 = new InputStreamReader(System.in);
	    	BufferedReader br2 = new BufferedReader(isr2);
	    	try {
				String date_buf = br2.readLine();
				date = Integer.parseInt(date_buf);
				if(date > 0 && date < 32)
					break;
				else
					System.out.println("1~31‚Ì”š‚Å‚¨Šè‚¢‚µ‚Ü‚·");
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
