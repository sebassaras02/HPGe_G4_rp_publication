#include "runaction.hh"

// define the constructor
runaction::runaction(){}
// define the destructor
runaction::~runaction(){}

void runaction::BeginOfRunAction(const G4Run* run){
    // initializate the run manager to store the hits
    G4AnalysisManager*man = G4AnalysisManager::Instance();
    // create a file for each run
    G4int RunID = run->GetRunID();
    std::stringstream strRunID;
    strRunID<<RunID;
    //man->SetHistoDictoryName("histograms");
    // create the root file
    man->OpenFile("output"+strRunID.str()+".root");
    
    man->CreateNtuple("Edep","Edep");
    man->CreateNtupleDColumn("fedep");
    man->FinishNtuple(0);
    
}
void runaction::EndOfRunAction(const G4Run*){
    // initializate the run manager to store the hits
    G4AnalysisManager*man = G4AnalysisManager::Instance();
    // write all the edep in the root file
    man->Write();
    // close root file
    man->CloseFile();
}
