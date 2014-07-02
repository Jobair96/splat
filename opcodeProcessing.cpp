#include <iostream>
#include <sstream>
#include <stack>
#include "opcodeProcessing.h"
#include <cassert>

// @param (short) opcode: the current opcode being processed
// @param (int *) RAM: a pointer to the RAM
// @param (short) PC: a reference to the current value of PC
// @param (stack<short>) theStack: a reference to a stack of the previous
//        values of PC; this is necessary for returning from a subroutine
void determineInstruction(CHIP8state & currState)
{
   short opcode = (currState.RAM[currState.PC] << 8) | currState.RAM[currState.PC + 1];
   switch (opcode & 0xF000)
   {
      case 0x0000:
         if ((opcode & 0xFFF0) == 0x00E0)
         {
             // clear screen
         }
         else if ((opcode & 0xFFFF) == 0x00EE)
         {
             // return from subroutine -- we'll need to keep track of the value
             // of PC before jumping to a subroutine
         }
         else
         {
             // invalid opcode
         }
      break;
      case 0x1000:
         currState.PC = opcode - 0x1000;
         return;
      break;
      case 0x2000:
         currState.theStack.push(currState.PC);
         currState.PC = opcode - 0x1000;
      break;
      case 0x3000:
         // skip next instruction if Vx equals a constant
         // if Vx == kk, PC += 4
         // else, PC += 2
      break;
      case 0x4000:
         // skip next instruction if Vx doesn't equal a constant
         // if Vx != kk, PC += 4
         // else, PC += 2
      break;
      case 0x5000:
         // skip next instruction if two registers are equal
         // if Vx == Vy, PC += 4
         // else, PC == 2
      break;
      case 0x6000:
         // set Vx to a constant
         // Vx = kk
      break;
      case 0x7000:
         // add a constant to Vx, and store in Vx
         // Vx += kk
      break;
      case 0x8000:
         // requires more processing - maybe have another function to do this?
         process0x8000Codes(currState, opcode);
      break;
      case 0x9000:
         // skip next instruction if two registers are not equal
         // if Vx != Vy, PC += 4
         // else, PC += 2
      break;
      case 0xA000:
         // set I register to a constant
         // I = opcode & 0x0FFF;
      break;
      case 0xB000:
         // jump to location nnn + V0
         // PC = (opcode & 0x0FFF) + V0;
      break;
      case 0xC000:
         // set Vx to random byte & kk
         // use math class random function
      break;
      case 0xD000:
         // display sprite on screen
      break;
      case 0xE000:
         // skip next instruction if a specific key is pressed or not.
         // The key corresponds to the value of Vx.
         // Let's have another thread to check key presses, and
         // store a bool array, saying which key is being pressed
         // current. This will obviously need to be updated
         // frequently!
      break;
      case 0xF000:
         // requires more processing - maybe have another function to do this?
         process0xF000Codes(currState, opcode);
      break;
      default:
         // unknown opcode - do we assert(0) or do we keep going?
      break;
   }
}

void process0x8000Codes(CHIP8state & currState, short opcode)
{
   assert((opcode & 0xF000) == 0x8000);
   
   
}

void process0xF000Codes(CHIP8state & currState, short opcode)
{
   assert((opcode & 0xF000) == 0xF000);
   
   
}