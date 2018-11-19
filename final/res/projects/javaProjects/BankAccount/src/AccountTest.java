import javax.swing.JOptionPane; // For the JOptionPane class
import java.text.DecimalFormat;

public class AccountTest 
{
	public static void main (String [] args)
	{
		String input; // to hold user input
		
		// Create a DecimalFromat object for displaying dollars.
		DecimalFormat dollar = new DecimalFormat("#,###.00");
		
		// Get the starting balance 
		input = JOptionPane.showInputDialog("What is your " +
							"account's starting balance?");
		
		BankAccount account = new BankAccount(input);
		
		// Get the amount of pay
		input = JOptionPane.showInputDialog("How much were " +
											"you paid this month");
		
		// Deposits user's pay into the account
		account.deposit(input);
		
		// Display the new balance.
		JOptionPane.showMessageDialog(null, 
				"Your pay has been deposited.\n" +
				"Your current balance is $ " + 
				 dollar.format(account.getBalance()));
		
		System.exit(0);
	}
}
