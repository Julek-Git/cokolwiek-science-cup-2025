#include "pieces/Pawn.h"

// bool Pawn::validate_move(uint8_t target_inx) 
// {
  
// }




// bool Pawn::validate_move(int _x, int _y) {
//   if (color == 0) {
//     if (y == 1) {
//       if (_y == y + 1 || _y == y + 2) {
//         return true;
//       }
//     } else {
//       if (_y == y + 1) {
//         return true;
//       }
//     }
//   } else {
//     if (y == 6) {
//       if (_y == y - 1 || _y == y - 2) {
//         return true;
//       }
//     } else {
//       if (_y == y - 1) {
//         return true;
//       }
//     }
//   }
//   return false;
// }

// bool Pawn::move(int _x, int _y) {
//   if (validate_move(_x, _y)) {
//     x = _x;
//     y = _y;
//     return true;
//   }
//   return false;
// }

// bool Pawn::validate_take(int _x, int _y) {
//   if (color == 0) {
//     if (_y == y + 1 && (_x == x + 1 || _x == x - 1)) {
//       return true;
//     }
//   } else {
//     if (_y == y - 1 && (_x == x + 1 || _x == x - 1)) {
//       return true;
//     }
//   }
//   return false;
// }

// bool Pawn::take(int _x, int _y) {
//   if (validate_take(_x, _y)) {
//     x = _x;
//     y = _y;
//     return true;
//   }
//   return false;
// }