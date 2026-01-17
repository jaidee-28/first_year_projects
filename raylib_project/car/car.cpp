#include "raylib.h"
#include <math.h> // For sinf, cosf, fmin, fmax

// Define the Car structure
typedef struct Car {
    Vector2 position;
    float speed;
    float maxSpeed;
    float acceleration;
    float friction;
    float rotation; // Angle in degrees
    float rotationSpeed;
    Color color;
} Car;

// Function to initialize the car
Car InitCar(Vector2 startPos, Color c) {
    Car car = { 
        .position = startPos, 
        .speed = 0.0f,
        .maxSpeed = 250.0f,
        .acceleration = 10.0f,
        .friction = 5.0f, // Braking force and drag
        .rotation = 90.0f, // Start facing up
        .rotationSpeed = 1.8f,
        .color = c
    };
    return car;
}

// Function to update the car's state
void UpdateCar(Car *car, float deltaTime) {
    // 1. Input Handling (Acceleration/Braking)
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        car->speed += car->acceleration * deltaTime;
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        car->speed -= car->acceleration * deltaTime * 2.0f; // Braking is stronger
    }

    // 2. Limit Speed
    car->speed = fmaxf(-car->maxSpeed * 0.5f, fminf(car->maxSpeed, car->speed));
    
    // 3. Apply Friction/Drag
    if (car->speed > 0) {
        car->speed -= car->friction * deltaTime;
        if (car->speed < 0) car->speed = 0;
    } else if (car->speed < 0) {
        car->speed += car->friction * deltaTime;
        if (car->speed > 0) car->speed = 0;
    }
    
    // 4. Input Handling (Steering)
    if (fabsf(car->speed) > 10.0f) { // Only allow steering when moving
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            // Turn opposite direction when reversing
            car->rotation -= car->rotationSpeed * deltaTime * (car->speed > 0 ? 1.0f : -1.0f) * 60.0f;
        } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            // Turn opposite direction when reversing
            car->rotation += car->rotationSpeed * deltaTime * (car->speed > 0 ? 1.0f : -1.0f) * 60.0f;
        }
    }

    // 5. Update Position
    float rad = car->rotation * DEG2RAD;
    
    car->position.x += cosf(rad) * car->speed * deltaTime;
    car->position.y += sinf(rad) * car->speed * deltaTime;
}

// Function to draw the car (a simple colored rectangle)
void DrawCar(Car car) {
    Vector2 origin = { 10, 20 }; // Half width and half height for rotation pivot (Car is 20x40)

    DrawRectanglePro(
        (Rectangle){ car.position.x, car.position.y, 20, 40 }, // Bounding box for the car
        origin, // Pivot point for rotation
        car.rotation + 90.0f, // Rotate so 0 degrees is right, but the car *looks* up (90 deg)
        car.color
    );
    
    // Draw a small indicator for the front of the car
    DrawRectanglePro(
        (Rectangle){ car.position.x, car.position.y, 8, 8 }, 
        (Vector2){ -4, -18 }, // Offset from center to the front bumper
        car.rotation + 90.0f,
        WHITE
    );
}


int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    // Set up the window
    InitWindow(screenWidth, screenHeight, "Raylib 2D Arcade Racer");
    
    // Initialize the car in the center of the screen
    Car myCar = InitCar((Vector2){ screenWidth / 2.0f, screenHeight / 2.0f }, RED);

    // Initialize the camera to follow the car
    Camera2D camera = { 0 };
    camera.target = myCar.position; // Camera looks at the car's initial position
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60); // Set desired screen frames per second

    // Main game loop
    while (!WindowShouldClose()) {
        
        // --- UPDATE ---
        
        float deltaTime = GetFrameTime();
        
        UpdateCar(&myCar, deltaTime);

        // Update the camera to follow the car's new position
        camera.target = myCar.position;
        
        // --- DRAW ---
        
        BeginDrawing();

            ClearBackground(GREEN); // Background is grass
            
            BeginMode2D(camera);
                
                // Draw the road (example: a large gray strip)
                DrawRectangle(-500, -500, 2000, 2000, DARKGRAY);
                
                // Draw a simple track boundary line
                DrawRectangleLines(50, 50, 700, 350,  BLACK);
                
                // Draw the car
                DrawCar(myCar);

            EndMode2D();
            
            // Draw UI/Debug info (not affected by camera)
            DrawText(TextFormat("Speed: %.1f km/h", fabsf(myCar.speed / 10.0f)), 10, 10, 20, BLACK);
            DrawText("Controls: WASD or Arrows", 10, 40, 20, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and unload graphics context
    
    return 0;
}