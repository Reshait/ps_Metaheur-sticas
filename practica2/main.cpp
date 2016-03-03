#include <iostream>
//Añadir includes, clases, etc...

class NeighOperatorKP{
    SolutionKP* generateNeight(SolutionKP* sCurrent, int pos){
        //ESTO ES DEMASIADO FÁCIL
    }
};

class FirstNeighExplorator : public AbstractNegh...or{
protected:
    Random *random;
    AbstractProblemInstance *problemInstance;
public:
    FirstNeighExplorator(AbstractProblemInstance *problemInstance, Random *random){
        this.random = random;
        //algo como this.problemInstance...
    }
    SolutionKP* exploreNg(SolutionKP* sCurrent, AbstractNeighOperatorKP *operator){

        Solution *neighSol = NULL;

        int numPosibilities = operator.getNumPosParam();
        random.generatePermutation(permutation, numPosibili);

        for(int i = 0; i < numPosibilities; i++){
            neightSol = operator.generateNeigh(sCurrent, permutation[i]);
            problemInstance.evaluate(neightSol);

            if(problemInstance.isBetter(neighSol, sCurrent)){
                return neightSol;
            }
        }

        return neighSol;
    }
};

class LocalSearch{
protected:
    AbstractNeighOperator *operator;
    Random *random;
    AbstractNeightExplorator *explorator;

public:
    LocalSearch(....){
        this.random = random;
        //--> cree que lo podría eliminar -->this.operator = operator;

    }

    Solution* applyLS(Solution* initialSol){
        Solution* currentSol = initialSol ->copy();
        Solution* neigh = explorator.exploreNg(currentSol);

        while(neigh != NULL){
            currentSol ->copy(neigh);
            neigh = explorator.exploreNg(currentSol);
        }

        delete neigh;
        return currentSol;
    }
}
