#ifndef MECANUM_DRIVE_STM__STM_COMMS_HPP_
#define MECANUM_DRIVE_STM__STM_COMMS_HPP_



// #include <cstring>
#include <sstream>
// #include <cstdlib>
#include <libserial/SerialPort.h>
#include <iostream>
#include <chrono>



LibSerial::BaudRate convert_baud_rate(int baud_rate)
{
  // Just handle some common baud rates
  switch (baud_rate)
  {
    case 1200: return LibSerial::BaudRate::BAUD_1200;
    case 1800: return LibSerial::BaudRate::BAUD_1800;
    case 2400: return LibSerial::BaudRate::BAUD_2400;
    case 4800: return LibSerial::BaudRate::BAUD_4800;
    case 9600: return LibSerial::BaudRate::BAUD_9600;
    case 19200: return LibSerial::BaudRate::BAUD_19200;
    case 38400: return LibSerial::BaudRate::BAUD_38400;
    case 57600: return LibSerial::BaudRate::BAUD_57600;
    case 115200: return LibSerial::BaudRate::BAUD_115200;
    case 230400: return LibSerial::BaudRate::BAUD_230400;
    default:
      std::cout << "Error! Baud rate " << baud_rate << " not supported! Default to 57600" << std::endl;
      return LibSerial::BaudRate::BAUD_57600;
  }
}

class ArduinoComms
{

public:

  ArduinoComms() = default;

  void connect(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms)
  {  
    timeout_ms_ = timeout_ms;
    serial_conn_.Open(serial_device);
    serial_conn_.SetBaudRate(convert_baud_rate(baud_rate));
    serial_conn_.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
    serial_conn_.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);
    serial_conn_.SetParity(LibSerial::Parity::PARITY_NONE);
    serial_conn_.SetStopBits(LibSerial::StopBits::STOP_BITS_1);

  }

  void disconnect()
  {
    serial_conn_.Close();
  }

  bool connected() const
  {
    return serial_conn_.IsOpen();
  }


  std::string send_msg(const std::string &msg_to_send, bool print_output = false)
  {
    serial_conn_.FlushIOBuffers(); // Just in case
    serial_conn_.Write(msg_to_send);

    std::cout << "msg_to_send " << msg_to_send << std::endl;

    std::string response = "";
    // std::string test_string = "122.33 434.242 45.23 56.23";

    auto start = std::chrono::high_resolution_clock::now();

    try
    {
      // Responses end with \r\n so we will read up to (and including) the \n.
      serial_conn_.ReadLine(response);
      // serial_conn_.Read(response, test_string.size(), timeout_ms_);

    }
    catch (const LibSerial::ReadTimeout&)
    {
        std::cerr << "The ReadByte() call has timed out." << std::endl ;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    if (print_output)
    {
      std::cout << "Sent: " << msg_to_send << " Recv: " << response << std::endl;
      std::cout << "Time taken for communication: " << elapsed.count() << " seconds" << std::endl;
    }

    return response;
  }


  void send_msg_no_response(const std::string &msg_to_send, bool print_output = false)
  {
    serial_conn_.FlushIOBuffers(); // Just in case
    serial_conn_.Write(msg_to_send);

    std::cout << "msg_to_send " << msg_to_send << std::endl;

  
    std::string response = "";
    // std::string test_string = "OK";

    try
    {
      // Responses end with \r\n so we will read up to (and including) the \n.
      serial_conn_.ReadLine(response);
      // serial_conn_.Read(response, test_string.size(), timeout_ms_);


    }
    catch (const LibSerial::ReadTimeout&)
    {
        std::cerr << "The ReadByte() call has timed out." << std::endl ;
    }
    

    if (print_output)
    {
      std::cout << "Sent: " << msg_to_send << " Recv: " << response << std::endl;
    }

    if (print_output)
    {
      std::cout << "Sent: " << msg_to_send << std::endl;
    }

    return;
  }

  void send_empty_msg()
  {
    std::string response = send_msg("\r",true);
  }

  void read_encoder_values(int &val_1, int &val_2, int &val_3, int &val_4)
  {
    std::string response = send_msg("e\r",true);

    std::string delimiter = " ";

    size_t del_pos1 = response.find(delimiter);
    std::string token_1 = response.substr(0, del_pos1);

    size_t del_pos2 = response.find(delimiter, del_pos1 + delimiter.length());
    std::string token_2 = response.substr(del_pos1 + delimiter.length(), 
                                      del_pos2 - del_pos1 - delimiter.length());

    size_t del_pos3 = response.find(delimiter, del_pos2 + delimiter.length());
    std::string token_3 = response.substr(del_pos2 + delimiter.length(), 
                                        del_pos3 - del_pos2 - delimiter.length());

    std::string token_4 = response.substr(del_pos3 + delimiter.length());


    val_1 = std::atoi(token_1.c_str());
    val_2 = std::atoi(token_2.c_str());
    val_3 = std::atoi(token_3.c_str());
    val_4 = std::atoi(token_4.c_str());
  }

  void set_motor_values(double val_1, double val_2, double val_3, double val_4)
  {
    std::stringstream ss;
    ss << "m " << val_1 << " " << val_2 << " " << val_3 << " " << val_4 << "\r";
    send_msg_no_response(ss.str());
  }

  void set_pid_values(int k_p, int k_d, int k_i, int k_o)
  {
    std::stringstream ss;
    ss << "u " << k_p << ":" << k_d << ":" << k_i << ":" << k_o << "\r";
    send_msg(ss.str());
  }

private:
    LibSerial::SerialPort serial_conn_;
    int timeout_ms_;
};

#endif // MECANUM_DRIVE_STM__STM_COMMS_HPP_