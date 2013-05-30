#define LEFTSENSOR 1 // TODO: What port is this on?
#define FRONTSENSOR 2 // TODO: What port is this on?
#define RIGHTSENSOR 3 // TODO: What port is this on?
#define WALLDISTANCE 4 // TODO: How far should it be from the walls?
#define MAXVISITED 66 // 3 * 22, should be plenty. 

#define LEFT 0
#define FORWARD 1
#define RIGHT 2

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int leftmode = 1;
int cell[3] = {0,0,NORTH};
int visited[MAXVISITED] = {};
int length = 0;

void setup() {
  
}

void loop() {
  int wallleft = analogRead(LEFTSENSOR) < WALLDISTANCE;
  int wallfront = analogRead(FRONTSENSOR) < WALLDISTANCE;
  int wallright = analogRead(RIGHTSENSOR) < WALLDISTANCE;
  
  if (leftmode) {
    if (!wallleft) {
      go(LEFT);
    } else if (!wallfront) {
      go(FORWARD);
    } else if (!wallright) {
      go(RIGHT);
    } else {
      rotate(180);
      cell[2] = cell[2] + 2 % 4;
      return;
    }
  } else {
    if (!wallright) {
      go(RIGHT);
    } else if (!wallfront) {
      go(FORWARD);
    } else if (!wallleft) {
      go(LEFT);
    } else {
      rotate(180);
      cell[2] = cell[2] + 2 % 4;
      return;
    }
  }
  
  int visitd = hasVisited(cell);
  if (visitd && leftmode) {
    go(RIGHT);
    leftmode = 0;
  }
  if (!visitd && !leftmode) {
    leftmode = true;
  }
  
  if (!visitd) {
    if (length > MAXVISITED) length = 0;
    visited[length++] = cell[0];
    visited[length++] = cell[1];
    visited[length++] = cell[2];
  }
}

int hasVisited(int curCell[3]) {
  for (int i; i < MAXVISITED; i += 3) {
    if (visited[i] == cell[0] && visited[i+1] == cell[1] && visited[i+2] == cell[2]) {
      return 1;
    }
  }
  return 0;
}

void go(int dir) {
  int facing = cell[2];
  
  switch (dir) {
    case LEFT:
      facing--;
      rotate(-90);
      break;
    case FORWARD:
      break;
    case RIGHT:
      facing++;
      rotate(90);
      break;
  }
  
  facing = (4 + facing) % 4;
  forward(5);
  
  switch (facing) {
    case NORTH:
      cell[1]++;
      break;
    case EAST:
      cell[0]++;
      break;
    case SOUTH:
      cell[1]--;
      break;
    case WEST:
      cell[0]--;
      break;
  }
  
  cell[2] = facing;
}

// TODO: Load in these functions and get running on an Arduino, 
// I don't have one at home.
void rotate(int deg) {
}

void forward(int steps) {
}
