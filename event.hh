#ifndef event_hh
#define  event_hh

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "g4root.hh"
#include "runaction.hh"

class eventaction : public G4UserEventAction 
{
public:
    eventaction(runaction*);
    ~eventaction();
    
    // call necessary methods
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
    // create a function to add all values of each event
    void AddEdep(G4double edep){fEdep+=edep;};
    
    private:
    G4double fEdep;
};

#endif
