#include <iostream>
#include <vector>
#include <regex>

void find_genes(const std::string& genome);
void print_vector(const std::vector<std::string>& vector);

int main() {
    std::string genome;

    std::cout << "Input genome" << std::endl;
    std::cin >> genome;

    find_genes(genome);

    return 0;
}

void find_genes(const std::string& genome) {
    std::regex pattern ("(ATG)(.*)(TAA)|(ATG)(.*)(TAG)|(ATG)(.*)(TGA)");
    std::sregex_iterator next(genome.begin(), genome.end(), pattern);
    std::sregex_iterator end;
    std::smatch match;
    std::string result;
    std::vector<std::string> vector_of_genomes;

    while (next != end) {
        match = *next;
        result = match.str();
        result = result.erase(0, 3).erase(result.length() - 3, 3);

        if (result.find("ATG") == std::string::npos || result.find("TAG") == std::string::npos ||
        result.find("TAA") == std::string::npos || result.find("TGA") == std::string::npos) {
            vector_of_genomes.emplace_back(result);
        }
        next++;
    }

    if (!vector_of_genomes.empty()) {
        print_vector(vector_of_genomes);
    }
    else {
        std::cout << "No gene is found" << std::endl;
    }

}

void print_vector(const std::vector<std::string>& vector) {
    unsigned i;

    for (i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
}
