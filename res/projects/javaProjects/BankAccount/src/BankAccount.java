/**
 * The BankAccount class simulates a bank account
 * @author Raphael
 *
 */

public class BankAccount 
{
	private double balance; // Account Balance
	
	/**
	 *  This constructor sets the starting balance
	 *  at 0.0.
	 */
	
	public BankAccount()
	{
		balance = 0.0;
	}
	
	public BankAccount(double startBalance)
	{
		balance = startBalance;
	}
	
	/** 
	 *  This constructor sets the starting balance 
	 *  to the value in the String argument.
	 *  @param str the starting balance, as a String.
	 */
	
	public BankAccount(String str)
	{
		balance = Double.parseDouble(str);
	}
	
	/**
	 *  The deposit method makes a deposit into the account.
	 *  @param amount The amount to add to the 
	 *  			  balance field.
	 */
	
	public void deposit (double amount)
	{
		balance += amount;
		
	}
	
	/**
	 *  The deposit method makes a deposit into 
	 *  the account.
	 *  @param str The amount to add to the s
	 *  			balance field, as a String.
	 */
	
	public void deposit (String str)
	{
		balance += Double.parseDouble(str);
		
	}
	
	/**
	 *  The withdraw method withdraws an amount from the account.
	 *  @param amount The amount to subtract from the 
	 *  			  balance field
	 */
	
	public void withdraw (double amount)
	{
		balance -= amount;
		
		
	}
	
	/**
	 * The withdraw method withdraws an amount from the account 
	 * @param str The amount to subtract from 
	 * 			  the balance field, as a string
	 */
	
	public void withdraw(String str)
	{
		balance -= Double.parseDouble(str);
	}
	
	/**
	 *  The setBalance method sets the account balance.
	 *  @param b The value to store in the balance field.
	 */
	
	public void setBalance(double b )
	{
		balance = b;
	}
	
	/**
	 *  The setBalance method sets the account balance.
	 *  @param str The value, as a String, to store in the balance field.
	 */
	
	public void setBalance(String str)
	{
		balance = Double.parseDouble(str);
	
	}
	
	/**
	 *  The getBalance method returns the 
	 *  account balance.
	 *  @param return The value in the balance field.
	 */
	
	public double getBalance()
	{
		return balance;
	}
}
