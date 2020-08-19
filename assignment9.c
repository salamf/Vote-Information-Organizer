////Salam Fazil
//V00935894

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS      10000  // maximum number of rows that the input file can have
#define NUMRIDINGS   338    // number of ridings

#define NUMCOLS      3      // number of columns in data
#define ID           0      // index of voter ID in data
#define RIDING       1      // index of riding number in data
#define VOTE         2      // index of vote in data

#define NUMPARTIES   4      // number of parties to vote for
#define NOPARTY     -1      // number to represents a party that doesn't exist
#define NDP          0      // number to represent NDP party
#define CONSERVATIVE 1      // number to represent Conservative party
#define LIBERAL      2      // number to represent Liberal party
#define GREEN        3      // number to represent Green party


int to_array( char filename[], int data[][NUMCOLS] );
void compute_riding_results(int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes);
int index_of_max(int array[], int length);
int calculate_winner(int counts_per_riding[][NUMPARTIES], int winners[]);
int calculate_popular_vote(int counts_per_riding[][NUMPARTIES]);
void to_party_name(char dest[], int party_num);
void to_file(char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]);


int main(void) {
    // test your methods here.
    // You have been provided with 4 sample input files and the corresponding output file


    ////To_array Test
//    int data[3][NUMCOLS];
//    char name[] = "input_text.txt";
//
//    to_array(name, data);
//
//    for (int i = 0; i < 50; ++i) {
//        for (int j = 0; j < NUMCOLS; ++j) {
//            printf("%d ", data[i][j]);
//        }
//        printf("\n");
//    }

    ////Compute_riding_results Test
//    int information[][NUMCOLS] = {{40601, 0, 3},
//                                  {15664, 1, 0},
//                                  {21298, 1, 2},
//                                  {78710, 2, 0},
//                                  {27598, 1, 3},
//                                  {45218, 1, 0}};
//    int res[NUMRIDINGS][NUMPARTIES];
//
//    compute_riding_results(information,res,6);
//
//    for (int i = 0; i < NUMRIDINGS; ++i) {
//        for (int j = 0; j < NUMPARTIES; ++j) {
//            printf("%d ", res[i][j]);
//        }
//        printf("\n");
//    }

    ////Index_of_max Test
//    int array1[] =  {3,4,1,6,1,6};
//    printf("%d", index_of_max(array1, 6));

    ////Calculate_winner Test
//    int counts_per_riding[NUMRIDINGS][NUMPARTIES] = {{10021, 16876, 18768, 12892},
//                                                     {27897, 18876, 23909, 20868},
//                                                     {13897, 10832, 12909, 22876},
//                                                     {14887, 11212, 11459, 14887}};
//    int storageArray[NUMRIDINGS] = {0};
//
//    int value = calculate_winner(counts_per_riding, storageArray);
//
//    for (int i = 0; i < NUMRIDINGS; ++i) {
//        printf("%d ", storageArray[i]);
//    }
//
//    printf("\n");
//
//    printf("%d\n", value);

    ////Calculate_popular_vote Test
//    int counts_per_riding[NUMRIDINGS][NUMPARTIES] = {{0, 0, 0, 1},
//                                                     {2, 0, 1, 1},
//                                                     {1, 0, 0, 0}};
//
//    int counts_per_riding2[NUMRIDINGS][NUMPARTIES] = {{0, 0, 0, 1},
//                                                      {2, 0, 1, 1},
//                                                      {1, 0, 0, 1}};
//
//    int val = calculate_popular_vote(counts_per_riding);
//
//    printf("\n%d\n", val);

    ////To_party_name Test
//    char destination[1000];
//    to_party_name(destination, -1);
//
//    printf("%s", destination);

    ////To_file Test
//    int data[MAXROWS][NUMCOLS];
//    int num_votes = to_array("input_text.txt", data);
//
//    int riding_vote_counts[NUMRIDINGS][NUMPARTIES];
//    compute_riding_results(data, riding_vote_counts, num_votes);
//
//    int winners[] = {0};
//    int election_winner_num = calculate_winner(riding_vote_counts, winners);
//
//    int winner2[NUMRIDINGS];
//
//    for (int i = 0; i < NUMRIDINGS; ++i) {
//        winner2[i] = winners[i];
//    }
//
//    char electionWinnerChar[1000];
//    to_party_name(electionWinnerChar, election_winner_num);
//
//    int popular_vote_winner_num = calculate_popular_vote(riding_vote_counts);
//
//    char popVoteWinnerChar[1000];
//    to_party_name(popVoteWinnerChar, popular_vote_winner_num);
//
//    to_file("output_text.txt", riding_vote_counts, winner2, electionWinnerChar, popVoteWinnerChar);

    return 0;
}

/* Purpose: To read and store the data from the input file into the corresponding
            rows/columns of the destination array.
 * Arguments: char filename - name of input file, int data - destination matrix
 * returns: -1 if file can't be read. Otherwise returns num of votes */
int to_array( char filename[], int data[][NUMCOLS] ){

    FILE* input_file = fopen(filename, "r");

    int r = 0;

    while((fscanf(input_file,"%d %d %d", &data[r][ID], &data[r][RIDING], &data[r][VOTE]) == NUMCOLS) && (r <= MAXROWS)){
        r++;
    }

    fclose(input_file);

    return r;
}

/* Purpose: Compute riding results and store them into an array
 * Arguments: int data - input matrix with the data, int result - destination matrix,
              int num_votes - the number of votes
 * returns: Nothing (void) */
void compute_riding_results(int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes){

    for(int r = 0; r < NUMRIDINGS; ++r){
        for(int c = 0; c < NUMPARTIES; ++c){
            result[r][c] = 0;
        }
    }

    for (int i = 0; i < num_votes; ++i) {
        int row = data[i][RIDING];
        int col = data[i][VOTE];

        result[row][col]++;
    }
}

/* Purpose: Find the index of the maximum number in an array
 * Arguments: int array - input array, int length - length of array
 * returns: The index of the max num in the matrix */
int index_of_max(int array[], int length){

    int max = array[0];
    int max_index = 0;

    for (int i = 0; i < length; ++i) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }

    for (int j = max_index + 1; j <= length; ++j) {
        if(array[j] == max){
            return -1;
        }
    }

    return max_index;
}

/**///helper function
int find_max(int n1, int n2, int n3, int n4){
    int max = 0;
    int ret_val = 0;

    if (n1 > n2 && n1 > n3 && n1 > n4){
        max = n1;
        ret_val = NDP;
    }else if(n2 > n1 && n2 > n3 && n2 > n4){
        max = n2;
        ret_val = CONSERVATIVE;
    }else if(n3 > n1 && n3 > n2 && n3 > n4){
        max = n3;
        ret_val = LIBERAL;
    }else if(n4 > n1 && n4 > n2 && n4 > n3){
        max = n4;
        ret_val = GREEN;
    }else{
        max = 0;
        ret_val = NOPARTY;
    }

    return ret_val;
}
/**/

/* Purpose: Store the winner of each riding into an output array
 * Arguments: int counts_per_riding - data matrix, int winners - output array
 * returns: The number of the overall winner, if there's a tie then -1 */
int calculate_winner(int counts_per_riding[][NUMPARTIES], int winners[]){

    int ndpWinCount = 0;
    int conWinCount = 0;
    int libWinCount = 0;
    int greenWinCount = 0;

    int tempArr[NUMPARTIES] = {0};

    for (int i = 0; i < NUMRIDINGS; ++i) {
        for (int c = 0; c < NUMPARTIES; ++c) {
            tempArr[c] = counts_per_riding[i][c];
        }
        winners[i] = index_of_max(tempArr, NUMPARTIES);

        if (winners[i] == NDP){
            ndpWinCount++;
        }else if(winners[i] == CONSERVATIVE){
            conWinCount++;
        }else if(winners[i] == LIBERAL){
            libWinCount++;
        }else if(winners[i] == GREEN){
            greenWinCount++;
        }
    }

    int mostRidingWon = find_max(ndpWinCount, conWinCount, libWinCount, greenWinCount);

    return mostRidingWon;
}

/* Purpose: Find which party had the most votes
 * Arguments: int counts_per_riding - data matrix
 * returns: The number of the party with the most votes */
int calculate_popular_vote(int counts_per_riding[][NUMPARTIES]){

    int ndpSum = 0;
    int conSum = 0;
    int libSum = 0;
    int greenSum = 0;

        for (int r = 0; r < NUMRIDINGS; ++r) {
            ndpSum += counts_per_riding[r][NDP];
            conSum += counts_per_riding[r][CONSERVATIVE];
            libSum += counts_per_riding[r][LIBERAL];
            greenSum += counts_per_riding[r][GREEN];
        }

    int winner = find_max(ndpSum, conSum, libSum, greenSum);

    return winner;
}

/* Purpose: Converts a party number to its name
 * Arguments: char dest - storage place of party name, int party_num - number of party
 * returns: Nothing (void) */
void to_party_name(char dest[], int party_num){

    if(party_num == 0){
        strcpy(dest, "NDP");
    }else if(party_num == 1){
        strcpy(dest, "CONSERVATIVE");
    }else if(party_num == 2){
        strcpy(dest, "LIBERAL");
    }else if(party_num == 3){
        strcpy(dest, "GREEN");
    }else{
        strcpy(dest, "NOT NAMED");
    }
}

/* Purpose: Opens a file and prints all given information into the file
 * Arguments: char filename - name of output file, int riding vote counts - vote counts for each riding
 *            int riding_winners - array of winners per riding, char election winner - name of election winner
 *            char popular_winner - name of popular votes winner
 * returns: Nothing (void) */
void to_file(char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]){

    FILE* output_file = fopen(filename, "w");

    fprintf(output_file, "Winner of the election: %s\n\nWinner of the popular vote: %s\n\n", election_winner, popular_winner);

    fprintf(output_file, "\t\tRIDING#\t\t\t\tNDP\t   CONSERVATIVE \t\tLIBERAL\t\t\t  GREEN    WINNING PARTY\n");

    for (int i = 0; i < NUMRIDINGS; ++i) {
        char rowWinner[1000];
        to_party_name(rowWinner, riding_winners[i]);

        fprintf(output_file, "%15d %15d %15d %15d %15d %15s", i, riding_vote_counts[i][NDP], riding_vote_counts[i][CONSERVATIVE],
                riding_vote_counts[i][LIBERAL], riding_vote_counts[i][GREEN], rowWinner);

        fprintf(output_file,"\n");
    }
    fclose(output_file);
}