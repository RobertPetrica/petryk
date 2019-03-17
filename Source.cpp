#include <iostream>
#include "mpi.h"

using namespace std;

void NumarPrim(int, int);

int main(int argc, char *argv[]) {

	int LIMIT = 100;
	int numberOfProcesses;
	int processRank;
	int error;
	int length;

	error = MPI_Init(&argc, &argv);
	if (error != MPI_SUCCESS) {
		cout << "Error starting MPI program. Terminating.\n";
		MPI_Abort(MPI_COMM_WORLD, error);
	}

	MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcesses);

	length = LIMIT / numberOfProcesses;

	MPI_Comm_rank(MPI_COMM_WORLD, &processRank);
	if (processRank != numberOfProcesses - 1)
		NumarPrim(length * processRank, length * processRank + length);
	else
		NumarPrim(length * processRank, LIMIT);

	MPI_Finalize();
}

void NumarPrim(int start, int stop) {

	for (int number = (start < 2 ? 2 : start); number < stop; number++)
/*If (start<2)
Return 2
Else return start
*/
	{
		bool isPrim = true;
		for (int div = 2; div <= number / 2; ++div)
			if (number % div == 0)//restul impartirii
			{
				isPrim = false;
				break;
			}
		if (isPrim)
		{
			int processRank;
			MPI_Comm_rank(MPI_COMM_WORLD, &processRank);
			cout << "Number : " << number << " -> Process : " << processRank << endl;
		}
	}
}