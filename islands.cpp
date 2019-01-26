// count islands 
// Anthony Olvera
// 01/25/2019
//
// Algoithm: 
// 1. loop over all bits
// 2. if an unvisited one is encountered
//        increment islands
//        mark it as visited 
//        traverse all adjacent nodes and mark them as visited
// 3. continue until all bits have been looped over
// 4. return islands

#include "islands.h"


void print_elements(vector< vector<int> > region){
  for(int i = 0; i < region.size(); i++) {
    cout << "row " << i << ": ";
    for(int j = 0; j < region[i].size(); j++) {
      cout << region[i][j];
    }
    cout << endl;
  }
}


int count_islands(vector< vector<int> > region){
  int islands = 0;
  vector< vector<int> > visited_matrix; // create a duplicate region of all nodes unvisited
  for(int row = 0; row < region.size(); row++){ //loop over rows
    vector<int> temp_row;
    for(int column = 0; column < region[row].size(); column++) { // loop over columns
      temp_row.push_back(0);
    }
    visited_matrix.push_back(temp_row);
  } 
  //cout<<"filled visited_matrix"<<endl; // good up to here
  for(int row = 0; row < region.size(); row++){ //loop over rows
    //cout<<"looping over row: "<< row <<endl;
    for(int column = 0; column < region[row].size(); column++) { // loop over columns
      cout<< "iteration is at region["<<row<<"]["<<column<<"]"<<" = "<<region[row][column] << endl;
      //visited_matrix[row][column] = 1; // mark node visited
      //cout << "coordinate: ("<< row <<", "<< column <<") has been marked visited"<< endl;
      //cout << "region" <<"["<<row<<"]"<<"["<<column<<"]"<<" is: "<< region[row][column]<< endl;
      cout << "visited_matrix" <<"["<<row<<"]"<<"["<<column<<"]"<<" = "<< visited_matrix[row][column]<< endl;
 
      if(region[row][column] == 1 && visited_matrix[row][column] == 0){ // node is 1 and unvisited
        islands++;
        cout << "found an unvisited one at region[" << row << "][" << column << "]"<< endl;
        cout << "number of islands is now: " << islands<< endl;
        visited_matrix[row][column] = 1;
        cout << "visited_matrix" <<"["<<row<<"]["<<column<<"]"<< " has been marked visited"<<endl;
        // do bfs
        cout<<"running bfs..."<<endl;
        queue<int*> bfs_queue;
        //int cur_node = convert_index(row, column); 
        int cur_node[2] = {row, column};
        bfs_queue.push(cur_node);
        cout<< "{"<<row<<", "<<column<<"} was pushed to the queue"<<endl;
        //cout << "entering while loop"<<endl;
        while(bfs_queue.size() != 0) {
          cout << "inside while loop" << endl;
          //cout << "bfs queue size is: "<< bfs_queue.size()<< endl;
          int* cur_node = bfs_queue.front();
          bfs_queue.pop();

          cout <<"{"<<cur_node[0]<<", "<<cur_node[1]<< "} was popped from the queue"<< endl;
          cout << "cur_node is {"<< cur_node[0] <<", "<< cur_node[1] <<"}"<<endl;
         
          // for all neighbors
          int neighbor_checker = 1;
          for(int i = 0; i < 2; i++){
            cout << "entering for loop" <<endl; // stuck in  for loop
            
            
            // this makes sure we dont excede indexing boundaries
            int neighbor_row = floor(cur_node[0] + neighbor_checker);
            
            //cout<< "neighbor_row is "<< neighbor_row <<endl;
            //cout<< "region.size() is " << region.size()<<endl;
            
            int neighbor_column = floor(cur_node[1] + neighbor_checker);
            
            if(neighbor_row < 0){
              neighbor_row = 0;
            }
            if(neighbor_column < 0){
              neighbor_column = 0;
            }
            if(neighbor_row >= region.size() - 1) {
              neighbor_row = region.size() - 1;
            }
            if(neighbor_column >= region[row].size() - 1) {
              neighbor_column = region[row].size() - 1;
            }
        

            //cout<< "neighbor_row is " << neighbor_row <<endl;
            
            
            int updown_neighbor = region[neighbor_row][cur_node[1]];
            int left_right_neighbor = region[cur_node[0]][neighbor_column];

            if(i == 0){
              cout<<"first updown_neighbor is region["<<neighbor_row<<"]["<<cur_node[1]<<"]"<< " = " << region[neighbor_row][cur_node[1]] << endl;
              cout<<"first leftright_neighbor is region["<<cur_node[0]<<"]["<<neighbor_column<<"]"<< " = " << region[cur_node[0]][neighbor_column]<< endl;
            } else {
              cout<<"second updown_neighbor is region["<<neighbor_row<<"]["<<cur_node[1]<<"]"<< " = " << region[neighbor_row][cur_node[1]] << endl;
              cout<<"second leftright_neighbor is region["<<cur_node[0]<<"]["<<neighbor_column<<"]"<< " = " << region[cur_node[0]][neighbor_column] << endl;
            }
            //cout<<"visited_matrix["<<row + neighbor_checker<<"]["<<column<<"]"<< " = " << visited_matrix[row + neighbor_checker][column] << endl;
            
            // make variables for neighbor indicies and ensure they are within region boundaries
            int updown_neighbor_index = cur_node[0] + neighbor_checker;
            //cout << "row is "<<row<< "neighbor_checker is " << neighbor_checker<< endl;
            int left_right_neighbor_index = cur_node[1] + neighbor_checker;
            
            



            if(updown_neighbor_index <  0){
              updown_neighbor_index = 0;
            } else if(updown_neighbor_index > region.size()){
                updown_neighbor_index = region.size();
            }
            if(left_right_neighbor_index < 0){
              left_right_neighbor_index = 0;
            } else if(left_right_neighbor_index > region[row].size()) { 
                left_right_neighbor_index = region[row].size();
            }
            cout<<"updown_neighbor_index: "<<updown_neighbor_index<<" ";
            cout<<"left_right_neighbor_index: "<<left_right_neighbor_index<<endl;
            cout<<"column: "<<column;
            cout<<" row: "<<row<<endl;
 

            cout<<"visited_mat["<<updown_neighbor_index<<"]["<<column<<"] = "<< visited_matrix[updown_neighbor_index][column] << endl;
            cout<<"row is: "<<row<< " column is: "<<column<<endl;
            if(updown_neighbor == 1 && visited_matrix[updown_neighbor_index][column] == 0){
              // enqueue node
              int updown_neighbor[2] = {updown_neighbor_index, column};
              bfs_queue.push(updown_neighbor);
              cout<<"{"<<updown_neighbor[0]<<", "<<updown_neighbor[1]<<"} ud was pushed to the queue"<<endl;
              cout << "bfs_queue size is now "<<bfs_queue.size()<<endl;
              visited_matrix[updown_neighbor_index][column] = 1;
              cout << "visited_matrix" <<"["<<updown_neighbor_index<<"]["<<column<<"]"<< " has been marked visited"<<endl;
            }
            //cout<< "vm["<<row<<"]["<<column+neighbor_checker<<"] = "<< visited_matrix[row][column + neighbor_checker]<<endl;
            if(left_right_neighbor == 1 && visited_matrix[row][left_right_neighbor_index] == 0){
              int left_right_neighbor[2] = {row, left_right_neighbor_index};
              bfs_queue.push(left_right_neighbor);
              cout<<"{"<<left_right_neighbor[0]<< ", "<< left_right_neighbor[1]<<"} lr was pushed to the queue"<<endl;
              visited_matrix[row][left_right_neighbor_index] = 1;
              cout << "visited_matrix" <<"["<<row<<"]["<<left_right_neighbor_index<<"]"<< "has been marked visited"<<endl;
            }
            neighbor_checker = -neighbor_checker;
          }
        }
      }    
    } 
  }
  cout<< "returning " << islands<<endl;
  return islands;
}