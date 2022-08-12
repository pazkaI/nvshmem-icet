MPICXX=mpicxx
CUDA_HOME ?= /usr/local/cuda

# need mpi
ifndef MPI_HOME
$(error MPI_HOME is not set)
endif

# need icet
ifndef ICET_HOME
$(error ICET_HOME is not set)
endif

# gencode flags for ampere
GENCODE_FLAGS := -gencode arch=compute_80,code=sm_80 -gencode arch=compute_80,code=compute_80

# compiler flags
MPICXX_FLAGS += -DUSE_NVTX -I$(CUDA_HOME)/include -I$(ICET_HOME)/include -std=c++14
LD_FLAGS = -L$(CUDA_HOME)/lib64 -lcudart -L$(ICET_HOME)/lib -lIceTCore -lIceTMPI -lIceTGL -lGL -lnvToolsExt

icet-opengl: Makefile opengl-test.c
	$(MPICXX) $(MPICXX_FLAGS) opengl-test.c $(LD_FLAGS) -o opengl-test

.PHONY: clean
clean:
	rm opengl-test.o opengl-test