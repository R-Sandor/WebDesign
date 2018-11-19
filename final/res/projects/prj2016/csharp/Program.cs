using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RecursiveMethod
{
    class Program
    {
        static void Main(string[] args)
        {
            double defaultSignificantNumbers = 0;
            double numberToCount = 4680;
            Console.WriteLine(Counter(numberToCount, defaultSignificantNumbers));
        }

        public static double Counter(double usersNumber, double significantNumbers)
        {
            if (usersNumber >=1)
            {
                usersNumber = usersNumber / 10;
                return Counter(usersNumber, indexMachine(significantNumbers));
               
            }
            else
            {
                return significantNumbers;
            }
        }

        public static double indexMachine(double significantNumbers)
        {
       
            return ++significantNumbers;
        }
    }
}
