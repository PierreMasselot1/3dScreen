# 3dScreen
This was one of my projects in the year 2018-2019 and the purpose was to rotate a screen and update the 3d model displayed in correlation with that. A key feature was that the screen would follow the user using computer vision.

The code is split in 4 parts, the main cpp file that handles computer vision, face detection and face tracking. It then sends all the needed data to a dll which acts as a bridge between the main cpp file and Blender(3d modeling and rendering software) python file. The cpp file also send the data to the arduino using serial communication.

The physical assembly can be seen in the final paper that is in french, it isn't well designed and we were working on a second version but I moved on to my current project before I had time to finish the design. If you want something more functional I recommend going for a gear setup with a high enough ratio to move the screen, one improvement path that we had was to add a slip ring in order to pass the power to the screen through the rotating platform and to use a chromecast to replace the hdmi cable, enabling true full 360 degree rotation.
