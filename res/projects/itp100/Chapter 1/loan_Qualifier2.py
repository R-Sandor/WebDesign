min_salary = 30000
min_years = 2
years_on_job = int (input ('Enter number of years on job: '))
salary = int (input ('Enter your salary: '))
if salary >= min_salary and years_on_job >= min_years:
        print ('You qualify for the loan.')
elif years_on_job < min_years:
        print ('you must have been employed', \
               'for at least', min_years, \
               'years to qualify.')
else:
        print ('you must earn at least $', \
               format(min_salary, ',.2f'), \
               ' per year to qualify.' )
