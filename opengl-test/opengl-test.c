#include <stdio.h>

#include "IceT.h"
#include "IceTMPI.h"

#include <GL/gl.h>

int main(int argc, char** argv) {

    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    IceTCommunicator icetComm = icetCreateMPICommunicator(MPI_COMM_WORLD);
    IceTContext icetContext = icetCreateContext(icetComm);
    icetDestroyMPICommunicator(icetComm);

    printf("Hello world from rank %d out of %d\n", world_rank, world_size);

    icetDestroyContext(icetContext);
    MPI_Finalize();
    exit(0);
}