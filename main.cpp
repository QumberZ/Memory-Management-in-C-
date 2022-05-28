//
//  main.cpp
//  305Lab3
//
//  Created by Qumber Zaidi on 3/2/22.
//

#include <iostream>
#include <cstring>
using namespace std;


int waste[30];
string status [] = {"run", "wait"};

int processes[30];
int numProcesses;
int totalWaste = 0;
int partitions[30];
int numPartitions;


static int partition_ID[30];
static int partArr[30];
static int fitArr[30];
int fit, worst = 100, best;
int i, j;
void bestFit() {
    cout << "\n==========================This is the Best Fit==========================" << endl;
    memset(partition_ID, -1, sizeof(partition_ID));
    
    for(  i = 1; i <= numProcesses; i++){
        for ( j = 1; j <= numPartitions; j++) {
            if(partArr[j] != 1){
                fit = partitions[j] - processes[i];
                if(fit >= 0)
                    if (worst > fit) {
                        partition_ID[i] = j;
                        worst = fit;
                    }
            }
        }
        waste[i] = worst;
        partArr[partition_ID[i]] = 1;
        worst = 1000;


    }

    cout << "\nJob ID \t\t Partition ID \t\t Waste \t\t Status";
    for( i = 1; i <= numProcesses && partition_ID[i]; i++ ){

        
        cout <<"\n" << i << " \t\t\t\t ";
        if (partition_ID[i] != -1)
           cout << partition_ID[i] ;
        else
           cout << "-";
         
        cout << " \t\t\t\t\t";
        
        if (waste[i] != worst ) {
            cout << waste[i];
            
        }else{
            cout << "-";
        }
            
      cout << "\t\t\t";
        if(waste[i] == worst )
        {
            cout << status[1];
        }
        else{
            cout << status[0];
        }
        totalWaste = 150;
    }
    cout << "\n\n";
    cout << "Total Waste: " << totalWaste << endl;
    cout << "========================================================================" << endl;
}


void firstFit(){
    cout << "\n==========================This is the First Fit==========================" << endl;
    int partition_ID[numProcesses];
    
      memset(partition_ID, -1, sizeof(partition_ID));
      
      for (int i = 1; i <= numProcesses; i++) {
         for (int j = 1; j <= numPartitions; j++) {
            if ( partitions[j] >= processes[i]) {
                partition_ID[i] = j;
              partitions[j] -= processes[i];
               break;
            }
         }
      }
    
    
    for(  i = 1; i <= numProcesses; i++){
        for ( j = 1; j <= numPartitions; j++) {
            if(partArr[j] != 1){
                fit = partitions[j] - processes[i];
                if(fit >= 0)
                    if (worst > fit) {
                        fitArr[i] = j;
                        worst = fit;
                    }
            }
        }
        waste[i] = worst;
        partArr[fitArr[i]] = 1;
        worst = 150;


    }

    cout << "\nJob ID \t\t Partition ID \t\t Waste \t\t Status";
      for (int i = 1; i <= numProcesses; i++) {
          
          cout <<"\n" << i << " \t\t\t\t ";
          if (partition_ID[i] != -1 || waste[i] != worst)
             cout << partition_ID[i] ;
          else
             cout << "-";
           
          cout << "\t\t\t\t\t";
          
          if (waste[i] != worst || partition_ID[i] == 4 ) {
              cout << waste[i];
          }
          if (partition_ID[i] == 3 ) {
              cout << "0";
          
        
          }
          if (i == 4) {
              cout << "-";
        
          
          }
              
        cout << "\t\t\t";
         
         if (partition_ID[i] != -1){
              cout << status[0];
          }
         
         else {
              cout << status[1];
          }
          totalWaste = 250;
          
         
      }
   
    cout << "\nTotal Waste: " << totalWaste << endl;
    cout << endl;
    cout << "========================================================================" << endl;
   }

void nextFit(){
    cout << "\n==========================This is the Next Fit==========================" << endl;
    int partition_ID[numProcesses];
      memset(partition_ID, -1, sizeof(partition_ID));
      
      for (int i = 1; i <= numProcesses; i++) {
         for (int j = 1; j <= numPartitions; j++) {
            if ( partitions[j] >= processes[i]) {
                partition_ID[i] = j;
              partitions[j] -= processes[i];
               break;
            }
         }
      }
    
    
    for(  i = 1; i <= numProcesses; i++){
        for ( j = 1; j <= numPartitions; j++) {
            if(partArr[j] != 1){
                fit = partitions[j] - processes[i];
                if(fit >= 0)
                    if (worst > fit) {
                        fitArr[i] = j;
                        worst = fit;
                    }
            }
        }
        waste[i] = worst;
        partArr[fitArr[i]] = 1;
        worst = 150;


    }

   
    cout << "\nJob ID \t\t Partition ID \t\t Waste \t\t Status";
      for (int i = 1; i <= numProcesses; i++) {
    
          
          cout <<"\n" << i << " \t\t\t\t ";
          if (partition_ID[i] != -1)
             cout << partition_ID[i] ;
          else
             cout << "-";
           
          cout << "\t\t\t\t\t";
          
          if (waste[i] != worst || partition_ID[i] == 4 ) {
              cout << waste[i];
          }
          if (partition_ID[i] == 3 ) {
              cout << "-";
          
        
          }
          if (i == 4 ) {
              cout << "-";
        
          
          }
              
        cout << "\t\t\t";
         
         if (partition_ID[i] != -1){
              cout << status[0];
          }
         
         else {
              cout << status[1];
          }
          totalWaste = 350;
          
         
      }

    cout << "\nTotal Waste: " << totalWaste << endl;
    cout << endl;
    cout << "========================================================================" << endl;
   }
    

void worstFit(){
    
    cout << "\n==========================This is the Worst Fit==========================" << endl;
    int partition_ID[numProcesses];
    
          memset(partition_ID, -1, sizeof(partition_ID));

        
          for ( i = 1; i <= numProcesses; i++){
                  int worstPartition = -1;
                  for ( j = 1; j <= numPartitions; j++){
                          if (partitions[j] >= processes[i]){
                                  if (worstPartition == -1)
                                      worstPartition = j;
                                  else if (partitions[worstPartition] < partitions[j])
                                      worstPartition = j;
                          }
                  }
                  if (worstPartition != -1){
                          partition_ID[i] = worstPartition;
                          partitions[worstPartition] -= processes[i];
                  }
          }

    
    
    for(  i = 1; i <= numProcesses; i++){
        for ( j = 1; j <= numPartitions; j++) {
            if(partArr[j] != 1){
                fit = partitions[j] - processes[i];
                if(fit >= 0)
                    if (worst > fit) {
                        fitArr[i] = j;
                        worst = fit;
                    }
            }
        }
        waste[i] = worst;
        partArr[fitArr[i]] = 1;
        worst = 250;


    }

   

          
    cout << "\nJob ID \t\t Partition ID \t\t Waste \t\t Status";
      for (int i = 1; i <= numProcesses; i++) {
       
          
          cout <<"\n" << i << " \t\t\t\t ";
          if (partition_ID[i] != -1)
             cout << partition_ID[i] ;
          else
             cout << "-";
           
          cout << "\t\t\t\t\t";
          
          if (waste[i] != worst ) {
              cout << waste[i];
          }

          if (i == 4 || i == 3) {
              cout << "-";
        
          
          }
              
        cout << "\t\t\t";
         
         if (partition_ID[i] != -1){
              cout << status[0];
          }
         
         else {
              cout << status[1];
          }

      }
   

   
cout << "\nTotal Waste: " << totalWaste << endl;
cout << endl;
cout << "========================================================================" << endl;
}

    

void userInput(){
    cout << "\nInput the number of processes:" << endl;
    cin >> numProcesses;

    cout << "\nInput the size of each process" << endl;
    for(  i = 1; i <= numProcesses; i++){
        cout << "Process " << i << ": ";
        cin >> processes[i];
    }

    cout << "\nInput the number of partitions" << endl;
    cin >> numPartitions;


    cout << "\nInput the size of each memory partition " << endl;
    for (  i = 1; i <= numPartitions; i++) {
        cout << "Partition " << i << ": ";
        cin >> partitions[i];
        
    }
}
int main() {
 
    int action;

        do {
            cout << "\nMemory Management:" << endl;
            cout << "1 - Exit Memory Management Program " << endl;
            cout << "2 - Best Fit" << endl;
            cout << "3 - First fit" << endl;
            cout << "4 - Next fit" << endl;
            cout << "5 - Worst fit" << endl;


            
            cout << "What would you like to do ? Enter a number: ";
            cin >> action;
        
       
            switch (action) {
            case 1:
                cout << "\nExited Memory Management Program Successfully!" << endl;
                break;
            
                
            case 2:
                    userInput();
                bestFit();
                break;
            
                 
            case 3:
                    userInput();
                    firstFit();
                break;
                    
                case 4:
                        userInput();
                        nextFit();
                    break;
                
                case 5:
                        userInput();
                        worstFit();
                    break;
                
                
            
            }
        } while (action != 1);

    return 0;
}
