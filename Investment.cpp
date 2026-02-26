#include "Investment.h" 
#include <iostream> 
#include <iomanip> 
#include <stdexcept>

// Constructor assigns user-provided values to private members.
Investment::Investment(double t_initialInvestmentAmount, 
	double t_monthlyDepositAmount,
	double t_annualInterestRate, 
	int t_numberOfYears)
: m_initialInvestmentAmount(t_initialInvestmentAmount),
m_monthlyDepositAmount(t_monthlyDepositAmount), 
m_annualInterestRate(t_annualInterestRate),
m_numberOfYears(t_numberOfYears) {}

// Calculates growth without additional monthly deposits.
void Investment::calculateWithoutMonthlyDeposits() {
	m_noDepositData.clear(); // Clear any previous results.

	double openingBalance = m_initialInvestmentAmount;

	// Loop over each year.
	for (int year = 1; year <= m_numberOfYears; ++year) {
		double earnedInterest = 0.0;

		// Loop over each month in the year.
		for (int month = 1; month <= 12; ++month) {
			// Monthly interest formula from requirements: 
			// (Opening Amount) * ((Interest Rate/100)/12)
			double monthlyInterest =
				openingBalance * (m_annualInterestRate / 100.0 / 12.0);

			earnedInterest += monthlyInterest;
			openingBalance += monthlyInterest;
		}

		// Store the year-end balance and interest.
		YearData yearData; 
		yearData.year = year;
		yearData.yearEndBalance = openingBalance; 
		yearData.yearEndInterest = earnedInterest;

		m_noDepositData.push_back(yearData);
	}
}

void Investment::calculateWithMonthlyDeposits() {
	m_withDepositData.clear();

	double openingBalance = m_initialInvestmentAmount;

	// Loop over each year.
	for (int year = 1; year <= m_numberOfYears; ++year) {
		double earnedInterest = 0.0;

		// Loop over each month in the year.
		for (int month = 1; month <= 12; ++month) {
			// Add monthly deposit before calculating interest.
			openingBalance += m_monthlyDepositAmount;

			// Monthly interest formula from requirements:
			// (Opening Amount + Deposited Amount) * ((Interest Rate/100)/12)
			double monthlyInterest = 
				openingBalance * (m_annualInterestRate / 100.0 / 12.0);

			earnedInterest += monthlyInterest;
			openingBalance += monthlyInterest;
		}

		// Store the year end balance and interest.
		YearData yearData; 
		yearData.year = year;
		yearData.yearEndBalance = openingBalance; 
		yearData.yearEndInterest = earnedInterest;

		m_withDepositData.push_back(yearData);
	}
}

// Display the report for the scenario without monthly deposits.
void Investment::displayWithoutMonthlyDeposits() const {
	std::cout << "\n Balance and Interest Without Additional Monthly Deposits\n";
	std::cout << " --------------------------------------------------------\n";
	std::cout << " Year\tYear End Balance\tYear End Earned Interest\n";

	// Use fixed and setprecision for currency formatting.
	for (const YearData& data : m_noDepositData) {
		std::cout << " " << data.year
			<< "\t$" << std::fixed << std::setprecision(2)
			<< data.yearEndBalance
			<< "\t\t$" << data.yearEndInterest
			<< "\n";
	}
}

// Display the rport for the scenario with monthly deposits.
void Investment::displayWithMonthlyDeposits() const {
	std::cout << "\n Balance and Interest With Additional Monthly Deposits\n";
	std::cout << " =========================================================\n";
	std::cout << " Year\tYear End Balance\tYear End Earned Interest\n";

	for (const YearData& data : m_withDepositData) {
		std::cout << " " << data.year
			<< "\t$" << std::fixed << std::setprecision(2)
			<< data.yearEndBalance
			<< "\t\t$" << data.yearEndInterest
			<< "\n";
	}
}
