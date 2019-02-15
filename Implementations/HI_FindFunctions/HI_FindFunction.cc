#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Pass.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include "HI_print.h"
#include "HI_FindFunction.h"
#include <stdio.h>
#include <string>
#include <ios>
#include <stdlib.h>

using namespace llvm;

bool HI_FindFunctions::runOnModule(Module &M) // The runOnModule declaration will overide the virtual one in ModulePass, which will be executed for each Module.
{
    for (Module::iterator GI = M.begin(),GE = M.end(); GI != GE; ++GI) //Module iterator is used to iterate the functions in the module, ++GI is better than GI ++, for the sake of stability
    {
        outs() << "Found function named == " << GI->getName() << "\n"; // a Function class is inherited from Value class, which has a function to get the name of the value (function).
    }
    return false;
}

char HI_FindFunctions::ID = 0;  // the ID for pass should be initialized but the value does not matter, since LLVM uses the address of this variable as label instead of its value.

void HI_FindFunctions::getAnalysisUsage(AnalysisUsage &AU) const {
  AU.setPreservesAll();
}
