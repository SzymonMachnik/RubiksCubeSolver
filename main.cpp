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


int main() {

  unordered_map<char, vector<vector<char>>> cube = {
    {'U', {{'W', 'W', 'W'}, 
           {'W', 'W', 'W'}, 
           {'W', 'W', 'W'}}},

    {'L', {{'O', 'O', 'O'}, 
           {'O', 'O', 'O'}, 
           {'O', 'O', 'O'}}},

    {'F', {{'G', 'G', 'G'}, 
           {'G', 'G', 'G'}, 
           {'G', 'G', 'G'}}},

    {'R', {{'R', 'R', 'R'}, 
           {'R', 'R', 'R'}, 
           {'R', 'R', 'R'}}},

    {'B', {{'B', 'B', 'B'}, 
           {'B', 'B', 'B'}, 
           {'B', 'B', 'B'}}},

    {'D', {{'Y', 'Y', 'Y'}, 
           {'Y', 'Y', 'Y'}, 
           {'Y', 'Y', 'Y'}}}
  };
  
  
  move_L_prim(cube);
  move_D(cube);
  move_B_prim(cube);
  move_U(cube);
  move_U(cube);
  move_R(cube);
  move_U_prim(cube);
  move_B(cube);
  move_R_prim(cube);
  move_U(cube);
  move_U(cube);
  move_F(cube);
  move_F(cube);
  move_U(cube);
  move_U(cube);
  move_R(cube);
  move_R(cube);
  move_F(cube);
  move_F(cube);
  move_R(cube);
  move_B(cube);
  move_B(cube);
  move_R(cube);
  move_B_prim(cube);
  

  printCube(cube);

  return 0;
}