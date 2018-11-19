import javax.swing.JOptionPane;
/**
 * This program accesses the Car class
 * It will hold the speed of the car  
 * @author Raphael
 *
 */
public class Driver {

	public static void main(String[] args) 
	{
		int vYear =Integer.parseInt(JOptionPane.showInputDialog(null,"What is the year of vechile"));
		String mke = JOptionPane.showInputDialog(null, "What is the make of the vechile");
		Car car = new Car(vYear,mke);
		
		JOptionPane.showMessageDialog(null, "The year of the vechile is " + car.getYearModel());
		JOptionPane.showMessageDialog(null, "The make of the of car is " + car.getMake());
		JOptionPane.showMessageDialog(null, "The current speed is " + car.getSpeed());
		
		
		for (int count = 0; count < 5; count++)
		{
			JOptionPane.showMessageDialog(null, "Pressing the gas pedal");
			car.accelerate();
			JOptionPane.showMessageDialog(null, "The current speed is " + car.getSpeed());

		}
		
		for (int count = 0; count < 5; count++)
		{
			JOptionPane.showMessageDialog(null, "Pressing the brake");
			car.brake();
			JOptionPane.showMessageDialog(null, "The current speed is " + car.getSpeed());

		}

	}

	
}