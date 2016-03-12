/* dgtnix, a test program for the dgtnix driver
Copyright (C) 2006 Pierre Boulenguez

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <config.h>

using namespace std;
#include <iostream>
#include <errno.h>
#include <dgtnix.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int mode = 0;
  cout << "dgtnixTest is a test Program for the dgtnix library."<<endl;
  cout << "This is dgtnix version "<<  dgtnixQueryString(DGTNIX_DRIVER_VERSION)<< endl; 
  int i = 0;
  int result;
  int optionError=0;
  char port[256];
  if(argc!=2)
    optionError=1;
  if(optionError)
    {
      cout << "usage: ./dgtnixTest port" << endl;
      cout << "Port is the port to which the board is connected." << endl;
      cout << "For usb connection, try : /dev/usb/tts/0, /dev/usb/tts/1, /dev/usb/tts/2 ..." << endl;
      cout << "For serial, try : /dev/ttyS0, /dev/ttyS1, /dev/ttyS2 ..." << endl;
      cout << "For the virtual board /tmp/dgtnixBoard is the default but you can change it." << endl;
      exit(1);
    }
  
  /* all debug informations are printed */
  dgtnixSetOption(DGTNIX_DEBUG, DGTNIX_DEBUG_WITH_TIME);
  /* Initialize the driver with port argv[2] */
  strncpy(port, argv[1], 256);
  result=dgtnixInit(port);
  int err = dgtnix_errno; 
  if(result < 0 )
    {
      cout << "Unable to connect to DGT board on port "  << port <<" : " ;
      switch (result)
	{
	case -1:
	  cout << strerror(err) << endl;
	  break;
	case -2:
	  cout << "Not responding to the DGT_SEND_BRD message" << endl;
	  break;
	default:
	  cout << "Unrecognized response to the DGT_SEND_BRD message :" <<  result <<endl;
	}
      exit(-1);
    }
  cout << "The board was found" << endl;
  dgtnixClose();
}
