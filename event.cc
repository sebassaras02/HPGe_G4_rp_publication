#include "event.hh"

// initialize constructor
eventaction::eventaction(runaction*){
    // create variable 
    fEdep=0.;
}
// initialize destructor
eventaction::~eventaction(){}

// functions

void eventaction::BeginOfEventAction(const G4Event*){

    fEdep=0.; // this reset the value of energy deposited in each event
    
}

void eventaction::EndOfEventAction(const G4Event*){
    
    // at the end of each event it is neccesary to save the data recolected
    G4AnalysisManager* man= G4AnalysisManager::Instance();
    // if (fEdep<0.0*MeV) return;
    if (fEdep<=0.0*MeV) return;
    man->FillNtupleDColumn(0,0,fEdep);
    man->AddNtupleRow(0);
}
