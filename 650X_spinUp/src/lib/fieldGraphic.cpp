/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       fieldGraphic.cpp                                          */
/*    Author:       LoJac10                                                   */
/*    Created:      Oct 30th, 2022                                            */
/*    Description:  Draw VRC Field and label red and blue alliance positions  */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

vex::color gray = vex::color(168,168,168);

void fieldGraphic(){
  
  /////////////////////////////////////
  //
  // Utilities
  //
  //////////////////////////////////////////////////////////
  
  // Clear the screen 
  Brain.Screen.clearScreen( vex::color::white );
  // Set pen color and Size for grid outline 
  Brain.Screen.setPenColor(black);
  Brain.Screen.setPenWidth(1);

  /////////////////////////////////////
  //
  // Draw columns
  //
  //////////////////////////////////////////////////////////
  
  // Column 1:6 
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(10, 45, 35, 35);
  Brain.Screen.setFillColor(gray);
  Brain.Screen.drawRectangle(10, 10, 35, 35);
  Brain.Screen.drawRectangle(10, 80, 35, 35);
  Brain.Screen.drawRectangle(10, 115, 35, 35);
  Brain.Screen.drawRectangle(10, 150, 35, 35);
  Brain.Screen.drawRectangle(10, 185, 35, 35);

  // Column 2:6
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(45, 10, 35, 35);
  Brain.Screen.setFillColor(gray);
  Brain.Screen.drawRectangle(45, 45, 35, 35);
  Brain.Screen.drawRectangle(45, 80, 35, 35);
  Brain.Screen.drawRectangle(45, 115, 35, 35);
  Brain.Screen.drawRectangle(45, 150, 35, 35);
  Brain.Screen.drawRectangle(45, 185, 35, 35);

  // Column 3:6
  Brain.Screen.setFillColor(gray);
  Brain.Screen.drawRectangle(80, 10, 35, 35);
  Brain.Screen.drawRectangle(80, 45, 35, 35);
  Brain.Screen.drawRectangle(80, 80, 35, 35);
  Brain.Screen.drawRectangle(80, 115, 35, 35);
  Brain.Screen.drawRectangle(80, 150, 35, 35);
  Brain.Screen.drawRectangle(80, 185, 35, 35);

  // Column 4:6
  Brain.Screen.setFillColor(gray);
  Brain.Screen.drawRectangle(115, 10, 35, 35);
  Brain.Screen.drawRectangle(115, 45, 35, 35);
  Brain.Screen.drawRectangle(115, 80, 35, 35);
  Brain.Screen.drawRectangle(115, 115, 35, 35);
  Brain.Screen.drawRectangle(115, 150, 35, 35);
  Brain.Screen.drawRectangle(115, 185, 35, 35);
  
  // Column 5:6
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(150, 10, 35, 35);
  Brain.Screen.setFillColor(gray);
  Brain.Screen.drawRectangle(150, 45, 35, 35);
  Brain.Screen.drawRectangle(150, 80, 35, 35);
  Brain.Screen.drawRectangle(150, 115, 35, 35);
  Brain.Screen.drawRectangle(150, 150, 35, 35);
  Brain.Screen.drawRectangle(150, 185, 35, 35);

  // Column 6:6
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(185, 45, 35, 35); 
  Brain.Screen.setFillColor(gray);
  Brain.Screen.drawRectangle(185, 10, 35, 35); 
  Brain.Screen.drawRectangle(185, 80, 35, 35);
  Brain.Screen.drawRectangle(185, 115, 35, 35);
  Brain.Screen.drawRectangle(185, 150, 35, 35);
  Brain.Screen.drawRectangle(185, 185, 35, 35);

  //////////////////////////////////////////
  //
  // Draw colored field tiles and field lines
  //
  //////////////////////////////////////////////////////////
  
  // Draw protected zones and autonomous lines in middle of field
  Brain.Screen.setPenColor( vex::color::white );
  Brain.Screen.setPenWidth(4);

  // Red inner protected zone white line
  Brain.Screen.drawLine(11, 45, 45, 45);
  Brain.Screen.drawLine(45, 45, 45, 11);

  // Red outter protected zone white line
  Brain.Screen.drawLine(11, 80, 45, 80);
  Brain.Screen.drawLine(45, 80, 80, 45);
  Brain.Screen.drawLine(80, 45, 80, 11);;

  // Blue innter protected zone white line
  Brain.Screen.drawLine(185, 11, 185, 45);
  Brain.Screen.drawLine(185, 45, 218, 45);

  // Blue outter protected zone white line
  Brain.Screen.drawLine(150, 11, 150, 45);
  Brain.Screen.drawLine(150, 45, 185, 80);
  Brain.Screen.drawLine(185, 80, 220, 80);

  // Autonomous white lines down center of ring
  Brain.Screen.drawLine(110, 11, 110, 218); // red side
  Brain.Screen.drawLine(115, 11, 115, 218); // blue side)

  ///////////////////////////////////////////////////
  //
  //  Label autonomous starting reference positions
  //
  /////////////////////////////////////////////////////////////////

  // BR start pos 
  Brain.Screen.setFont( prop20 );
  Brain.Screen.setCursor( 6 , 21 );
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setFont(monoM);
  Brain.Screen.print("BR");
  
  // BL start pos 
  Brain.Screen.setFont( prop20 );
  Brain.Screen.setCursor( 8 , 21 );
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setFont(monoM);
  Brain.Screen.print("BL");

  // RL start pos 
  Brain.Screen.setFont( prop20 );
  Brain.Screen.setCursor( 6 , 2 );
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setFont(monoM);
  Brain.Screen.print("RL");

  // RR start pos 
  Brain.Screen.setFont( prop20 );
  Brain.Screen.setCursor( 8 , 2 );
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setFont(monoM);
  Brain.Screen.print("RR");
}