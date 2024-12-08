#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


void printCube(unordered_map<char, vector<vector<char>>> &cube) {
  for (auto row : cube['U']) {
    cout << "      \t";
    for (auto block : row) {
        cout << block << " ";      
    }
    cout << endl;
  }
  cout << endl;

  vector<char> sides = {'L', 'F', 'R', 'B'};

  for (int i = 0; i < 3; i++) {
    for (auto side : sides) {
      for (auto block : cube[side][i]) {
        cout << block << " ";
      }
      cout << '\t';
    }
    cout << endl;
  }
  cout << endl;

  for (auto row : cube['D']) {
    cout << "      \t";
    for (auto block : row) {
      cout << block << " ";      
    }
    cout << endl;
  }
  cout << endl;
}


void rotate_face(vector<vector<char>> &face) {
  vector<vector<char>> temp = face;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face[j][2 - i] = temp[i][j];
    }
  }
}

void rotate_face_prim(vector<vector<char>> &face) {
  vector<vector<char>> temp = face;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      face[2 - j][i] = temp[i][j];
    }
  }
}


void move_R(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][i][2];
    cube['U'][i][2] = cube['F'][i][2];
    cube['F'][i][2] = cube['D'][i][2];
    cube['D'][i][2] = cube['B'][2 - i][0];
    cube['B'][2 - i][0] = temp;
  }
  rotate_face(cube['R']);
}

void move_R_prim(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][i][2];
    cube['U'][i][2] = cube['B'][2 - i][0];
    cube['B'][2 - i][0] = cube['D'][i][2];
    cube['D'][i][2] = cube['F'][i][2];
    cube['F'][i][2] = temp;
  }
  rotate_face_prim(cube['R']);
}


void move_L(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][i][0];
    cube['U'][i][0] = cube['B'][2 - i][2];
    cube['B'][2 - i][2] = cube['D'][i][0];
    cube['D'][i][0] = cube['F'][i][0];
    cube['F'][i][0] = temp;
  }
  rotate_face(cube['L']);
}

void move_L_prim(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][i][0];
    cube['U'][i][0] = cube['F'][i][0];
    cube['F'][i][0] = cube['D'][i][0];
    cube['D'][i][0] = cube['B'][2 - i][2];
    cube['B'][2 - i][2] = temp;
  }
  rotate_face_prim(cube['L']);
}


void move_F(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][2][i];
    cube['U'][2][i] = cube['L'][2 - i][2];
    cube['L'][2 - i][2] = cube['D'][0][2 - i];
    cube['D'][0][2 - i] = cube['R'][i][0];
    cube['R'][i][0] = temp;
  }
  rotate_face(cube['F']);
}

void move_F_prim(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][2][i];
    cube['U'][2][i] = cube['R'][i][0];
    cube['R'][i][0] = cube['D'][0][2 - i];
    cube['D'][0][2 - i] = cube['L'][2 - i][2];
    cube['L'][2 - i][2] = temp;
  }
  rotate_face_prim(cube['F']);
}


void move_B(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][0][i];
    cube['U'][0][i] = cube['R'][i][2];
    cube['R'][i][2] = cube['D'][2][2 - i];
    cube['D'][2][2 - i] = cube['L'][2 - i][0];
    cube['L'][2 - i][0] = temp;
  }
  rotate_face(cube['B']);
}

void move_B_prim(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['U'][0][i];
    cube['U'][0][i] = cube['L'][2 - i][0];
    cube['L'][2 - i][0] = cube['D'][2][2 - i];
    cube['D'][2][2 - i] = cube['R'][i][2];
    cube['R'][i][2] = temp;
  }
  rotate_face_prim(cube['B']);
}


void move_U(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['F'][0][i];
    cube['F'][0][i] = cube['R'][0][i];
    cube['R'][0][i] = cube['B'][0][i];
    cube['B'][0][i] = cube['L'][0][i];
    cube['L'][0][i] = temp;
  }
  rotate_face(cube['U']);
}

void move_U_prim(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['F'][0][i];
    cube['F'][0][i] = cube['L'][0][i];
    cube['L'][0][i] = cube['B'][0][i];
    cube['B'][0][i] = cube['R'][0][i];
    cube['R'][0][i] = temp;
  }
  rotate_face_prim(cube['U']);
}


void move_D(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['F'][2][i];
    cube['F'][2][i] = cube['L'][2][i];
    cube['L'][2][i] = cube['B'][2][i];
    cube['B'][2][i] = cube['R'][2][i];
    cube['R'][2][i] = temp;
  }
  rotate_face(cube['D']);
}

void move_D_prim(unordered_map<char, vector<vector<char>>> &cube) {
  for (int i = 0; i < 3; i++) {
    char temp = cube['F'][2][i];
    cube['F'][2][i] = cube['R'][2][i];
    cube['R'][2][i] = cube['B'][2][i];
    cube['B'][2][i] = cube['L'][2][i];
    cube['L'][2][i] = temp;
  }
  rotate_face_prim(cube['D']);
}


void solveWhiteGreenEdge(unordered_map<char, vector<vector<char>>> &cube, char secondEdge) {
  // FIND WhiteGreenEdge
  // cout << "White edge on " << << << " edge on " << << endl;
  // White on down layer facing down
  if (cube['F'][2][1] == secondEdge && cube['D'][0][1] == 'W') {
    cout << "White edge on " << "D" << secondEdge << " edge on " << "F" << endl;

  } else if (cube['R'][2][1] == secondEdge && cube['D'][1][2] == 'W') {
    cout << "White edge on " << "D" << secondEdge << " edge on " << "R" << endl;

  } else if (cube['B'][2][1] == secondEdge && cube['D'][2][1] == 'W') {
    cout << "White edge on " << "D" << secondEdge << " edge on " << "B" << endl;

  } else if (cube['L'][2][1] == secondEdge && cube['D'][1][0] == 'W') {
    cout << "White edge on " << "D" << secondEdge << " edge on " << "L" << endl;
  }
  // White on down layer facing side
    else if (cube['F'][2][1] == 'W' && cube['D'][0][1] == secondEdge) {
    cout << "White edge on " << "F" << secondEdge << " edge on " << "D" << endl;

  } else if (cube['R'][2][1] == 'W' && cube['D'][1][2] == secondEdge) {
    cout << "White edge on " << "R" << secondEdge << " edge on " << "D" << endl;

  } else if (cube['B'][2][1] == 'W' && cube['D'][2][1] == secondEdge) {
    cout << "White edge on " << "B" << secondEdge << " edge on " << "D" << endl;

  } else if (cube['L'][2][1] == 'W' && cube['D'][1][0] == secondEdge) {
    cout << "White edge on " << "L" << secondEdge << " edge on " << "D" << endl;
  }
  // White on middle layer
    else if (cube['F'][1][2] == 'W' && cube['R'][1][0] == secondEdge) {
    cout << "White edge on " << "F" << secondEdge << " edge on " << "R" << endl;

  } else if (cube['F'][1][2] == secondEdge && cube['R'][1][0] == 'W') {
    cout << "White edge on " << "R" << secondEdge << " edge on " << "F" << endl;

  } else if (cube['R'][1][2] == 'W' && cube['B'][1][0] == secondEdge) {
    cout << "White edge on " << "R" << secondEdge << " edge on " << "B" << endl;

  } else if (cube['R'][1][2] == secondEdge && cube['B'][1][0] == 'W') {
    cout << "White edge on " << "B" << secondEdge << " edge on " << "R" << endl;

  } else if (cube['B'][1][2] == 'W' && cube['L'][1][0] == secondEdge) {
    cout << "White edge on " << "B" << secondEdge << " edge on " << "L" << endl;

  } else if (cube['B'][1][2] == secondEdge && cube['L'][1][0] == 'W') {
    cout << "White edge on " << "L" << secondEdge << " edge on " << "B" << endl;

  } else if (cube['L'][1][2] == 'W' && cube['F'][1][0] == secondEdge) {
    cout << "White edge on " << "L" << secondEdge << " edge on " << "F" << endl;
    
  } else if (cube['L'][1][2] == secondEdge && cube['F'][1][0] == 'W') {
    cout << "White edge on " << "F" << secondEdge << " edge on " << "L" << endl;
    
  }
  // White on up layer facing side
    else if (cube['F'][0][1] == 'W' && cube['U'][2][1] == secondEdge) {
    cout << "White edge on " << "F" << secondEdge << " edge on " << "U" << endl;
     
  } else if (cube['R'][0][1] == 'W' && cube['U'][1][2] == secondEdge) {
    cout << "White edge on " << "R" << secondEdge << " edge on " << "U" << endl;
 
  } else if (cube['B'][0][1] == 'W' && cube['U'][0][1] == secondEdge) {
    cout << "White edge on " << "B" << secondEdge << " edge on " << "U" << endl;
 
  } else if (cube['L'][0][1] == 'W' && cube['U'][1][0] == secondEdge) {
    cout << "White edge on " << "L" << secondEdge << " edge on " << "U" << endl;
 
  } 
  // White on up layer facing up
    else if (cube['F'][0][1] == secondEdge && cube['U'][2][1] == 'W') {
    cout << "White edge on " << "U" << secondEdge << " edge on " << "F" << endl;
     
  } else if (cube['R'][0][1] == secondEdge && cube['U'][1][2] == 'W') {
    cout << "White edge on " << "U" << secondEdge << " edge on " << "R" << endl;
 
  } else if (cube['B'][0][1] == secondEdge && cube['U'][0][1] == 'W') {
    cout << "White edge on " << "U" << secondEdge << " edge on " << "B" << endl;
 
  } else if (cube['L'][0][1] == secondEdge && cube['U'][1][0] == 'W') {
    cout << "White edge on " << "U" << secondEdge << " edge on " << "L" << endl;
 
  }
}

void solveCross(unordered_map<char, vector<vector<char>>> &cube) {
  solveWhiteGreenEdge(cube, 'G');
}


int main() {

  unordered_map<char, vector<vector<char>>> cube = {
    {'U', {{'Y', 'Y', 'Y'}, 
           {'Y', 'Y', 'Y'}, 
           {'Y', 'Y', 'Y'}}},

    {'L', {{'R', 'R', 'R'}, 
           {'R', 'R', 'R'}, 
           {'R', 'R', 'R'}}},

    {'F', {{'G', 'G', 'G'}, 
           {'G', 'G', 'G'}, 
           {'G', 'G', 'G'}}},

    {'R', {{'O', 'O', 'O'}, 
           {'O', 'O', 'O'}, 
           {'O', 'O', 'O'}}},

    {'B', {{'B', 'B', 'B'}, 
           {'B', 'B', 'B'}, 
           {'B', 'B', 'B'}}},

    {'D', {{'W', 'W', 'W'}, 
           {'W', 'W', 'W'}, 
           {'W', 'W', 'W'}}}
  };
    


  // Around front
  printCube(cube);

  move_F(cube);
  solveCross(cube);

  move_F(cube);
  solveCross(cube);

  move_F(cube);
  solveCross(cube);

  move_F(cube);
  solveCross(cube);

  // Around right
  move_D(cube);
  printCube(cube);

  move_R(cube);
  solveCross(cube);

  move_R(cube);
  solveCross(cube);

  move_R(cube);
  solveCross(cube);

  move_R(cube);
  solveCross(cube);

  // Around back
  move_D(cube);
  printCube(cube);

  move_B(cube);
  solveCross(cube);

  move_B(cube);
  solveCross(cube);

  move_B(cube);
  solveCross(cube);

  move_B(cube);
  solveCross(cube);

  // Around left
  move_D(cube);
  printCube(cube);

  move_L(cube);
  solveCross(cube);

  move_L(cube);
  solveCross(cube);

  move_L(cube);
  solveCross(cube);

  move_L(cube);
  solveCross(cube);

  // Around up
  move_L_prim(cube);
  move_F(cube);
  printCube(cube);

  solveCross(cube);
  move_U(cube);

  solveCross(cube);
  move_U(cube);

  solveCross(cube);
  move_U(cube);

  solveCross(cube);
  move_U(cube);

  // Around down
  move_F(cube);
  move_F(cube);
  printCube(cube);

  solveCross(cube);
  move_D(cube);

  solveCross(cube);
  move_D(cube);

  solveCross(cube);
  move_D(cube);

  solveCross(cube);
  move_D(cube);

  return 0;
}