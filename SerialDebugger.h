/********************************************************************************
 * FileName:     SerialDebugger.h
 * Dependencies: Arduino Stream Class
 * Framework:    Arduino
 * Platform:      
 * License:      Released under the MIT License (MIT)
 * Copyright:    Copyright © 2021 Umesh Walkar
 *
 ********************************************************************************
 * File Description:
 *
 * This is an Arduino Stream class that can be use to dump incomming and outgoing 
 * data to another Serial Stream for debugging purpose.
 * The debugging can be enabled or disabled in runtime.
 *
 * Change History:
 *  Rev     Date         Author          Description
 *  1.0.0   31/07/2021   Umesh Walkar    Intitial Revision
 *******************************************************************************/
#ifndef SerialDebugger_h
#define SerialDebugger_h

class SerialDebugger
    : public Stream
{
public:
  SerialDebugger(Stream &data, Stream &dump)
      : _data(data), _dump(dump)
  {
  }

  virtual size_t write(uint8_t ch)
  {
    if (_enabled)
      _dump.write(ch);
    return _data.write(ch);
  }
  virtual int read()
  {
    int ch = _data.read();
    if (_enabled)
    {
      if (ch != -1)
      {
        _dump.write(ch);
      }
    }
    return ch;
  }
  virtual int available() { return _data.available(); }
  virtual int peek() { return _data.peek(); }
  virtual void flush() { _data.flush(); }

  void enable(bool flag)
  {
    _enabled = flag;
  }

private:
  Stream &_data;
  Stream &_dump;
  bool _enabled = true;
};

#endif
