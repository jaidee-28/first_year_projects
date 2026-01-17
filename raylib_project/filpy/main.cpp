
#include "raylib.h"
#include <math.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define GAME_TITLE "Filpy Flip (raylib)"
#define TARGET_FPS 60
#define GRAVITY 1000.0f          
#define JUMP_SPEED -450.0f       
#define PIPE_SPEED 200.0f        
#define PIPE_WIDTH 80            
#define PIPE_GAP_HEIGHT 150     
#define PIPE_SPAWN_INTERVAL 1.5f 
#define PIPE_COUNT 3            

typedef struct Player {
    Rectangle rect;
    float velocityY;
    Color color;
    Texture2D text;
} Player;

typedef struct Pipe {
    Rectangle topRect;
    Rectangle bottomRect;
    bool active;    
    bool scored;  
} Pipe;

static Music bgMusic = { 0 };
static Sound gameOverSound = { 0 };
static bool soundPlayed = false;

static Player player = { 0 };
static Pipe pipes[PIPE_COUNT] = { 0 };
static int score = 0;
static bool gameOver = false;
static float pipeTimer = 0.0f;


static void InitGame(void);        
static void UpdateGame(void);     
static void DrawGame(void);     
static void UnloadGame(void);      
static void SpawnPipe(void);      
static void ResetGame(void);        
 
  
int main(void)
{
   InitAudioDevice();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    
    bgMusic = LoadMusicStream("bgm.mp3");
    gameOverSound = LoadSound("game.mp3");
    InitGame();
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        UpdateGame();
   
        DrawGame();
    }

 
    UnloadGame();
     CloseAudioDevice();
    CloseWindow();
    return 0;
}


static void InitGame(void)
{
    
    
    player.rect = (Rectangle){ SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2 - 20, 40, 40 };
    if (player.text.id <= 0) {
        player.text = LoadTexture("raj.png.png"); 
    }
    player.velocityY = 0.0f;
    player.color = YELLOW;
    score = 0;
    gameOver = false;
    soundPlayed = false; 
    pipeTimer = PIPE_SPAWN_INTERVAL; 

    for (int i = 0; i < PIPE_COUNT; i++)
    {  PlayMusicStream(bgMusic);
        pipes[i].active = false;
        pipes[i].scored = false;
    }
    
}

static void ResetGame(void)
{
    InitGame();
}

// Spawns a new pipe configuration
static void SpawnPipe(void)
{

    int index = -1;
    for (int i = 0; i < PIPE_COUNT; i++)
    {
        if (!pipes[i].active)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        // Randomly determine the Y position of the gap center
        // Ensures the gap is not too close to the top or bottom edge
        int minCenterY = PIPE_GAP_HEIGHT;
        int maxCenterY = SCREEN_HEIGHT - PIPE_GAP_HEIGHT;
        int gapCenterY = GetRandomValue(minCenterY, maxCenterY);

        // Calculate top pipe height
        float topHeight = (float)gapCenterY - (PIPE_GAP_HEIGHT / 2.0f);

        // Top Pipe
        pipes[index].topRect = (Rectangle){
            (float)SCREEN_WIDTH, 0.0f, PIPE_WIDTH, topHeight
        };

        // Bottom Pipe
        pipes[index].bottomRect = (Rectangle){
            (float)SCREEN_WIDTH, (float)gapCenterY + (PIPE_GAP_HEIGHT / 2.0f),
            PIPE_WIDTH, (float)SCREEN_HEIGHT - (gapCenterY + (PIPE_GAP_HEIGHT / 2.0f))
        };

        pipes[index].active = true;
        pipes[index].scored = false;
    }
}

// Game logic update
static void UpdateGame(void)
{ UpdateMusicStream(bgMusic);
    if (gameOver)
    {   StopMusicStream(bgMusic);
        if (!soundPlayed) {
            PlaySound(gameOverSound); // Play death sound ONCE
            soundPlayed = true;
        }
        // Check for restart input
        if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            ResetGame();
        }
        return;
        UpdateMusicStream(bgMusic);
    }

  
    if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        player.velocityY = JUMP_SPEED;
    }

   
    float delta = GetFrameTime();

   
    player.velocityY += GRAVITY * delta;

    
    player.rect.y += player.velocityY * delta;

   
    pipeTimer -= delta;
    if (pipeTimer <= 0.0f)
    {
        SpawnPipe();
        pipeTimer = PIPE_SPAWN_INTERVAL;
    }

    // --- 4. Pipe Movement and Recycling ---
    for (int i = 0; i < PIPE_COUNT; i++)
    {
        if (pipes[i].active)
        {
            // Move pipe left
            pipes[i].topRect.x -= PIPE_SPEED * delta;
            pipes[i].bottomRect.x -= PIPE_SPEED * delta;

            // Check if pipe is off-screen (recycle it)
            if (pipes[i].topRect.x + PIPE_WIDTH < 0)
            {
                pipes[i].active = false;
            }

            // Check for scoring (Player passes the pipe center line)
            if (!pipes[i].scored && player.rect.x > pipes[i].topRect.x + pipes[i].topRect.width)
            {
                score++;
                pipes[i].scored = true;
            }
        }
    }

    // --- 5. Collision Detection ---

    // Collision with ground or ceiling (immediate game over)
    if (player.rect.y <= 0 || player.rect.y + player.rect.height >= SCREEN_HEIGHT)
    {
        gameOver = true;
        // Clamp player to the ground
        if (player.rect.y + player.rect.height > SCREEN_HEIGHT)
            player.rect.y = SCREEN_HEIGHT - player.rect.height;
        // Clamp player to the ceiling
        if (player.rect.y < 0)
            player.rect.y = 0;
    }

    // Collision with pipes
    for (int i = 0; i < PIPE_COUNT; i++)
    {
        if (pipes[i].active)
        {
            if (CheckCollisionRecs(player.rect, pipes[i].topRect) ||
                CheckCollisionRecs(player.rect, pipes[i].bottomRect))
            {
                gameOver = true;
                break;
            }
        }
    }
}

// Drawing function
static void DrawGame(void){

    BeginDrawing();
    ClearBackground(SKYBLUE); // Sky background

    // Draw Ground
    DrawRectangle(0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, 20, BROWN);
    DrawRectangle(0, SCREEN_HEIGHT - 30, SCREEN_WIDTH, 10, DARKBROWN);

    // Draw Pipes
    for (int i = 0; i < PIPE_COUNT; i++)
    {
        if (pipes[i].active)
        {
            // Draw top pipe
            DrawRectangleRec(pipes[i].topRect, GREEN);
            DrawRectangle(pipes[i].topRect.x - 5, pipes[i].topRect.y + pipes[i].topRect.height - 10, PIPE_WIDTH + 10, 10, DARKGREEN); // Top cap

            // Draw bottom pipe
            DrawRectangleRec(pipes[i].bottomRect, GREEN);
            DrawRectangle(pipes[i].bottomRect.x - 5, pipes[i].bottomRect.y, PIPE_WIDTH + 10, 10, DARKGREEN); // Bottom cap
        }
    }

    Rectangle source = { 0.0f, 0.0f, (float)player.text.width, (float)player.text.height };
    Rectangle dest = player.rect; // This scales the photo to your player size
    Vector2 origin = { 0, 0 };

    DrawTexturePro(player.text, source, dest, origin, 0.0f, WHITE);

    // Draw Score
    DrawText(TextFormat("SCORE: %i", score), 10, 10, 30, WHITE);

    // Draw Game Over Screen
    if (gameOver)
    {  
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.8f));
        DrawText("GAME OVER", SCREEN_WIDTH / 2 - MeasureText("GAME OVER", 60) / 2, SCREEN_HEIGHT / 2 - 60, 60, RED);
      
        DrawText("Press SPACE or Click to Restart", SCREEN_WIDTH / 2 - MeasureText("Press SPACE or Click to Restart", 30) / 2, SCREEN_HEIGHT / 2 + 20, 30, WHITE);
    }

    EndDrawing();
  
}

// Unload resources (only needed if textures/audio were used)
static void UnloadGame(void)
{
    UnloadTexture(player.text);
    UnloadMusicStream(bgMusic);
    UnloadSound(gameOverSound);
    // No resources to unload in this version
}