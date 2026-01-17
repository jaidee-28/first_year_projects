#include "raylib.h"
struct animdata
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float upt;
    float runningt;
};
bool isong(animdata data,int hight)
{
    return data.pos.y>=hight-data.rec.height;
}

animdata updateani(animdata data, float deltatime,int maxf)
{
    data.runningt+=deltatime;
    if(data.runningt>=data.upt)
    {
        data.runningt=0;
        data.rec.x=data.frame*data.rec.width;
        data.frame++;
        if(data.frame>maxf)
        {
            data.frame = 0;
        }
    }
    return data;
}
int main()
{
    int width{768};
    int hight{380};
    int gravaity{1'000};

    bool isinair{};
    int velocity{0};
    int jumpvelocity{-600};

    InitWindow(width, hight, "dasher ");
    InitAudioDevice();
    Music backgroundm =LoadMusicStream("super_mario.mp3");
    PlayMusicStream(backgroundm);
    SetMusicVolume(backgroundm,2.0);
    Sound jump =LoadSound("jump-15984.mp3");
Music gameover = LoadMusicStream("jems1.mp3");
SetMusicVolume(gameover,2.0);
PlayMusicStream(gameover);
Music win= LoadMusicStream("win.mp3");
SetMusicVolume(win,2.0);
PlayMusicStream(win);
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    animdata scarfydata;
    scarfydata.rec.width = scarfy.width / 6;
    scarfydata.rec.height = scarfy.height;
    scarfydata.rec.x = 0;
    scarfydata.rec.y = 0;
    scarfydata.pos.x = width / 2 - scarfydata.rec.width / 2;
    scarfydata.pos.y = hight - scarfydata.rec.height;
    scarfydata.frame = 0;
    scarfydata.upt = 1.0 / 12;
    scarfydata.runningt = 0;

    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
int sizeofnebula{10  };

animdata ned[sizeofnebula];
for(int i=0;i<sizeofnebula;i++)
{
   ned[i].rec.x=0.0;
   ned[i].rec.y=0.0;
   ned[i].rec.width=nebula.width/8;
   ned[i].rec.height=nebula.height/8;
   ned[i].pos.y=hight-nebula.height/8;
   ned[i].frame=0;
   ned[i].runningt=0;
   ned[i].upt=0.0;
   ned[i].pos.x=width+300*i;

}
float finsh{ned[sizeofnebula-1].pos.x};

    int nebvel{-200};
    Texture2D backgr= LoadTexture("textures/far-buildings.png");
   float bgx{};
   Texture2D midgr =LoadTexture("textures/back-buildings.png");
   float mgx{};
   Texture2D foreg =LoadTexture("textures/foreground.png");
   float fgx{};
     bool collision{};
     bool newCollision = false;
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
UpdateMusicStream(backgroundm);
        const float dt{GetFrameTime()};
        BeginDrawing();
          ClearBackground(WHITE);
          bgx-=20*dt;
          if(bgx<=-backgr.width*2)
          {
            bgx=0;
          }
          mgx-=40*dt;
          if(mgx<=-midgr.width*2)
          {
            mgx=0;
          }
          fgx-=80*dt;
          if(fgx<=-foreg.width*2)
          {
            fgx=0;
          }
          
          Vector2 bg1pos{bgx,0.0};
          DrawTextureEx(backgr,bg1pos,0.0,2.0,WHITE);
          Vector2 bg2pos{bgx+backgr.width*2,0};
          DrawTextureEx(backgr,bg2pos,0,2,WHITE);
          Vector2 mg1pos{mgx,0};
           DrawTextureEx(midgr,mg1pos,0,2,WHITE);
          Vector2 mg2pos{mgx+midgr.width*2,0};
         
          DrawTextureEx(midgr,mg2pos,0,2,WHITE);
          Vector2 fg1pos{fgx,0};
          DrawTextureEx(foreg,fg1pos,0,2,WHITE);
          Vector2 fg2pos{fgx+foreg.width*2,0};
          
          DrawTextureEx(foreg,fg2pos,0,2,WHITE);


      if(!isinair)
      {
        scarfydata=updateani(scarfydata,dt,5);
      }
        for(int i=0;i<sizeofnebula;i++)
        {
        ned[i]=updateani(ned[i],dt,7);
    }
      
        if (isong(scarfydata,hight))
        {
            velocity = 0;
            isinair = false;
        }
        else
        {
            velocity += gravaity * dt;
            isinair = true;
        }
        if (IsKeyPressed(KEY_SPACE) && !isinair)
        {
            velocity += jumpvelocity;
            PlaySound(jump);
        }
        scarfydata.pos.y += velocity * dt;
      
        for(animdata nebula : ned)
         { float pad{20};
            Rectangle nebrec{
                nebula.pos.x+pad,
                nebula.pos.y+pad,
                nebula.rec.width-2*pad,
                nebula.rec.height-2*pad
            };
            Rectangle scarfyrec{
                scarfydata.pos.x+pad,
                scarfydata.pos.y+pad,
                scarfydata.rec.width-2*pad,
                scarfydata.rec.height-2*pad
            };
             if(CheckCollisionRecs(nebrec, scarfyrec ))
         {
            collision=true;
            newCollision=true;
         }
         }
         for(int i=0;i<sizeofnebula;i++)
         {
            ned[i].pos.x += nebvel * dt;
         }
         if(newCollision)
         {
             
           StopMusicStream(backgroundm);

         }
         if(collision)
         {
           DrawText("Game over",width/4,hight/2,40,RED); 
           UpdateMusicStream(gameover);
          
          
         }

         else if(scarfydata.pos.x>=finsh)
         {
            DrawText("You win",width/4,hight/2,40,RED); 
            StopMusicStream(backgroundm);
            UpdateMusicStream(win);
            StopMusicStream(gameover);
           
         }
         else{
            for(int i=0;i<sizeofnebula;i++)
        {
        
         DrawTextureRec(nebula, ned[i].rec, ned[i].pos, WHITE);
        }
 finsh +=nebvel*dt;
        DrawTextureRec(scarfy, scarfydata.rec, scarfydata.pos, WHITE);


         }

        
        EndDrawing();
       
    }
    UnloadTexture(nebula);
    UnloadTexture(scarfy);
    UnloadTexture(backgr);
    UnloadMusicStream(win);
    UnloadTexture(midgr);
  UnloadMusicStream(gameover);
    UnloadSound(jump);
    UnloadTexture(foreg);
    UnloadMusicStream(backgroundm);
    CloseAudioDevice();
    CloseWindow();
}