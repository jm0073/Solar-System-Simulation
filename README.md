# Solar System Simulation Project

Our project aims to create an immersive virtual environment simulating the solar system using OpenGL and fundamental concepts of computer graphics. Users can explore the celestial bodies orbiting the Sun, view them from different perspectives, and interact with various elements of the system.

## Key Features

- **Interactive Camera Control:** Users can dynamically adjust the camera view using keyboard interrupts, enabling them to navigate around the solar system and observe the movements of planets and moons.
- **Realistic Rendering:** Experience lifelike representations of the Sun, planets, moons, and orbit lines, providing an authentic simulation of the solar system.
- **Dynamic Elements:** Certain elements such as ambient light and orbit lines can be toggled on or off, allowing users to customize their viewing experience.

## Implementation Details

- **Orbit Calculation:** The distances and comparative angles of the planets' orbits are calculated to accurately position them around the Sun.
- **Display List Optimization:** Objects representing celestial bodies and orbit lines are encapsulated in display lists, ensuring efficient rendering and smooth animation.
- **Camera Movement:** Camera movement is achieved by adjusting the view angles and distance, providing users with flexible control over their exploration of the solar system.

## Controls

- **Arrow Keys:** Adjust the view angle to explore the solar system from different perspectives.
- **'i', 'o':** Zoom in or out to focus on specific areas of interest.
- **'n':** Toggle ambient light on or off to adjust the illumination of the scene.
- **'m':** Toggle orbit lines on or off to visualize the paths of the planets' orbits.
- **Left Mouse Button:** Reset the view angles to the left view.
- **Home Button:** Reset the view to the top view.

Our project serves as an educational tool for learning about the solar system while providing an engaging and interactive experience. It offers a captivating way to explore the wonders of space using OpenGL and computer graphics principles.

## Computer Graphics Concepts Used

| Sr. No | Computer Graphics Concept | Description | Usage |
|--------|----------------------------|-------------|-------|
| 1      | OpenGL Primitives          | Use of basic shapes to construct objects | Constructing the Sun, planets, Moon, and Saturn's rings |
| 2      | Lighting                   | Simulation of sunlight as a light source | Illuminating the Sun and planets |
| 3      | Material Properties        | Setting material properties for objects | Defining colors and textures for the Sun, planets, Moon, and Saturn's rings |
| 4      | Display Lists              | Optimizing rendering performance | Encapsulating objects and orbit lines in display lists for efficient rendering |
| 5      | Camera Control             | Adjusting view angles and distance | Allowing users to explore the solar system from various perspectives |
| 6      | Keyboard and Mouse Input   | Handling user input for interaction | Controlling camera movement, toggling ambient light, and orbit lines |
| 7      | Coordinate Calculation     | Calculating positions of celestial bodies | Positioning the planets and Moon in their orbits around the Sun |
| 8      | Animation                  | Incremental updates for dynamic elements | Rotating planets and Moon for animation |

## Output and Screenshots

- **Fig 1:** Default view of the program
  ![Screenshot 2024-08-05 190808](https://github.com/user-attachments/assets/4b3cad9e-0ad8-400e-914c-b4e08d11d854)



- **Fig 2:** Left-side view without orbits and ambient light
  ![image](https://github.com/user-attachments/assets/964a0102-afb0-4812-9eda-171a8d155a94)



- **Fig 3:** Top view without orbits and ambient light
  ![image](https://github.com/user-attachments/assets/15cf37e2-8b6f-4c4c-8a61-94786e35b7c4)



- **Fig 4:** Top view with orbits and ambient light
  ![image](https://github.com/user-attachments/assets/d1cc8814-dc40-4a4d-ad9e-1095dd7f1ffc)



- **Fig 5:** Left-side view with orbits and ambient light
  ![image](https://github.com/user-attachments/assets/79210f13-9168-421f-9bdc-d137e50c2191)



- **Fig 6:** Zoomed-in view
  ![image](https://github.com/user-attachments/assets/a6532193-6231-4cf6-b0ad-ae9152134917)



- **Fig 7:** Zoomed-out view
  ![image](https://github.com/user-attachments/assets/9b886746-b581-4162-bfda-a4b9c6986cb1)

