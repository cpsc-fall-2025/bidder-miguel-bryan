#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// INSTRUCTIONS
// ============================================================================
// 1. Implement the three functions below.
// 2. You may use the main() function at the bottom to test your code locally.
// 3. Do not change the function signatures.
// ============================================================================

// TODO: Implement this function to return a vector of strings
// containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {
  return {"Miguel-Angel Gonzalez", "Bryan De La Cruz"};
}

// TODO: Implement this function to return a string that describes
// the strategy your logic uses to bid (e.g., "We bid high early on").
std::string GetStrategy() {
  return "We bid evenly each round using an equal-distribution strategy.";
}

// TODO: Implement the bidding logic.
// parameters:
//   rounds: The total number of rounds in the game.
//   budget: The total points available to spend across all rounds.
//   output_filename: The name of the file where the bids should be written.
//
// Logic:
//   1. Calculate how much to bid in each round.
//   2. Open 'output_filename' for writing.
//   3. Write the bid for each round on a new line in the file.
//
// Constraints:
//   - You must write exactly 'rounds' number of lines.
//   - The sum of all bids must not exceed 'budget'.
//   - Bids must be non-negative integers.
void GenerateBids(int rounds, int budget, std::string output_filename) {
  std::ofstream outfile(output_filename);
  if (rounds <= 0) {
    return;
  }

  int bid_per_round = budget / rounds;
  int leftover = budget % rounds;

  for (int i = 0; i < rounds; i++) {
    int bid = bid_per_round;
    if (leftover > 0) {
      bid += 1;
      leftover--;
    }
    std::ofstream out{output_filename};
    outfile << bid << "\n";
  }
  outfile.close();
}

// ============================================================================
// MAIN FUNCTION
// Use this to test your code.
// This function will be ignored by the "make test" command.
// ============================================================================
int main() {
  int rounds{10};
  int budget{50};
  GenerateBids(rounds, budget, "test_output.txt");  
  std::ifstream input("test_output.txt");
  return 0;
}