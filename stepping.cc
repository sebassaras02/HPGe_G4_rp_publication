#include "stepping.hh"
#include "G4RunManager.hh"



steppingaction::steppingaction(eventaction* eventAction){
    
    fEventAction=eventAction;
}

steppingaction::~steppingaction(){}

void steppingaction::UserSteppingAction (const G4Step* step){
    
    const detectorconstruction* detectorConstruction = static_cast<const detectorconstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
        
    G4LogicalVolume* fScoringVolume = detectorConstruction->GetScoringVolume();
    
    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
    
    if (volume != fScoringVolume) 
        return;
    // get edep of each step
    G4double edep= step->GetTotalEnergyDeposit();
    
    // integrate all edep of each event
    // if (edep<0*MeV) return ;
    fEventAction->AddEdep(edep);
    
}
