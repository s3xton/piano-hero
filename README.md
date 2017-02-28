# PianoHero: Augmented Reality MIDI-to-Piano Learning Assistant

The aim of this project is to augment a 2D representation of a MIDI file over a piano keyboard. This is interesting as it can be used as a learning assistant for students of any level to learn any piece (song) on the piano. MIDI files are available for almost every sheet music that has been produced, therefore, this application has a wide use of over a millions different MIDI files available free online. 

There are three main components to this project:

### 1. Converting MIDI to 2D Representation
We plan to extract the data by parsing a MIDI file to a 2D representation, where the width of the representation is the key on the piano, and the depth is time or duration of the note. We will use OpenGL to create the model of the representation.

### 2. Finding and Tracking the Piano keys 
For finding and tracking the piano we plan to place markers at either side of the keyboard. Using ARToolKit we can find these markers are get the location of the keyboard in the scene. For finding and tracking the keys we plan to use OpenCV. Test data can be found from online pictures of a piano keyboard.

### 3. Augmenting the representation to the piano 
We will use OpenGL to create a model of our 2D representation. Then, we will use the pose matrix returned from step 2 to augment this model over the piano in real time.

Ideally this application would run on a HoloLens, allowing the user to see the augmentations in their field of view. However, we do not have access to one for development and the emulator does not have enough functionality for our purposes. For these reasons, we will develop the application to run using a computer with an attached webcam, with a view to porting it to the HoloLens at some point in the future.

