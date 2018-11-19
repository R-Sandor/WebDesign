/**
 * This class will hold information about the die.
 * @author Raphael
 *
 */
public class Die 
{
	// To hold the sided die.
	private int sides;
	// Holds number of dice.
	private int dice; 
	public Die (int sds, int dce) 
	{
		sides = sds;
		dice = dce;
	}
	
	public Die()
	{
		sides = 6;
		dice = 2;
	}
	public void setSides(int sds)
	{
		sides = sds;
	}
	
	public int getSides()
	{
		return sides;
	}
	
	public void setDice(int dce)
	{
		dice = dce;
	}
	
	public int getDice()
	{
		return dice;
	}
	
}
