/*---------------------------------------------------------------------------*\
                          ____  _ _ __ _ __  ___ _ _
                         |_ / || | '_ \ '_ \/ -_) '_|
                         /__|\_, | .__/ .__/\___|_|
                             |__/|_|  |_|
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <zypp/base/LogTools.h>

#include "Zypper.h"
#include "markauto.h"

///////////////////////////////////////////////////////////////////
// MarkautoOptions
///////////////////////////////////////////////////////////////////

inline std::ostream & operator<<( std::ostream & str, const MarkautoOptions & obj )
{ return str << "MarkautoOptions"; }

///////////////////////////////////////////////////////////////////
namespace
{
  ///////////////////////////////////////////////////////////////////
  /// \class MarkautoImpl
  /// \brief Implementation of markauto
  ///////////////////////////////////////////////////////////////////
  class MarkautoImpl : public CommandBase<MarkautoImpl,MarkautoOptions>
  {
    typedef CommandBase<MarkautoImpl,MarkautoOptions> CommandBase;
  public:
    MarkautoImpl( Zypper & zypper_r ) : CommandBase( zypper_r ) {}
    // CommandBase::_zypper
    // CommandBase::options;	// access/manip command options
    // CommandBase::run;	// action + catch and repost Out::Error
    // CommandBase::execute;	// run + final "Done"/"Finished with error" message
    // CommandBase::showHelp;	// Show user help on command
  public:
    /** default action */
    void action();
  };
  ///////////////////////////////////////////////////////////////////

  void MarkautoImpl::action()
  {
    OSD << (options()._unmark ? "unmarkauto" : "markauto") << " " << options()._dryrun << endl;

    // init_target( *this );
    // if ( exitCode() != ZYPPER_EXIT_OK )
    //   return;
    // load_resolvables( *this );
    //
    // SEC << sat::Pool::instance() << endl;
    //
    // sat::StringQueue ai( sat::Pool::instance().autoInstalled() );
    // IdString s( "AAAAAAAA" );
    // if ( ai.contains( s.id() ) )
    //   ai.remove( s.id() );
    // else
    //   ai.push_back( s.id() );
    // sat::Pool::instance().setAutoInstalled( ai );
    // God->target()->updateAutoInstalled();
    // break;

    if ( true )
      throw( Out::Error( ZYPPER_EXIT_ERR_ZYPP, "error", "detail" ) );
    else
      _zypper.setExitCode( ZYPPER_EXIT_ERR_ZYPP );
  }
} // namespace
///////////////////////////////////////////////////////////////////

int markauto( Zypper & zypper_r )
{
  return MarkautoImpl( zypper_r ).execute();
}
