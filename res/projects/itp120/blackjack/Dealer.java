import java.util.Random;
/**
 * This class will act as the dealer in a game of 21.
 * @author Raphael
 *
 */
public class Dealer 
{
	private int die1Value;
	private int die2Value;
	Random rand = new Random();
	Die die = new Die();
	Die die2 = new Die();
	public int rollDice()
	{
		die1Value = rand.nextInt(die.getSides() +1);
		die2Value = rand.nextInt(die2.getSides()+1);
		return die1Value + die2Value;
		
	}
	
	public void setPlayer1Total()
	{
		rollDice();
	}
	
	
}
