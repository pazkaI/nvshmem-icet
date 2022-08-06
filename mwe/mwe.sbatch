#!/bin/bash
#SBATCH -p alpha
#SBATCH -N 1
#SBATCH -n 2
#SBATCH --mem=1500
#SBATCH --gpus-per-task=1
#SBATCH --time=00:01:00
#SBATCH --output=icet-mwe-%A.out

srun ./IceT_MWE