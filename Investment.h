#ifndef AIRGEAD_INVESTMENT_H_ 
#define AIRGEAD_INVESTMENT_H_

#include <vector>

// The Investment class models after an investment account and 
// // provides methods to calculate and display the growth over time.
class Investment {
public:
	// initializes all investment parameters.
	Investment(double t_initialInvestmentAmount,
		double t_monthlyDepositAmount,
		double t_annualInterestRate,
		int t_numberOfYears);

	// Calculates yearly balances and interest without monthly deposits.
	void calculateWithoutMonthlyDeposits();

	// Calculates yearly balances and interest with monthly deposits.
	void calculateWithMonthlyDeposits();

	// Displays the report without monthly deposits.
	void displayWithoutMonthlyDeposits() const;

	// Displays the report with monthly deposits.
	void displayWithMonthlyDeposits() const;

private:
	// Private member variables follow m_ naming convention.
	double m_initialInvestmentAmount; 
	double m_monthlyDepositAmount; 
	double m_annualInterestRate; 
	int m_numberOfYears;

	// Struct, Structured to store yearly summary data.
	struct YearData {
		int year;
		double yearEndBalance;
		double yearEndInterest;
	};

	// Vectors store yearly results for each scenario.
	std::vector<YearData> m_noDepositData;
	std::vector<YearData> m_withDepositData;
};

#endif // AIRGEAD_INVESTMENT_H_






