/*---------------------------------------------------------------------------*\
                          ____  _ _ __ _ __  ___ _ _
                         |_ / || | '_ \ '_ \/ -_) '_|
                         /__|\_, | .__/ .__/\___|_|
                             |__/|_|  |_|
\*---------------------------------------------------------------------------*/
#ifndef ZYPPER_MARKAUTO_H
#define ZYPPER_MARKAUTO_H

#include <string>
class Zypper;

/*
 markauto ...
*/

/** markauto specific options */
struct MarkautoOptions : public Options
{
  MarkautoOptions( bool unmarkMode_r = false ) : Options( ZypperCommand::MARKAUTO )
  , _unmark( unmarkMode_r )
  {}

  int _dryrun = false;		//< Dryrun mode.
  bool _unmark = false;		//< Unmarkauto mode.
};

/** Execute markauto.
 */
int markauto( Zypper & zypper_r );

#endif // ZYPPER_MARKAUTO_H
