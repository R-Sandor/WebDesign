import java.util.*;

/**
 * This program demonstrates a <code> for </code>
 * loop.
 * @author Raphael J.
 *
 */
public class LotterOdds
{
	public static void main(String[]args)
	{
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("How many numbers do you need to draw?");
		int drawings = keyboard.nextInt();
		System.out.print("What is the highest number you can draw?");
		int highestNumber = keyboard.nextInt();
		
		/*
		 * Compute binomial coefficient drawings*(drawings-1)*(drawings-2)*...
		 * *(drawings-highestNumber+1)/(1*2*3.....highestNumber)
		 */
		
		int lotteryOdds = 1;
		for (int i = 1; i <= drawings; i++)
			lotteryOdds = lotteryOdds*(highestNumber-i+1)/i;
		
		System.out.println("Your odds are 1 in " + lotteryOdds + ". Good Luck!");
	}
	
}
