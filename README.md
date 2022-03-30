# HPGe GEANT4 Application

This simulation was made as part of a larger project, which aims to simulate volumetric sources
in order to calibrate radiation detectors. The project in the future will be focused on improving 
the simulation through adapting radioactive sources with irregular volume.

## Done by: Sebastián Sarasti Zambonino

> This application and research did not have any direct founding.

## Details of the application:

The simulation connects several classes to work properly:

- Detector construction class: there is defined the materials and volumes
- Physics list: there is defined the process the simulation will use and setcut range value (default)
- Primary generator: there is defined the method to generate particles, in this application was used general particle source to be user-friendly
- Run Action: generates a graph per run and save it like root file
- Event Action: plot the result of energy deposited per event
- Stepping Action: get the energy deposited of each step in the target volumes

## Installation

Copy the repository in your Linux operative system. Then create a folder where you are going to compile the application (build folder).

To compile
```sh
cd build
cmake ..
make -j (number of threads of your PC)
```

To execute without bash mode
```sh
./naidetector 
```

To execute in bash mode
```sh
./naidetector  macrocommand.mac
```

## License

MIT

You are free to use this application and improve it. The commercial use it is not allowed without the owner permission (Sebastián Sarasti).



