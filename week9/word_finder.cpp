#include <iostream>
#include <vector>

// given input of grid - has to find the words going up or down - print final grid using #

std::vector<std::string> row_check(const std::vector<std::string>& grid,
    const std::vector<std::string>& words,
    std::vector<std::string>& not_found);

std::vector<std::string> column_check(const std::vector<std::string>& grid,
    const std::vector<std::string>& words,
    std::vector<std::string>& not_found);

std::vector<std::string> transposition(const std::vector<std::string>& grid);



void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
)
{
not_found = words;


}
std::vector<std::string> row_check(const std::vector<std::string>& grid, const std::vector<std::string>& words,std::vector<std::string>& not_found)
{
    std::string current_row;
    std::string current_substr;
    int row_size = grid[0].size();
    std::string hashtag(row_size,'#' ) ;
    std::vector<std::string> vector_rows;
    for(int y = 0; y < grid.size() ; ++y)
    {
        vector_rows.push_back(hashtag);
    }


    for(int row_counter = 0; row_counter < grid.size(); ++row_counter)
    {
        current_row = grid[row_counter];
        for(int word_incrament = 0; word_incrament < words.size(); ++ word_incrament)
        {
            if(words[word_incrament].size() <= row_size){
            for(int last_char = 0; last_char <= row_size - words[word_incrament].size(); ++last_char)
            {
                current_substr = current_row.substr(last_char,words[word_incrament].size());
                if(current_substr == words[word_incrament])
                    {
                        vector_rows[row_counter].replace(last_char,words[word_incrament].size(),current_substr);
                        not_found[word_incrament] = "removed";
                    }
            }
        }
    }
}
    return vector_rows;
}
std::vector<std::string> column_check(const std::vector<std::string>& grid,
    const std::vector<std::string>& words,
    std::vector<std::string>& not_found)
    {
        std::vector<std::string> new_grid = grid;
        new_grid = transposition(new_grid);
        new_grid = row_check(new_grid,words,not_found);
        new_grid = transposition(new_grid);

        return new_grid;
    }

std::vector<std::string> transposition(const std::vector<std::string>& grid)
{
    std::vector<std::string> transposed_vector {};
    std::string column;
    int row_size = grid[0].size();
    for(int column_mover = 0; column_mover < row_size; ++column_mover)
    {
        column = "";
        for(int x = 0 ; x < grid.size(); ++x)
            {
                column += (grid[x])[column_mover];
            }
            transposed_vector.push_back(column);
    }
    return transposed_vector;


}
int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}