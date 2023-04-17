/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       auton.h                                                   */
/*    Author:       LoJac10                                                   */
/*    Created:      Nov 17th, 2022                                            */
/*    Description:  auton program select module and auton program             */
/*                  header file                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

  // module: autonSelect.h
  // author: jpearman's autonSelect.h
  typedef struct _button button;
  void displayButtonControls( int index, bool pressed );
  int findButton(  int16_t xpos, int16_t ypos );
  void initButtons();
  void userTouchCallbackPressed();
  void displayButtonControls( int index, bool pressed );

  // module: auton programs
  void Auton_RF1();
  void Auton_RF2();
  void Auton_RN1();
  void Auton_RN2();
  void Auton_BF1();
  void Auton_BF2();
  void Auton_BN1();
  void Auton_BN2();