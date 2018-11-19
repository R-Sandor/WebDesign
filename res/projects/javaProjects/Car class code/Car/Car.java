/**
 * This program will hold car information. 
 * @author Raphael
 *
 */

public class Car
{
	// Hold the year of the model of car.
	private int yearModel;
	// The hold the make of the car
	private String make;
	// Hold the speed of the vehicle.
	private int speed;
	
	/**
	 * The is constructor sets the yearModel and make of the car
	 * also places the speed at 0.
	 * @param yrMd
	 * @param mke
	 */
	
	public Car(int yrMd, String mke)
	{
		yearModel = yrMd;
		make = mke;
		speed = 0;
	}
	
	
	/**
	 * This will set the cars year.
	 * @param yrMod sets yearModel 
	 */
	
	public void setYearModel(int yrMod)
	{
		yearModel = yrMod;
	}
	
	/**
	 * Holds make information  
	 * @param mke sets make
	 */
	
	public void setMake (String mke)
	{
		make = mke;
	}
	
	/**
	 * The accelerate method.
	 * Speeds car up by 5 mph.
	 */
	public void accelerate()
	{
		speed += 5;
	}
	
	/**
	 * The brake method 
	 * slows the car by 5 mph.
	 */
	
	public void brake()
	{
		speed -= 5;
	}
	
	
	/**
	 * @return returns yearModel
	 */
	
	public int getYearModel()
	{
		return yearModel;
	}
	
	/**
	 * @return make of car
	 */
	
	public String getMake()
	{
		return make;
	}
	
	/**
	 * displays speed
	 * @return Speed of car
	 */
	public int getSpeed()
	{
		return speed;
	}
}
