#include "detectorconstruction.hh"

// contructor
detectorconstruction::detectorconstruction()
{}
// destructor
detectorconstruction::~detectorconstruction()
{}
// define a function to create NaI detectors 

// add properties and volumenes
G4VPhysicalVolume* detectorconstruction::Construct()
{
  // Get nist material manager
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  nist->SetVerbose(1);
  
  // Envelope parameters
  //
  G4double env_sizeX = 1*m;
    
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       env_sizeX, env_sizeX, env_sizeX);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  // CUERPO 1
  // Definir el material
  // se genera el aluminio
  G4Material* aluminio = nist->FindOrBuildMaterial("G4_Al");
  // se genera el solido
  G4double innerRadius, outerRadius, hz, startAngle, spanningAngle; 
  G4Tubs*recubrimiento = new G4Tubs("rs",innerRadius=0*cm,outerRadius=3.9*cm,hz=6.32*cm,
  startAngle=0.*deg,spanningAngle=360.*deg);
  // se crea el volumen logico
  G4LogicalVolume* logic_recubrimiento =
                        new G4LogicalVolume(recubrimiento,          //its solid
                        aluminio,           //its material
                        "rl");            //its name
  // se genera el volumen fisico
  G4ThreeVector pos1 = G4ThreeVector(0.*cm,0*cm,0*cm);
  new G4PVPlacement(0,                        //no rotation
                    pos1,                    //at position
                    logic_recubrimiento,     //its logical volume
                    "rf",                   //its name
                    logicWorld,              //its mother  volume
                    false,                    //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking  
  
  // CUERPO 2
  // Definir el material
  // se genera el aire 
  // se genera el elemento

  G4Material*aire= nist->ConstructNewGasMaterial("Coldair","G4_AIR",77.*kelvin,0.71*atmosphere);
  // se genera el solido
  G4Tubs*enfriamiento= new G4Tubs("es",innerRadius=0*cm,outerRadius=3.6*cm,hz=6.22*cm,
  startAngle=0.*deg,spanningAngle=360.*deg);
  // se crea el volumen logico
  G4LogicalVolume* logic_enfriamiento =
                        new G4LogicalVolume(enfriamiento,          //its solid
                        aire,           //its material
                        "el");            //its name
  // se genera el volumen fisico
    new G4PVPlacement(0,                        //no rotation
                    pos1,                    //at position
                    logic_enfriamiento,     //its logical volume
                    "ef",                   //its name
                    logic_recubrimiento,              //its mother  volume
                    false,                    //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking   
  
  // CUERPO 3
  // Definir el material
  // se genera el litio
  

  G4Material* litio = new G4Material( "li",				//its name
                   3, 				//atomic number
                   6.941,					//mass of mole
                   0.53*g/cm3, 				//density
                   kStateSolid,	//solid,gas
                   77*kelvin,	//temperature
                   0.71*atmosphere);	//pressure
  // se genera el solido
  G4Tubs*s_litio = new G4Tubs("ls",innerRadius=0*cm,outerRadius=2.545*cm,hz=1.02*cm,
  startAngle=0.*deg,spanningAngle=360.*deg);
  // se crea el volumen logico
  G4LogicalVolume* logic_litio =
                        new G4LogicalVolume(s_litio,          //its solid
                        litio,           //its material
                        "ll");            //its name
  // se genera el volumen fisico
  G4double z2= (6.22-0.4-1.02)*cm;
  G4ThreeVector pos2 = G4ThreeVector(0.*cm,0*cm,z2);
  new G4PVPlacement(0,                        //no rotation
                    pos2,                    //at position
                    logic_litio,     //its logical volume
                    "lf",                   //its name
                    logic_enfriamiento,              //its mother  volume
                    false,                    //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking  
  
  // CUERPO 4
  // Definir el material
  // se genera el germanio
  G4Material* germanio =  new G4Material( "ge",				//its name
                   32, 				//atomic number
                   72.64,					//mass of mole
                   5.32*g/cm3, 				//density
                   kStateSolid,	//solid,gas
                   77*kelvin,	//temperature
                   0.71*atmosphere);	//pressure
  // se genera el solido
  G4Tubs*s_germanio = new G4Tubs("gs",innerRadius=0*cm,outerRadius=2.525*cm,hz=1*cm,
  startAngle=0.*deg,spanningAngle=360.*deg);
  // se crea el volumen logico
  logic_ger1 =new G4LogicalVolume(s_germanio,          //its solid
                        germanio,           //its material
                        "gl");            //its name
  fScoringVolume=logic_ger1;
  // se genera el volumen fisico
  new G4PVPlacement(0,                        //no rotation
                    pos1,                    //at position
                    logic_ger1,     //its logical volume
                    "gf",                   //its name
                    logic_litio,              //its mother  volume
                    false,                    //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking  
  
  //
  return physWorld;
}




