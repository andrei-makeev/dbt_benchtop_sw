# dbt_benchtop_sw
A set of programs used in the FDA's Digital Breast Tomosynthesis (DBT) benchtop system

'dbt_benchtop' folder:

MS Visual Studio 2013 (C++) graphical application to control the DBT benchtop system, we
built at the FDA, to acquire x-ray projection images with one of the three pre-set acquisition
geometries or in full-field digital mammography (FFDM) mode.
The purpose of sharing this code is to help developers and students who are putting together
a similar experimental system for the first time. The software also makes use of
the National Instruments NI DAQmx suite to support DAQmx interface board PCIe-6323 used for
triggering, detector commutation, measuring pulses, etc., as well as, PCommServer Pro2 library
by Delta Tau, to interact with the Turbo Clipper programmable multi-axis controller (PMAC) that
produces trajectories for the x-ray tube motion.
X-ray detector setup, generator settings, and filter selection are all done externally.
In DBT mode this program establishes communication with the motion controller, allows
to select and download one the three acquisition geometries motion controller (*.pmc) files
to the PMAC, move the x-ray tube motorized stages to the beginning of the circular arc, and
initiate a synchronized DBT acquisition scan. After the scan is completed the code
in the *.pmc program sends the three motorized stages back to their "home" positions to get
ready for the next acquisition.
Angular motion of an x-ray tube (swivel arm in clinical systems) here is realized in a more complex
fashion: circular arc trajectory is achieved with the two orthogonal linear stages and the rotary table
with the x-ray tube mounted on top. Such an implementation was due to the existing setup in the
laboratory. All currently implemented trajectories are of a step-and-shoot kind.
Analogic Anrad AXS-2430 amorphous Selenium x-ray detector is used for image registration
in a DBT mode. In FFDM mode, another detector, Teledyne Dalsa Xineos-2329 can be used. The user
has an option of choosing between the Anrad and the Xineos in FFDM regime.
PMC scripts for Delta Tau PMAC Turbo clipper controller are located in a 'pmc' folder. As of now
the absolute paths to these motion programs are hardcoded here under 'Acquisition geometry'.
Motion controller commands '&1b1r' and '&1b2r' tell the PMAC to execute the pieces of PMC script
that move the motorized stages to the beginning of the circular arc, and to begin
the DBT scan correspondingly.

'pmc' folder:

Contains programmable motion controller (PMC) scripts for Delta Tau Turbo PMAC Clipper with
DBT trajectories that emulate three clinical systems (in terms of angular range, number of
projections, and radius of rotation): Hologic Selenia, GE Essential, and Siemens Mammomat, as
well as the PFM setup file for the Turbo PMAC Clipper controller.

compute_dbt_arc.pro:

IDL program to calculate the x-ray focal spot toggle positions along the DBT arc in Cartesian
coordinates for three trajectory geometries as described above.
