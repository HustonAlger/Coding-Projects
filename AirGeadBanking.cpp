#include <iostream> 
#include <stdexcept> 
#include "Investment.h"

int main() {
	// Loop allows user to test multiple scenarios.
	while (true) {
		try {
			double initialInvestmentAmount; 
			double monthlyDepositAmount;
			double annualInterestRate; 
			int numberOfYears;

			// Display the input screen as shown in the Airgead requirements.
			std::cout << "********** Data Input **********\n";

			std::cout << "Initial Investment Amount: "; 
			std::cin >> initialInvestmentAmount;

			std::cout << "Monthly Deposit: "; 
			std::cin >> monthlyDepositAmount;

			std::cout << "Annual Interest: "; 
			std::cin >> annualInterestRate;

			std::cout << "Number of years: "; 
			std::cin >> numberOfYears;

			// validation to ensure positive values.
			if (!std::cin ||
				initialInvestmentAmount < 0.0 || 
				monthlyDepositAmount < 0.0 || 
				annualInterestRate < 0.0 ||
				numberOfYears <= 0) {
				// Clear error state and discard bad input.
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::invalid_argument("All values must be valid and positive.");
			}

			std::cout << "Press any key to continue...\n";

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();

			// Create Investment object using validated input.
			Investment investment(initialInvestmentAmount,
				monthlyDepositAmount,
				annualInterestRate, 
				numberOfYears);

			// Perform calculations for both scenarios.
			investment.calculateWithoutMonthlyDeposits(); 
			investment.calculateWithMonthlyDeposits();

			// Display both reports.
			investment.displayWithoutMonthlyDeposits(); 
			investment.displayWithMonthlyDeposits();

			// Asks user if they want to run another scenario.
			std::cout << "\nRun another scenario? (y/n): "; 
			char again;
			std::cin >> again;
			if (again != 'y' && again != 'Y') {
				break; // Exit loop and end program. 
			}

			// Clear any leftover input before next loop iteration.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		catch (const std::exception& e) {
			// Handle errors gracefully and allow user to try again.
			std::cout << "Error: " << e.what() << "\nPlease try again.\n\n";
		}
	}

	std::cout << "Thank you for using Airgead Banking.\n";
	return 0;
}